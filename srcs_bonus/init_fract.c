/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:14:27 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/25 18:14:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	init_mandelbrot(t_fract *var)
{
	var->param->x1 = -2.1;
	var->param->x2 = 0.6;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.55 * SCREEN;
	var->param->add_y = 0.45 * SCREEN;
	var->param->zoom_x = var->param->screen_x / \
	(var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / \
	(var->param->y2 - var->param->y1);
}

void	init_julia(t_fract *var)
{
	var->param->x1 = -1;
	var->param->x2 = 1;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.65 * SCREEN;
	var->param->add_y = 0.725 * SCREEN;
	var->param->zoom_x = var->param->screen_x / \
	(var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / \
	(var->param->y2 - var->param->y1);
}

void	init_beryl(t_fract *var)
{
	var->param->x1 = -2.1;
	var->param->x2 = 0.6;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.55 * SCREEN;
	var->param->add_y = 0.45 * SCREEN;
	var->param->zoom_x = var->param->screen_x / \
	(var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / \
	(var->param->y2 - var->param->y1);
}

void	init_burningship(t_fract *var)
{
	var->param->x1 = -2.1;
	var->param->x2 = 0.6;
	var->param->y1 = -1.2;
	var->param->y2 = 1.2;
	var->param->add_x = 0.55 * SCREEN;
	var->param->add_y = 0.45 * SCREEN;
	var->param->zoom_x = var->param->screen_x / \
	(var->param->x2 - var->param->x1);
	var->param->zoom_y = var->param->screen_y / \
	(var->param->y2 - var->param->y1);
}
