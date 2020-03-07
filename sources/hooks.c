/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:21:10 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 23:31:25 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int			hook_keyboard(int key, t_fract *fract)
{
	if (key == 53)
		exit(0);
	if (key == 24)
		fract->max_iter += 2;
	if (key == 27)
		fract->max_iter -= 2;
	if (key == 124)
		fract->x_shift -= 15;
	if (key == 123)
		fract->x_shift += 15;
	if (key == 125)
		fract->y_shift -= 15;
	if (key == 126)
		fract->y_shift += 15;
	if (key == 8)
	{
		fract->blue_add = 1;
		fract->red_sh -= -0.5;
		fract->green_sh -= -0.5;
		fract->blue_sh -= -0.5;
	}
	multithread(fract);
	return (0);
}

int			hook_mouse_motion(int x, int y, t_fract *fract)
{
	fract->x_mouse = ((((double)x - fract->width) / (fract->width / 2)) + 1);
	fract->y_mouse = ((((double)y - fract->width) / (fract->width / 2)) + 1);
	multithread(fract);
	return (0);
}

int			hook_mouse_scroll(int button, int x, int y, t_fract *fract)
{
	if (button == 5)
	{
		x -= fract->width / 2;
		y -= fract->height / 2;
		fract->zoom = (fract->zoom + 1) * 1.1;
		fract->x_shift += x / fract->zoom / 1.5;
		fract->y_shift += y / fract->zoom / 1.5;
	}
	else if (button == 4)
	{
		if (fract->zoom > 2)
			fract->zoom = (fract->zoom - 1) / 1.1;
		if (fract->zoom < 4)
			fract->zoom = 1;
	}
	multithread(fract);
	return (0);
}

void		set_hooks(t_fract *fract)
{
	mlx_hook(fract->win_ptr, 2, 0, hook_keyboard, fract);
	mlx_hook(fract->win_ptr, 4, 0, hook_mouse_scroll, fract);
	mlx_hook(fract->win_ptr, 6, 0, hook_mouse_motion, fract);
}
