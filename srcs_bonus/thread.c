/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:22:52 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/26 17:27:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	*use_threads(void *v)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)v;
	y = t->var->param->screen_y / THREADS * t->id - 1;
	while (++y < t->var->param->screen_y / THREADS * (t->id + 1))
	{
		x = -1;
		while (++x < t->var->param->screen_x)
			display_fract(t->var, x, y);
	}
	return (NULL);
}

int	init_threads(t_fract *var)
{
	t_render	*r;
	int			i;

	i = -1;
	r = &var->render;
	while (++i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].var = var;
		if (pthread_create(r->threads + i, NULL, use_threads, r->args + i))
			exit(1);
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(r->threads[i], NULL))
			exit(1);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
	return (0);
}
