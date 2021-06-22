/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:41:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/22 19:17:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_up(t_fract *var)
{
	ft_reset(var);
	var->param->y1 *= 0.9;
	mandelbrot(var);
}

void	move_down(t_fract *var)
{
	ft_reset(var);
	var->param->y1 *= 1.1;
	mandelbrot(var);
}

void	move_left(t_fract *var)
{
	ft_reset(var);
	var->param->x1 *= 0.9;
	mandelbrot(var);
}

void	move_right(t_fract *var)
{
	ft_reset(var);
	var->param->x1 *= 1.1;
	mandelbrot(var);
}
