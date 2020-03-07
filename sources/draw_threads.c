/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:52:43 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 22:58:42 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void		draw(t_fract *fract, int col, int col_end)
{
	int row;
	int iteration;
	int pix_addr;

	while (col < col_end)
	{
		row = -1;
		while (++row < fract->width)
		{
			pix_addr = row * 4 + (col * fract->width) * 4;
			iteration = fract->func_name(fract, row, col);
			if (iteration < fract->max_iter)
				colorize(iteration, pix_addr, fract);
			else
				all_black(pix_addr, fract);
		}
		col++;
	}
}

void		*make_threads(void *fract)
{
	t_fract	*f;
	int		i;

	f = (t_fract*)fract;
	i = -1;
	while (++i < THREADS)
	{
		if (pthread_equal(pthread_self(), f->threads[i]))
			draw(f, i * (f->width / THREADS), i *
			(f->width / THREADS) + (f->width / THREADS));
	}
	return (0);
}

void		multithread(t_fract *fract)
{
	int i;

	i = -1;
	while (++i < THREADS)
	{
		pthread_create(&fract->threads[i], NULL, make_threads, fract);
	}
	i = -1;
	while (++i < THREADS)
	{
		pthread_join(fract->threads[i], NULL);
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img, 0, 0);
}
