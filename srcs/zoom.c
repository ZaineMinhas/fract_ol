/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:57:33 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/25 17:23:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_fract *var)
{
		var->param->zoom += 15;
		var->param->zoom_x += 15;
		var->param->zoom_y += 15;
		ft_reset(var);
		display_fract(var);
}

void	zoom_out(t_fract *var)
{
	var->param->zoom -= 15;
	var->param->zoom_x -= 15;
	var->param->zoom_y -= 15;
	ft_reset(var);
	display_fract(var);
}
