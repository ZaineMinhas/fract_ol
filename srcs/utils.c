/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:40:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 16:24:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
		printf("Second argument have to be :\n-Mandelbrot\n-Julia\n");
	exit(1);
}

int	ft_close(t_fract *var)
{
	(void)var;
	exit(1);
	return (0);
}
