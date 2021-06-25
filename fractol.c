/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/25 16:06:52 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_fract(t_fract *var)
{
	if (!var->param->mandelbrot)
		mandelbrot(var);
	else if (!var->param->julia)
		julia(var);
}

int		main(int argc, char **argv)
{
	t_fract		var;

	if (argc != 2)
	{
		printf("ARGUMENT NUMBER ERROR\n");
		exit(1);
	}
	init_mlx(&var);
	check_name(argv[1], &var);
	init_const(&var);
	display_fract(&var);
	mlx_hook(var.win_ptr, 2, 1L<<0, ft_key, &var);
	mlx_hook(var.win_ptr, 17, 1L<<17, ft_close, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make && make fclean && ./fractol mandelbrot