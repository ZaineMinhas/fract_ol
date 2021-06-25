/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/25 15:59:15 by zminhas          ###   ########.fr       */
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
		move_up(var);
	else if (key == KEY_A)
		move_left(var);
	else if (key == KEY_S)
		move_down(var);
	else if (key == KEY_D)
		move_right(var);
	//printf("--------------------\nx1 = %f\ny1 = %f\nx2 = %f\ny2 = %f\n", var->param->x1, var->param->y1, var->param->x2, var->param->y2);
	return (0);
}