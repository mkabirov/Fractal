/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:11:17 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 23:11:00 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void		error_mes(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void		select_fractol(char **argv, t_fract *fract)
{
	if (argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3'
	|| argv[1][0] == '4')
	{
		if (argv[1][0] == '1')
			fract->func_name = &mandelbrot;
		else if (argv[1][0] == '2')
			fract->func_name = &julia;
		else if (argv[1][0] == '3')
			fract->func_name = &burning_ship;
		else if (argv[1][0] == '4')
			fract->func_name = &cat_mandelbrot;
		multithread(fract);
		set_hooks(fract);
	}
	else
		error_mes("usage: check input 1 / 2 / 3 / 4");
}

int			main(int argc, char **argv)
{
	t_fract	*fract;
	int		i;

	i = 0;
	if (argc == 2)
	{
		fract = initialize_struct();
		initialize_window(fract);
		select_fractol(argv, fract);
		mlx_loop(fract->mlx_ptr);
		free(fract);
	}
	else
		error_mes("usage: ./fractal [type number: 1 - Mandelbrot, 2 - Julia, \
3 - Burning Ship, 4 - MandelCat]");
	return (0);
}
