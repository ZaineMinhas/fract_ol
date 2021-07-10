/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:08:08 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 16:27:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_mandelbrot(char *str)
{
	if (ft_strlen(str) != 10)
		return (0);
	if (str[0] != 'm' && str[0] != 'M')
		return (0);
	if (str[1] != 'a' && str[1] != 'A')
		return (0);
	if (str[2] != 'n' && str[2] != 'N')
		return (0);
	if (str[3] != 'd' && str[3] != 'D')
		return (0);
	if (str[4] != 'e' && str[4] != 'E')
		return (0);
	if (str[5] != 'l' && str[5] != 'L')
		return (0);
	if (str[6] != 'b' && str[6] != 'B')
		return (0);
	if (str[7] != 'r' && str[7] != 'R')
		return (0);
	if (str[8] != 'o' && str[8] != 'O')
		return (0);
	if (str[9] != 't' && str[9] != 'T')
		return (0);
	return (1);
}

int	check_julia(char *str)
{
	if (ft_strlen(str) != 5)
		return (0);
	if (str[0] != 'j' && str[0] != 'J')
		return (0);
	if (str[1] != 'u' && str[1] != 'U')
		return (0);
	if (str[2] != 'l' && str[2] != 'L')
		return (0);
	if (str[3] != 'i' && str[3] != 'I')
		return (0);
	if (str[4] != 'a' && str[4] != 'A')
		return (0);
	return (2);
}

void	check_name(char *str, t_fract *var)
{
	var->param->id = check_mandelbrot(str);
	if (!var->param->id)
		var->param->id = check_julia(str);
	if (var->param->id == 1)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 360 * SCREEN;
	}
	else if (var->param->id == 2)
	{
		var->param->screen_x = 520 * SCREEN;
		var->param->screen_y = 580 * SCREEN;
	}
	else
		return_error(3);
}
