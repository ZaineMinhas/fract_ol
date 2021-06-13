/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:14:42 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/13 21:04:06 by zminhas          ###   ########.fr       */
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

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define DRAW_PREC 50

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

typedef struct s_mathlist
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_math;

typedef	struct	s_fractlist
{
	t_img	*img;
	t_math	*math;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fract;

/*
** VAR FONCTION
*/

void	init_mlx(t_fract *var);
void	init_const(t_fract *var);

/*
** MLX FONCTION
*/

void	ft_draw_pixel(t_img *img, int x, int y, int color);

#endif