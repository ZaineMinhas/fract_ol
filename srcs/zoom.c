/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:57:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/05 16:52:45 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_fract *var)
{
		ft_reset(var);
		var->param->zoom_x *= 1.05;
		var->param->zoom_y *= 1.05;
		var->param->x1 += var->param->add_x / (var->param->zoom_x / 20);
		var->param->y1 += var->param->add_y / (var->param->zoom_y / 20);
		var->param->moves[0] = 0;
}

void	zoom_out(t_fract *var)
{
	ft_reset(var);
	var->param->zoom_x *= 0.95;
	var->param->zoom_y *= 0.95;
	var->param->x1 -= var->param->add_x / (var->param->zoom_x / 20);
	var->param->y1 -= var->param->add_y / (var->param->zoom_y / 20);
	var->param->moves[0] = 0;
}
