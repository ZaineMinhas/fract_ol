/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:19:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/07/10 16:29:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	color_fire(int i)
{
	int	color[24];

	color[0] = 0x001E0500;
	color[1] = 0x00270502;
	color[2] = 0x00300505;
	color[3] = 0x00390508;
	color[4] = 0x0043050B;
	color[5] = 0x004C050E;
	color[6] = 0x00550511;
	color[7] = 0x005F0514;
	color[8] = 0x00640A14;
	color[9] = 0x00781A14;
	color[10] = 0x008C2B14;
	color[11] = 0x00A03C14;
	color[12] = 0x009B0A14;
	color[13] = 0x00910914;
	color[14] = 0x00870814;
	color[15] = 0x007D0714;
	color[16] = 0x00730714;
	color[17] = 0x00690614;
	color[18] = 0x005F0514;
	color[19] = 0x00550514;
	color[20] = 0x005A0A14;
	color[21] = 0x00853214;
	color[22] = 0x00B05A14;
	color[23] = 0x00DC8214;
	return (color[i % 24]);
}

int	color_ice(int i)
{
	int	color[24];

	color[0] = 0x000A78CD;
	color[1] = 0x000A6BC2;
	color[2] = 0x000A5EB7;
	color[3] = 0x000A51AD;
	color[4] = 0x000A44A2;
	color[5] = 0x000A3898;
	color[6] = 0x000A2B8D;
	color[7] = 0x000A1E83;
	color[8] = 0x000A1178;
	color[9] = 0x000A056E;
	color[10] = 0x00161378;
	color[11] = 0x00232282;
	color[12] = 0x002F308D;
	color[13] = 0x003C3F97;
	color[14] = 0x00484EA1;
	color[15] = 0x00555CAC;
	color[16] = 0x00616BB6;
	color[17] = 0x006E7AC0;
	color[18] = 0x007A88CB;
	color[19] = 0x008797D5;
	color[20] = 0x0093A6DF;
	color[21] = 0x00A0B4EA;
	color[22] = 0x00ACC3F4;
	color[23] = 0x00B9D2FF;
	return (color[i % 24]);
}

int	color_clown(int i)
{
	int	color[12];

	color[0] = 0x00500A78;
	color[1] = 0x005F1487;
	color[2] = 0x006E1E96;
	color[3] = 0x00055F32;
	color[4] = 0x00197D37;
	color[5] = 0x002D9B3C;
	color[6] = 0x00C8AF3C;
	color[7] = 0x00E1D23C;
	color[8] = 0x00FAF53C;
	color[9] = 0x00CD730A;
	color[10] = 0x00C56605;
	color[11] = 0x00BE5A00;
	return (color[i % 12]);
}

int	color_psycho(int i)
{
	int	color[16];

	color[0] = 0x00FF0000;
	color[1] = 0x0000FF00;
	color[2] = 0x000000FF;
	color[3] = 0x00FF0000;
	color[4] = 0x0000FF00;
	color[5] = 0x000000FF;
	color[6] = 0x00FF0000;
	color[7] = 0x0000FF00;
	color[8] = 0x000000FF;
	color[9] = 0x00FF0000;
	color[10] = 0x0000FF00;
	color[11] = 0x000000FF;
	color[12] = 0x00FF0000;
	color[13] = 0x0000FF00;
	color[14] = 0x000000FF;
	color[15] = 0x00FFFFFF;
	return (color[i % 16]);
}

int	color_rave(int i)
{
	int	color[22];

	color[0] = 0x00000000;
	color[1] = 0x0005FF05;
	color[2] = 0x00000000;
	color[3] = 0x00FF0505;
	color[4] = 0x00000000;
	color[5] = 0x003246FF;
	color[6] = 0x00000000;
	color[7] = 0x00FF0096;
	color[8] = 0x00000000;
	color[9] = 0x00780A8C;
	color[10] = 0x00000000;
	color[11] = 0x0064FA64;
	color[12] = 0x00000000;
	color[13] = 0x00FA6464;
	color[14] = 0x00000000;
	color[15] = 0x00FA7800;
	color[16] = 0x00000000;
	color[17] = 0x00FFFF05;
	color[18] = 0x00000000;
	color[19] = 0x000AFAE6;
	color[20] = 0x00000000;
	color[21] = 0x006464FA;
	return (color[i % 22]);
}
