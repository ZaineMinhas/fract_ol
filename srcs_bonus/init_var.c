/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:57:28 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/12 17:44:21 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	init_struct(t_fract *var)
{
	var->img = malloc(sizeof(t_img));
	var->param = malloc(sizeof(t_param));
	if (!var->img || !var->param)
		return_error(1);
}

void	init_mlx(t_fract *var)
{
	var->mlx_ptr = mlx_init();
	if (!var->mlx_ptr)
		return_error(2);
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->param->screen_x, \
	var->param->screen_y, "la fenetre");
	var->img->img = mlx_new_image(var->mlx_ptr, var->param->screen_x, \
	var->param->screen_y);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel,
			&var->img->line_length, &var->img->endian);
}

void	init_screen_size(t_fract *var)
{
	if (var->param->id == 1)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 360 * SCREEN;
	}
	else if (var->param->id == 2)
	{
		var->param->screen_x = 520 * SCREEN;
		var->param->screen_y = 580 * SCREEN;
	}
	else if (var->param->id == 3)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 360 * SCREEN;
	}
	else if (var->param->id == 4)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 430 * SCREEN;
	}
}

void	init_const(t_fract *var)
{
	if (var->param->id == 1)
		init_mandelbrot(var);
	else if (var->param->id == 2)
		init_julia(var);
	else if (var->param->id == 3)
		init_beryl(var);
	else if (var->param->id == 4)
		init_burningship(var);
}
