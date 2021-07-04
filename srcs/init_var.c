/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:57:28 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/04 19:08:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_struct(t_fract *var)
{
	var->img = malloc(sizeof(t_img));
	if (!var->img)
		return_error(1);
	var->param = malloc(sizeof(t_param));
	if (!var->param)
		return_error(1);
}

void	init_mlx(t_fract *var)
{
	var->mlx_ptr = mlx_init();
	if (!var->mlx_ptr)
		return_error(2);
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->param->screen_x, var->param->screen_y, "la fenetre");
	var->img->img = mlx_new_image(var->mlx_ptr, var->param->screen_x, var->param->screen_y);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel,
			&var->img->line_length, &var->img->endian);
}

void	init_mandelbrot(t_fract *var)
{
	var->param->x1 = -2.1;
	var->param->x2 = 0.6;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.55 * SCREEN;
	var->param->add_y = 0.45 * SCREEN;
	var->param->zoom_x = var->param->screen_x / (var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / (var->param->y2 - var->param->y1);
}

void	init_julia(t_fract *var)
{
	var->param->x1 = -1;
	var->param->x2 = 1;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.65 * SCREEN;
	var->param->add_y = 0.725 * SCREEN;
	var->param->zoom_x = var->param->screen_x / (var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / (var->param->y2 - var->param->y1);
}

void	init_const(t_fract *var)
{
	if (!var->param->mandelbrot)
		init_mandelbrot(var);
	else if (!var->param->julia)
		init_julia(var);
}
