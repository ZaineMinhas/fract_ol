/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:14:42 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 17:15:40 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

/*
** DEFINE
*/

# define SCREEN 1
# define DRAW_PREC 100
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

/*
** STRUCT
*/

typedef struct s_imglist
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_paramlist
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	int		prec;
	int		screen_x;
	int		screen_y;
	int		mandelbrot;
	int		julia;
}				t_param;

typedef	struct	s_fractlist
{
	t_img	*img;
	t_param	*param;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fract;

/*
** FRACTAL FUNCTION
*/

void	display_fract(t_fract *var);
void    mandelbrot(t_fract *var);
void	julia(t_fract *var);
void	zoom_in(t_fract *var);
void	zoom_out(t_fract *var);
void	move_up(t_fract *var);
void	move_down(t_fract *var);
void	move_left(t_fract *var);
void	move_right(t_fract *var);

/*
** VAR FUNCTION
*/

int		ft_key(int key, t_fract *var);
void	init_struct(t_fract *var);
void	init_mlx(t_fract *var);
void	init_const(t_fract *var);
void	init_mandelbrot(t_fract *var);
void	init_julia(t_fract *var);

/*
** MLX FUNCTION
*/

void	draw_pixel(t_img *img, int x, int y, int color);
void	ft_reset(t_fract *var);

/*
** UTILS FUNCTION
*/

void	check_name(char *str, t_fract *var);
int		check_mandelbrot(char *str, t_fract *var);
int		check_julia(char *str, t_fract *var);
int		ft_close(t_fract *var);

#endif