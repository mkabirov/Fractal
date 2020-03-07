/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:08:28 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 22:57:54 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void		colorize(int iteration, int pix_addr, t_fract *fract)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)iteration / (double)fract->max_iter;
	red = (int)(fract->red_sh * (1 - t) * pow(t, 2) * 255);
	green = (int)(fract->green_sh * pow((1 - t), 2) * pow(t, 2) * 255);
	if (fract->blue_add == 1)
		blue = (int)(fract->blue_sh * pow((1 - t), 3) * t * 255);
	else
		blue = 0;
	fract->get_addr[pix_addr] = (char)0;
	fract->get_addr[pix_addr++] = (char)blue;
	fract->get_addr[pix_addr++] = (char)green;
	fract->get_addr[pix_addr++] = (char)red;
}

void		all_black(int pix_addr, t_fract *fract)
{
	fract->get_addr[pix_addr] = (char)0;
	fract->get_addr[pix_addr++] = (char)255;
	fract->get_addr[pix_addr++] = (char)255;
	fract->get_addr[pix_addr++] = (char)255;
}
