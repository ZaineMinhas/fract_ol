/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:01:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/21 18:20:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fract *var)
{
	double	img_x;
	double	img_y;
	double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;
	int		x;
	int		y;
	int		i;

	img_x = (var->math->x2 - var->math->x1) * var->math->zoom;
	img_y = (var->math->y2 - var->math->y1) * var->math->zoom;
	x = -1;
	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
			c_r = x / var->math->zoom + var->math->x1;
			c_i = y / var->math->zoom + var->math->y1;
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
				mlx_pixel_put(var->mlx_ptr, var->win_ptr, x, y, 100100100);
		}
	}
}