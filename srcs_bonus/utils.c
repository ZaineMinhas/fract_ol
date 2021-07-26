/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:40:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/26 17:29:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	return_error(int index)
{
	if (!index)
	{
		printf("\033[91mARGUMENT NUMBER ERROR\033[0m\n");
		return_error(3);
	}
	else if (index == 1)
		printf("\033[91mMALLOC ERROR\033[0m\n");
	else if (index == 2)
		printf("TOO MUCH THREADS\n");
	else if (index == 3)
	{
		printf("Second argument have to be :\n-Mandelbrot\n-Julia\n-Beryl\n");
		printf("-Burningship\n");
	}
	exit(1);
}

void	select_color(t_fract *var, char *str)
{
	int	c;

	if (!str)
	{
		var->param->color = COLOR;
		return ;
	}
	c = ft_atoi(str);
	if (c >= 0 && c <= 6)
		var->param->color = c;
	else
		var->param->color = COLOR;
}

int	color(int i, t_fract *var)
{
	if (var->param->color == 0)
		return (color_ice(i));
	else if (var->param->color == 1)
		return (color_fire(i));
	else if (var->param->color == 2)
		return (color_clown(i));
	else if (var->param->color == 3)
		return (color_rave(i));
	else if (var->param->color == 4)
		return (color_psycho(i));
	else if (var->param->color == 5)
		return (65382 + i * 300000);
	else if (var->param->color == 6)
		return (16776960 + i * 30000000);
	else
	{
		printf("COLOR SET INVALID\n");
		exit(1);
	}
}

int	ft_close(t_fract *var)
{
	(void)var;
	exit(1);
	return (0);
}
