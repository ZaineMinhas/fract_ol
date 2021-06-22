/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/22 18:57:07 by zminhas          ###   ########.fr       */
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
		//exit(1);
	mandelbrot(&var);
	mlx_hook(var.win_ptr, 2, 1L<<0, ft_key, &var);
	mlx_hook(var.win_ptr, 17, 1L<<17, ft_close, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make && make fclean && ./a.out