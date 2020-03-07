/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:10:55 by mkabirov          #+#    #+#             */
/*   Updated: 2020/01/05 23:28:08 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define THREADS 16

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*img_ptr;
	void		*img;
	char		*get_addr;
	int			bpp;
	int			sl;
	int			endian;
	int			height;
	int			width;
	int			max_iter;
	double		c_im;
	double		c_re;
	double		x_mouse;
	double		y_mouse;
	double		x_shift;
	double		y_shift;
	double		red_sh;
	double		green_sh;
	double		blue_sh;
	double		zoom;
	int			blue_add;
	int			(*func_name)(struct s_fract*, double row, double col);
	pthread_t	threads[THREADS];
}				t_fract;

t_fract			*initialize_struct(void);
void			initialize_window(t_fract *fract);
void			error_mes(char *s);
void			draw(t_fract *fract, int col, int col_end);
int				mandelbrot(t_fract *fract, double c_re, double c_im);
int				julia(t_fract *fract, double x, double y);
int				burning_ship(t_fract *fract, double c_re, double c_im);
int				cat_mandelbrot(t_fract *fract, double c_re, double c_im);
void			select_fractol(char **argv, t_fract *fract);
void			colorize(int iteration, int pix_addr, t_fract *fract);
void			all_black(int pix_addr, t_fract *fract);
void			set_hooks(t_fract *fract);
int				hook_mouse_motion(int x, int y, t_fract *fract);
int				hook_mouse_scroll(int button, int x, int y, t_fract *fract);
int				hook_keyboard(int key, t_fract *fract);
void			*make_threads(void *fract);
void			multithread(t_fract *fract);

#endif
