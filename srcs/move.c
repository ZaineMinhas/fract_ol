/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:41:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/25 17:11:05 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_up(t_fract *var)
{
	ft_reset(var);
	var->param->y1 *= 0.95;
	display_fract(var);
}

void	move_down(t_fract *var)
{
	ft_reset(var);
	var->param->y1 *= 1.05;
	display_fract(var);
}

void	move_left(t_fract *var)
{
	ft_reset(var);
	var->param->x1 *= 0.995;
	display_fract(var);
}

void	move_right(t_fract *var)
{
	ft_reset(var);
	var->param->x1 *= 1.005;
	display_fract(var);
}
