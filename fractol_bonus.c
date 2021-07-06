/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/06 16:58:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*static	void	ft_mandelbrot_croix(t_fract *var)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < 420)
		draw_pixel(var->img, x, 180, 0x3FFAB2);
	while (++y < 360)
		draw_pixel(var->img, 220, y, 0x3FFAB2);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}*/

/*static	void	ft_julia_croix(t_fract *var)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < 520)
		draw_pixel(var->img, x, 290, 0x3FFAB2);
	while (++y < 580)
		draw_pixel(var->img, 260, y, 0x3FFAB2);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}*/

static	int	check_moves(t_fract *var)
{
	if (var->param->moves[0] == 1)
		zoom_in(var);
	if (var->param->moves[0] == -1)
		zoom_out(var);
	return (1);
}

int		display_fract(t_fract *var)
{
	if (check_moves(var))
	{
		if (var->param->id == 1)
			mandelbrot(var);
		else if (var->param->id == 2)
			julia(var);
	}
	return (0);
	//ft_mandelbrot_croix(var);
}

int		main(int argc, char **argv)
{
	t_fract		var;

	if (argc != 2)
		return_error(0);
	init_struct(&var);
	check_name(argv[1], &var);
	init_mlx(&var);
	init_const(&var);
	mlx_hook(var.win_ptr, 2, 1L << 0, ft_key, &var);
	mlx_hook(var.win_ptr, 4, 1L << 2, ft_mouse_wheel, &var);
	mlx_hook(var.win_ptr, 17, 1L << 17, ft_close, &var);
	mlx_loop_hook(var.mlx_ptr, display_fract, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

//la formule : clear && make bonus && make fclean && ./fractol mandelbrot