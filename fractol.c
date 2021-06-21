/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/21 18:19:59 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fract		var;

	(void)argv;
	init_mlx(&var);
	init_const(&var);
	if (argc != 2)
		printf("nik\n");
		printf("%f\n", var.math->x1);
		//exit(1);
	mandelbrot(&var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
