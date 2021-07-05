/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/05 19:28:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_key(int key)
{
	if (key == KEY_ESC)
		exit(1);
	return (0);
}

int		ft_mouse_wheel(int button, int x, int y, t_fract *var)
{
	x = 9;
	y = 6;
	if (button == 4)
		zoom_in(var);
		//var->param->moves[0] = 1;
	else if (button == 5)
		zoom_out(var);
		//var->param->moves[0] = -1;
	return (0);
}