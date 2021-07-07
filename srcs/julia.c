/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:30:34 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/07 19:58:05 by zminhas          ###   ########.fr       */
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
			i = -1;
			while (z_r * z_r + z_i * z_i <= 4 && ++i < DRAW_PREC)
			{
				tmp = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_r * z_i + c_i;
                z_r = tmp;
			}
			if  (i != DRAW_PREC)
				draw_pixel(var->img, x, y, color(i));
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
