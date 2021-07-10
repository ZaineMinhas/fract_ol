/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 17:00:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static int	color(int i, t_fract *var)
{
	if (var->param->color == 0)
		return (color_ice(i));
	else if (var->param->color == 1)
		return (color_fire(i));
	else if (var->param->color == 2)
		return (color_clown(i));
	else if (var->param->color == 3)
		return (color_rave(i));
	else if (var->param->color == 4)
		return (color_psycho(i));
	else if (var->param->color == 5)
		return (65382 + i * 300000);
	else if (var->param->color == 6)
		return (16776960 + i * 30000000);
	else
	{
		printf("COLOR SET INVALID\n");
		exit(1);
	}
}

void	julia(t_fract *var)
{
	long double	c[2];
	long double	z[2];
	long double	tmp;
	int			coord[2];
	int			i;

	coord[0] = -1;
	while (++coord[0] < var->param->screen_x)
	{
		coord[1] = -1;
		while (++coord[1] < var->param->screen_y)
		{
			c[0] = 0.285;
			c[1] = 0.01;
			z[0] = coord[0] / var->param->zoom_x + var->param->x1;
			z[1] = coord[1] / var->param->zoom_y + var->param->y1;
			i = -1;
			while (z[0] * z[0] + z[1] * z[1] <= 4 && ++i < DRAW_PREC)
			{
				tmp = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[0] * z[1] + c[1];
				z[0] = tmp;
			}
			if (i != DRAW_PREC)
				draw_pixel(var->img, coord[0], coord[1], color(i, var));
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
