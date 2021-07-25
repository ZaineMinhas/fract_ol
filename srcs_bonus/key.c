/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/25 18:35:51 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	other_key(int key, t_fract *var)
{
	if (key == KEY_1)
		var->param->color = 0;
	else if (key == KEY_2)
		var->param->color = 1;
	else if (key == KEY_3)
		var->param->color = 2;
	else if (key == KEY_4)
		var->param->color = 3;
	else if (key == KEY_5)
		var->param->color = 4;
	else if (key == KEY_6)
		var->param->color = 5;
	else if (key == KEY_7)
		var->param->color = 6;
}

int	ft_key(int key, t_fract *var)
{
	if (key == KEY_ESC)
		exit(1);
	else if (key == KEY_UP)
		var->param->zoom = 1;
	else if (key == KEY_DOWN)
		var->param->zoom = -1;
	else if (key == KEY_W)
		move_down(var);
	else if (key == KEY_A)
		move_right(var);
	else if (key == KEY_S)
		move_up(var);
	else if (key == KEY_D)
		move_left(var);
	else
		other_key(key, var);
	return (0);
}

int	ft_mouse_pos(int x, int y, t_fract *var)
{
	var->param->mouse_x = x;
	var->param->mouse_y = y;
	return (0);
}

int	ft_mouse_wheel(int button, int x, int y, t_fract *var)
{
	if (button == 1 || button == 2)
		return (0);
	if (x - var->param->screen_x / 2 < 0)
		var->param->x1 -= (1 / var->param->zoom_x) * MOUSE_SPEED *\
		(1 - (float)x / (var->param->screen_x / 2));
	else
		var->param->x1 += (1 / var->param->zoom_x) * MOUSE_SPEED *\
		((float)(x - var->param->screen_x / 2) / (var->param->screen_x / 2));
	if (y - var->param->screen_y / 2 < 0)
		var->param->y1 -= (1 / var->param->zoom_y) * MOUSE_SPEED *\
		(1 - (float)y / (var->param->screen_y / 2));
	else
		var->param->y1 += (1 / var->param->zoom_y) * MOUSE_SPEED *\
		((float)(y - var->param->screen_y / 2) / (var->param->screen_y / 2));
	if (button == 4)
		var->param->zoom = 1;
	else if (button == 5)
		var->param->zoom = -1;
	return (0);
}
