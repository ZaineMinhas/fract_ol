/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/20 17:48:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static	int	check_moves(t_fract *var)
{
	if (var->param->zoom == 1)
		zoom_in(var);
	if (var->param->zoom == -1)
		zoom_out(var);
	return (1);
}

int	display_fract(t_fract *var, int x, int y)
{
	if (check_moves(var))
	{
		if (var->param->id == 1)
			mandelbrot(var, x, y);
		else if (var->param->id == 2)
			julia(var, x, y);
		else if (var->param->id == 3)
			beryl(var, x, y);
		else if (var->param->id == 4)
			burningship(var, x, y);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fract		var;

	if (argc < 2)
		return_error(0);
	init_struct(&var);
	if (argc >= 3)
		select_color(&var, argv[2]);
	else
		select_color(&var, NULL);
	check_name(argv[1], &var);
	init_mlx(&var);
	init_const(&var);
	mlx_hook(var.win_ptr, 2, 1L << 0, ft_key, &var);
	mlx_hook(var.win_ptr, 4, 1L << 2, ft_mouse_wheel, &var);
	mlx_hook(var.win_ptr, 17, 1L << 17, ft_close, &var);
	mlx_loop_hook(var.mlx_ptr, init_threads, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make bonus && make fclean && ./fractol mandelbrot