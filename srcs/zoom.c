/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:57:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 17:26:44 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_fract *var)
{
		var->param->zoom_x *= 1.05;
		var->param->zoom_y *= 1.05;
		var->param->y1 += 0.55 / (var->param->zoom_y / 20);
		var->param->x1 += 0.55 / (var->param->zoom_x / 20);
		var->param->prec += 2;
		ft_reset(var);
		display_fract(var);
}

void	zoom_out(t_fract *var)
{
	var->param->zoom_x *= 0.95;
	var->param->zoom_y *= 0.95;
	var->param->y1 -= 0.55 / (var->param->zoom_y / 20);
	var->param->x1 -= 0.55 / (var->param->zoom_x / 20);
	var->param->prec -= 2;
	ft_reset(var);
	display_fract(var);
}
