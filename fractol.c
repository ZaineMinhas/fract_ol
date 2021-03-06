/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/27 19:49:37 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_fract(t_fract *var)
{
	if (var->param->id == 1)
		mandelbrot(var);
	else if (var->param->id == 2)
		julia(var);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fract		var;

	if (argc < 2)
		return_error(0);
	init_struct(&var);
	check_name(argv[1], &var);
	init_mlx(&var);
	init_const(&var);
	if (argc < 4)
		julia_set(&var, argv[2]);
	else
		julia_set(&var, NULL);
	mlx_hook(var.win_ptr, 2, 1L << 0, ft_key, &var);
	mlx_hook(var.win_ptr, 4, 1L << 2, ft_mouse_wheel, &var);
	mlx_hook(var.win_ptr, 17, 1L << 17, ft_close, &var);
	mlx_loop_hook(var.mlx_ptr, display_fract, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make && make fclean && ./fractol mandelbrot