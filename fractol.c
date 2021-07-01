/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 17:03:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static	void	ft_croix(t_fract *var)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < 440)
		draw_pixel(var->img, x, 220, 0x3FFAB2);
	while (++y < 440)
		draw_pixel(var->img, 220, y, 0x3FFAB2);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}*/

void	display_fract(t_fract *var)
{
	if (!var->param->mandelbrot)
		mandelbrot(var);
	else if (!var->param->julia)
		julia(var);
	//ft_croix(var);
}

int		main(int argc, char **argv)
{
	t_fract		var;

	if (argc != 2)
	{
		printf("ARGUMENT NUMBER ERROR\n");
		exit(1);
	}
	init_struct(&var);
	check_name(argv[1], &var);
	init_mlx(&var);
	init_const(&var);
	display_fract(&var);
	mlx_hook(var.win_ptr, 2, 1L<<0, ft_key, &var);
	mlx_hook(var.win_ptr, 17, 1L<<17, ft_close, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make && make fclean && ./fractol mandelbrot