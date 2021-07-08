/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:40:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/08 16:21:08 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	return_error(int index)
{
	if (!index)
	{
		printf("ARGUMENT NUMBER ERROR\n");
		return_error(3);
	}
	else if (index == 1)
		printf("MALLOC ERROR\n");
	else if (index == 2)
		printf("SOMETHING WRONG\n");
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

int		ft_close(t_fract *var)
{
	(void)var;
	exit(1);
	return (0);
}
