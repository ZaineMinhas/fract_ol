/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:01:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/22 19:31:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	color(int i)
{
	if (i >= 0 && i <= 0.1 * DRAW_PREC)
		return (255255000);
	else if (i > 0.1 * DRAW_PREC && i <= 0.2 * DRAW_PREC)
		return (106027154);
	else if (i > 0.2 * DRAW_PREC && i <= 0.3 * DRAW_PREC)
		return (255204051);
	else if (i > 0.3 * DRAW_PREC && i <= 0.4 * DRAW_PREC)
		return (255204000);
	else if (i > 0.4 * DRAW_PREC && i <= 0.5 * DRAW_PREC)
		return (255153051);
	else if (i > 0.5 * DRAW_PREC && i <= 0.6 * DRAW_PREC)
		return (255153000);
	else if (i > 0.6 * DRAW_PREC && i <= 0.7 * DRAW_PREC)
		return (255102000);
	else if (i > 0.7 * DRAW_PREC && i <= 0.8 * DRAW_PREC)
		return (255051000);
	else if (i > 0.8 * DRAW_PREC && i <= 0.9 * DRAW_PREC)
		return (255000051);
	else if (i > 0.9 * DRAW_PREC && i <= 0.99 * DRAW_PREC)
		return (255000000);
	return (0);
}

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

	img_x = (var->param->x2 - var->param->x1) * var->param->zoom;
	img_y = (var->param->y2 - var->param->y1) * var->param->zoom;
	x = -1;
	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
			c_r = x / var->param->zoom + var->param->x1;
			c_i = y / var->param->zoom + var->param->y1;
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
			/*else
				draw_pixel(var->img, x, y, i * 254 / DRAW_PREC);*/
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}