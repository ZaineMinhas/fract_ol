/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:41:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 16:27:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_up(t_fract *var)
{
	ft_reset(var);
	var->param->y1 += 1 / (var->param->zoom_y / 20);
	display_fract(var);
}

void	move_down(t_fract *var)
{
	ft_reset(var);
	var->param->y1 -= 1 / (var->param->zoom_y / 20);
	display_fract(var);
}

void	move_left(t_fract *var)
{
	ft_reset(var);
	var->param->x1 += 1 / (var->param->zoom_x / 20);
	display_fract(var);
}

void	move_right(t_fract *var)
{
	ft_reset(var);
	var->param->x1 -= 1 / (var->param->zoom_x / 20);
	display_fract(var);
}
