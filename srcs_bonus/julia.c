/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/06 17:22:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static int	color(int i)
{
	return (16711935 + i * 2000);
}

void	julia(t_fract *var)
{
	long double  c_r;
    long double  c_i;
    long double  z_r;
    long double  z_i;
    long double  tmp;
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < var->param->screen_x)
	{
		y = -1;
		while (++y < var->param->screen_y)
		{
			c_r = 0.285;
			c_i = 0.01;
			z_r = x / var->param->zoom_x + var->param->x1;
			z_i = y / var->param->zoom_y + var->param->y1;
			i = 0;
			while (z_r * z_r + z_i * z_i <= 4 && i < DRAW_PREC)
			{
				tmp = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_r * z_i + c_i;
                z_r = tmp;
				i++;
			}
			if  (i != DRAW_PREC)
				draw_pixel(var->img, x, y, color(i));
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
