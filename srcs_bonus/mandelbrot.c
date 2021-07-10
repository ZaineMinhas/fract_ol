/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:01:17 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 16:04:36 by zminhas          ###   ########.fr       */
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

void	mandelbrot(t_fract *var)
{
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
	int			x;
	int			y;
	int			i;

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
			i = -1;
			while (z_r * z_r + z_i * z_i <= 4 && ++i < DRAW_PREC)
			{
				tmp = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_r * z_i + c_i;
				z_r = tmp;
			}
			if (i != DRAW_PREC)
				draw_pixel(var->img, x, y, color(i, var));
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
