/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:47:45 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 23:13:29 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int				mandelbrot(t_fract *fract, double c_re, double c_im)
{
	int			iteration;
	double		x;
	double		y;
	double		x_next;

	x = 0;
	y = 0;
	iteration = 0;
	c_re = ((4.0 * c_re / fract->width - 2.0) / fract->zoom)
		+ (fract->x_shift / fract->width);
	c_im = ((4.0 * c_im / fract->height - 2.0) / fract->zoom)
		+ (fract->y_shift / fract->height);
	while (x * x + y * y <= 4 && iteration < fract->max_iter)
	{
		x_next = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = x_next;
		iteration++;
	}
	return (iteration);
}

int				julia(t_fract *fract, double x, double y)
{
	int			iteration;
	long double	temp;

	x = ((4.0 * x / fract->width - 2.0) / fract->zoom)
	+ (fract->x_shift / fract->width);
	y = ((4.0 * y / fract->height - 2.0) / fract->zoom)
	+ (fract->y_shift / fract->height);
	iteration = 0;
	while (x * x + y * y < 4.0 && iteration < fract->max_iter)
	{
		temp = x * x - y * y + fract->x_mouse;
		y = 2 * x * y + fract->y_mouse;
		x = temp;
		iteration++;
	}
	return (iteration);
}

int				burning_ship(t_fract *fract, double c_re, double c_im)
{
	int			iteration;
	double		x;
	double		y;
	double		x_next;

	x = 0;
	y = 0;
	iteration = 0;
	c_re = ((4.0 * c_re / fract->width - 2.0) / fract->zoom)
		+ (fract->x_shift / fract->width);
	c_im = ((4.0 * c_im / fract->height - 2.0) / fract->zoom)
		+ (fract->y_shift / fract->height);
	while (x * x + y * y <= 16 && iteration < fract->max_iter)
	{
		x_next = x * x - y * y + c_re;
		y = fabs(2 * x * y + c_im);
		x = fabs(x_next);
		iteration++;
	}
	return (iteration);
}

int				cat_mandelbrot(t_fract *fract, double c_re, double c_im)
{
	int			iteration;
	double		x;
	double		y;
	double		x_next;

	x = 0;
	y = 0;
	iteration = 0;
	c_im = ((4.0 * c_im / fract->width - 2.0) / fract->zoom)
		+ (fract->x_shift / fract->width);
	c_re = ((4.0 * c_re / fract->height - 2.0) / fract->zoom)
		+ (fract->y_shift / fract->height);
	while (x * x + y * y <= 4 && iteration < fract->max_iter)
	{
		x_next = x * x - y * y - c_im;
		y = -2 * fabs(x) * y - c_re;
		x = x_next;
		iteration++;
	}
	return (iteration);
}
