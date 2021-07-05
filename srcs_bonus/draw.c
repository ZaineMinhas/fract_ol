/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:40:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 16:38:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	ft_reset(t_fract *var)
{
	int x;
	int y;

	x = -1;
	while (++x < var->param->screen_x)
	{
		y = -1;
		while (++y < var->param->screen_y)
			draw_pixel(var->img, x, y, 000000000);
	}
}