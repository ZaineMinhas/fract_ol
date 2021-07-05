/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:01:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/05 17:38:32 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	color(int i)
{
	return (65382 + i * 300000);
}

void	mandelbrot(t_fract *var)
{
	double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < var->param->screen_x)
	{
		y = -1;
		while (++y < var->param->screen_y)
		{
			c_r = x / var->param->zoom_x + var->param->x1;
			c_i = y / var->param->zoom_y + var->param->y1;
			z_r = 0;
			z_i = 0;
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
