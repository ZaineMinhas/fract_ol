/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:57:28 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/21 18:05:08 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_fract *var)
{
	var->img = malloc(sizeof(t_img));
	var->math = malloc(sizeof(t_math));
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, 1920, 1080, "la fenetre");
	var->img->img = mlx_new_image(var->mlx_ptr, 1920, 1080);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel,
			&var->img->line_length, &var->img->endian);
}

void	init_const(t_fract *var)
{
	var->math->x1 = -2.1;
	var->math->x2 = 0.6;
	var->math->y1 = -1.2;
	var->math->y2 = 1.2;
	var->math->zoom = 200;
}
