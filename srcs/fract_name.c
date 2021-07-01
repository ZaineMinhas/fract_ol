/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:08:08 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/01 16:53:33 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		check_mandelbrot(char *str, t_fract *var)
{
	var->param->mandelbrot = 0;
	if (ft_strlen(str) != 10)
		return (++var->param->mandelbrot);
	if (str[0] != 'm' && str[0] != 'M')
		return (++var->param->mandelbrot);
	if (str[1] != 'a' && str[1] != 'A')
		return (++var->param->mandelbrot);
	if (str[2] != 'n' && str[2] != 'N')
		return (++var->param->mandelbrot);
	if (str[3] != 'd' && str[3] != 'D')
		return (++var->param->mandelbrot);
	if (str[4] != 'e' && str[4] != 'E')
		return (++var->param->mandelbrot);
	if (str[5] != 'l' && str[5] != 'L')
		return (++var->param->mandelbrot);
	if (str[6] != 'b' && str[6] != 'B')
		return (++var->param->mandelbrot);
	if (str[7] != 'r' && str[7] != 'R')
		return (++var->param->mandelbrot);
	if (str[8] != 'o' && str[8] != 'O')
		return (++var->param->mandelbrot);
	if (str[9] != 't' && str[9] != 'T')
		return (++var->param->mandelbrot);
	return (0);
}

int		check_julia(char *str, t_fract *var)
{
	var->param->julia = 0;
	if (ft_strlen(str) != 5)
		return (++var->param->julia);
	if (str[0] != 'j' && str[0] != 'J')
		return (++var->param->julia);
	if (str[1] != 'u' && str[1] != 'U')
		return (++var->param->julia);
	if (str[2] != 'l' && str[2] != 'L')
		return (++var->param->julia);
	if (str[3] != 'i' && str[3] != 'I')
		return (++var->param->julia);
	if (str[4] != 'a' && str[4] != 'A')
		return (++var->param->julia);
	return (0);
}

void	check_name(char *str, t_fract *var)
{
	if (!check_mandelbrot(str, var))
	{
		var->param->screen_x = 440/*440 * SCREEN*/;
		var->param->screen_y = 440/*360 * SCREEN*/;
	}
	if (!check_julia(str, var))
	{
		var->param->screen_x = 520;
		var->param->screen_y = 480;
	}
	if (var->param->mandelbrot && var->param->julia)
	{
		printf("NAME ERROR\n");
		exit(1);
	}
}