/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:01:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/26 17:54:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	mandelbrot(t_fract *var, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	tmp;
	int			i;

	c[0] = x / var->param->zoom_x + var->param->x1;
	c[1] = y / var->param->zoom_y + var->param->y1;
	z[0] = 0;
	z[1] = 0;
	i = -1;
	while (z[0] * z[0] + z[1] * z[1] <= 4 && ++i < DRAW_PREC)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = tmp;
	}
	if (i != DRAW_PREC)
		draw_pixel(var->img, x, y, color(i, var));
	else
		draw_pixel(var->img, x, y, 0);
}
