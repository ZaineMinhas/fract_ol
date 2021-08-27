/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:40:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/27 19:54:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
		printf("SOMETHING WRONG\n");
	else if (index == 3)
		printf("Second argument have to be :\n-Mandelbrot\n-Julia\n");
	exit(1);
}

int	ft_close(t_fract *var)
{
	(void)var;
	exit(1);
	return (0);
}

void	julia_set(t_fract *var, char *str)
{
	int	i;

	if (!str)
		return ;
	i = ft_atoi(str);
	if (i >= 1 && i <= 4)
		var->param->julia_set = i;
	else
		var->param->julia_set = 0;
}
