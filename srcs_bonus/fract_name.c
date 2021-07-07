/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:08:08 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/07 19:42:21 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int		check_mandelbrot(char *str)
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

int		check_julia(char *str)
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

int		check_beryl(char *str)
{
	if (ft_strlen(str) != 5)
		return (0);
	if (str[0] != 'b' && str[0] != 'B')
		return (0);
	if (str[1] != 'e' && str[1] != 'E')
		return (0);
	if (str[2] != 'r' && str[2] != 'R')
		return (0);
	if (str[3] != 'y' && str[3] != 'Y')
		return (0);
	if (str[4] != 'l' && str[4] != 'L')
		return (0);
	return (3);
}

int		check_burningship(char *str)
{
	if (ft_strlen(str) != 11)
		return (0);
	if (str[0] != 'b' && str[0] != 'B')
		return (0);
	if (str[1] != 'u' && str[1] != 'U')
		return (0);
	if (str[2] != 'r' && str[2] != 'R')
		return (0);
	if (str[3] != 'n' && str[3] != 'N')
		return (0);
	if (str[4] != 'i' && str[4] != 'I')
		return (0);
	if (str[5] != 'n' && str[5] != 'N')
		return (0);
	if (str[6] != 'g' && str[6] != 'G')
		return (0);
	if (str[7] != 's' && str[7] != 'S')
		return (0);
	if (str[8] != 'h' && str[8] != 'H')
		return (0);
	if (str[9] != 'i' && str[9] != 'I')
		return (0);
	if (str[10] != 'p' && str[10] != 'P')
		return (0);
	return (4);
}

void	check_name(char *str, t_fract *var)
{
	var->param->id = check_mandelbrot(str);
	if (!var->param->id)
		var->param->id = check_julia(str);
	if (!var->param->id)
		var->param->id = check_beryl(str);
	if (!var->param->id)
		var->param->id = check_burningship(str);
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
	else if (var->param->id == 3)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 360 * SCREEN;
	}
	else if (var->param->id == 4)
	{
		var->param->screen_x = 440 * SCREEN;
		var->param->screen_y = 360 * SCREEN;
	}
	else
		return_error(3);
}