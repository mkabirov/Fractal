/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:37:30 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 23:13:51 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

t_fract		*initialize_struct(void)
{
	t_fract *fract;

	fract = (t_fract *)malloc(sizeof(t_fract));
	if (!fract)
		return (NULL);
	fract->width = 1200;
	fract->height = 1200;
	fract->max_iter = 50;
	fract->zoom = 0;
	fract->img = 0;
	fract->bpp = 4;
	fract->sl = 0;
	fract->endian = 0;
	fract->zoom = 1.0;
	fract->x_shift = 0;
	fract->y_shift = 0;
	fract->x_mouse = 0.4;
	fract->y_mouse = -0.3;
	fract->red_sh = 12;
	fract->green_sh = 25;
	fract->blue_sh = 8.5;
	fract->blue_add = 0;
	return (fract);
}

void		initialize_window(t_fract *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, fract->width,
	fract->height, "Fractol");
	fract->img = mlx_new_image(fract->mlx_ptr, fract->width, fract->height);
	fract->get_addr = mlx_get_data_addr(fract->img, &fract->bpp,
	&fract->sl, &fract->endian);
}
