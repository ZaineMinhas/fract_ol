/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beryl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:00:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/12 16:30:32 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	beryl(t_fract *var, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	tmp[2];
	int			i;

	c[0] = x / var->param->zoom_x + var->param->x1;
	c[1] = y / var->param->zoom_y + var->param->y1;
	z[0] = 1;
	z[1] = 0;
	i = -1;
	while (z[0] * z[0] + z[1] * z[1] <= 4 && ++i < DRAW_PREC)
	{
		tmp[0] = c[0] * z[0] - c[1] * z[1];
		tmp[1] = c[0] * z[1] + c[1] * z[0];
		c[0] += z[0];
		c[1] += z[1];
		z[0] = tmp[0];
		z[1] = tmp[1];
	}
	if (i != DRAW_PREC)
		draw_pixel(var->img, x, y, color(i, var));
}
