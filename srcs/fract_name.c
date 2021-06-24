/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:08:08 by zminhas           #+#    #+#             */
/*   Updated: 2021/06/24 15:11:57 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		check_mandelbrot(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) != 10)
		i++;
	if (str[0] != 'm' || str[0] != 'M')
		i++;
	if (str[1] != 'a' || str[1] != 'A')
		i++;
	if (str[2] != 'n' || str[2] != 'N')
		i++;
	if (str[3] != 'd'|| str[3] != 'D')
		i++;
	if (str[4] != 'e' || str[4] != 'E')
		i++;
	if (str[5] != 'l' || str[5] != 'L')
		i++;
	if (str[6] != 'b'|| str[6] != 'B')
		i++;
	if (str[7] != 'r' || str[7] != 'R')
		i++;
	if (str[8] != 'o' || str[8] != 'O')
		i++;
	if (str[9] != 't' || str[9] != 'T')
		i++;
	else
		i = 2;
	return (i);
}

int		check_julia(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) != 5)
		i++;
	if (str[0] != 'j' || str[0] != 'J')
		i++;
	if (str[1] != 'u' || str[1] != 'U')
		i++;
	if (str[2] != 'l' || str[2] != 'L')
		i++;
	if (str[3] != 'i' || str[3] != 'I')
		i++;
	if (str[4] != 'a' || str[4] != 'A')
		i++;
	else
		i = 2;
	return (i);
}