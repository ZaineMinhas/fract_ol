/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 17:27:50 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	color(int i)
{
	if (COLOR == 0)
		return (color_ice(i));
	else if (COLOR == 1)
		return (color_fire(i));
	else if (COLOR == 2)
		return (color_clown(i));
	else if (COLOR == 3)
		return (color_rave(i));
	else if (COLOR == 4)
		return (color_psycho(i));
	else if (COLOR == 5)
		return (65382 + i * 300000);
	else if (COLOR == 6)
		return (16776960 + i * 30000000);
	else
	{
		printf("COLOR SET INVALID\n");
		exit(1);
	}
}

static void	julia_calc(t_calc *c)
{
	c->tmp = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
	c->z_i = 2 * c->z_r * c->z_i + c->c_i;
	c->z_r = c->tmp;
}

void	julia(t_fract *var)
{
	t_calc	c;

	c.x = -1;
	while (++c.x < var->param->screen_x)
	{
		c.y = -1;
		while (++c.y < var->param->screen_y)
		{
			c.c_r = 0.285;
			c.c_i = 0.01;
			c.z_r = c.x / var->param->zoom_x + var->param->x1;
			c.z_i = c.y / var->param->zoom_y + var->param->y1;
			c.i = -1;
			while (c.z_r * c.z_r + c.z_i * c.z_i <= 4 && ++c.i < DRAW_PREC)
				julia_calc(&c);
			if (c.i != DRAW_PREC)
				draw_pixel(var->img, c.x, c.y, color(c.i));
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
