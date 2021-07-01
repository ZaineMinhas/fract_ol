/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 17:26:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*static int	color(int i)
{
	if (i >= 0 && i <= 0.1 * DRAW_PREC)
		return (0xFFFF00);
	else if (i > 0.1 * DRAW_PREC && i <= 0.2 * DRAW_PREC)
		return (0xFFCC00);
	else if (i > 0.2 * DRAW_PREC && i <= 0.3 * DRAW_PREC)
		return (0xFF9900);
	else if (i > 0.3 * DRAW_PREC && i <= 0.4 * DRAW_PREC)
		return (0xFF6600);
	else if (i > 0.4 * DRAW_PREC && i <= 0.5 * DRAW_PREC)
		return (0xFF3300);
	else if (i > 0.5 * DRAW_PREC && i <= 0.6 * DRAW_PREC)
		return (0xFF0000);
	else if (i > 0.6 * DRAW_PREC && i <= 0.7 * DRAW_PREC)
		return (0xFF0033);
	else if (i > 0.7 * DRAW_PREC && i <= 0.8 * DRAW_PREC)
		return (0xFF0066);
	else if (i > 0.8 * DRAW_PREC && i <= 0.9 * DRAW_PREC)
		return (0xFF0099);
	else if (i > 0.9 * DRAW_PREC && i <= 0.99 * DRAW_PREC)
		return (0xFF00FF);
	return (0);
}*/

void	julia(t_fract *var)
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
			c_r = 0.285;
			c_i = 0.01;
			z_r = x / var->param->zoom_x + var->param->x1;
			z_i = y / var->param->zoom_y + var->param->y1;
			i = 0;
			while (z_r * z_r + z_i * z_i <= 4 && i < var->param->prec)
			{
				tmp = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_r * z_i + c_i;
                z_r = tmp;
				i++;
			}
			if  (i != DRAW_PREC)
				draw_pixel(var->img, x, y, i * 255 / var->param->prec);
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
