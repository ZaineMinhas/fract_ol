/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/04 18:52:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_key(int key, t_fract *var)
{
	//printf("%d\n", key);
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
	return (0);
}

int		ft_mouse_wheel(int button, int x, int y, t_fract *var)
{
	x = 9;
	y = 6;
	if (button == 4)
		var->param->zoom = 1;
	else if (button == 5)
		var->param->zoom = -1;
	return (0);
}