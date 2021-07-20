/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:14:42 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/20 17:51:51 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "libft/libft.h"

/*
** DEFINE
*/

# define THREADS 64
# define SCREEN 1
# define COLOR 0
# define DRAW_PREC 200
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 22
# define KEY_6 23
# define KEY_7 26
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

/*
** STRUCT
*/

typedef struct s_fractlist	t_fract;

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
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	zoom_x;
	long double	zoom_y;
	float		screen_x;
	float		screen_y;
	float		add_x;
	float		add_y;
	int			zoom;
	int			id;
	int			color;
}				t_param;

typedef struct s_thread
{
	t_fract	*var;
	int		id;
}				t_thread;

typedef struct s_render
{
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}				t_render;

struct s_fractlist
{
	t_img		*img;
	t_param		*param;
	t_render	render;
	void	*mlx_ptr;
	void	*win_ptr;
};

/*
** FRACTAL FUNCTION
*/

void	mandelbrot(t_fract *var, int x, int y);
void	julia(t_fract *var, int x, int y);
void	beryl(t_fract *var, int x, int y);
void	burningship(t_fract *var, int x, int y);
void	check_name(char *str, t_fract *var);
int		display_fract(t_fract *var, int x, int y);
int		check_mandelbrot(char *str);
int		check_julia(char *str);
int		check_beryl(char *str);
int		check_burningship(char *str);

/*
** MOVE FUNCTION
*/

int		ft_key(int key, t_fract *var);
int		ft_mouse_wheel(int button, int x, int y, t_fract *var);
void	other_key(int key, t_fract *var);
void	zoom_in(t_fract *var);
void	zoom_out(t_fract *var);
void	move_up(t_fract *var);
void	move_down(t_fract *var);
void	move_left(t_fract *var);
void	move_right(t_fract *var);

/*
** VAR FUNCTION
*/

void	init_struct(t_fract *var);
void	init_screen_size(t_fract *var);
void	init_const(t_fract *var);
void	init_mandelbrot(t_fract *var);
void	init_julia(t_fract *var);
void	init_beryl(t_fract *var);
void	init_burningship(t_fract *var);

/*
** MLX FUNCTION
*/

void	draw_pixel(t_img *img, int x, int y, int color);
void	init_mlx(t_fract *var);
void	ft_reset(t_fract *var);

/*
** THREADS FUNCTION
*/

void	*use_threads(void *v);
int		init_threads(t_fract *var);

/*
** COLOR FUNCTION
*/

void	select_color(t_fract *var, char *str);
int		color(int i, t_fract *var);
int		color_ice(int i);
int		color_fire(int i);
int		color_rave(int i);
int		color_clown(int i);
int		color_psycho(int i);

/*
** UTILS FUNCTION
*/

void	return_error(int index);
int		ft_close(t_fract *var);

#endif