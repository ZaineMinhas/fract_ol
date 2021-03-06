/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/27 20:15:49 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	julia(t_fract *var, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	tmp;
	int			i;

	c[0] = (long double)(4 * var->param->mouse_x) / var->param->screen_x - 2;
	c[1] = (long double)(4 * var->param->mouse_y) / var->param->screen_y - 2;
	z[0] = x / var->param->zoom_x + var->param->x1;
	z[1] = y / var->param->zoom_y + var->param->y1;
	i = -1;
	while (z[0] * z[0] + z[1] * z[1] <= 100000000 && ++i < DRAW_PREC)
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
