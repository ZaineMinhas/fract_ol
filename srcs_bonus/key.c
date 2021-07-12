/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/12 16:37:58 by zminhas          ###   ########.fr       */
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
		zoom_in(var);
	else if (key == KEY_DOWN)
		zoom_out(var);
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

int	ft_mouse_wheel(int button, int x, int y, t_fract *var)
{
	x = 9;
	y = 6;
	if (button == 4)
		var->param->moves[0] = 1;
	else if (button == 5)
		var->param->moves[0] = -1;
	return (0);
}
