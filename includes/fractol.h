/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:36:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:58:47 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Necessaire pour plusieurs fonctions (mlx_init, mlx_new_window, ...)
*/
# include "mlx.h"

/*
** Necessaire pour les masques de mlx_hook
*/
# include "X.h"

# include <math.h>
# include <OpenCL/opencl.h>
# include "../libft/includes/libft.h"
# include "color.h"

/*
** open
*/
# include <fcntl.h>

/*
** perror
*/
# include <stdio.h>

# define WIDTH_W 800
# define HEIGHT_W 800
# define PLUS 69
# define MINUS 78
# define TOP 126
# define BOTTOM 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define P 35
# define RST 15
# define R 0
# define I 1
# define ACCG 33
# define ACCD 30
# define FRACT 3
# define ZOOM 5.0
# define SPACE 49

# define UI unsigned int
# define ZR p->z[R]
# define ZI p->z[I]
# define CI p->c[I]
# define CR p->c[R]

# define SHIP_OR_BIRD (p->fractale == SHIP || p->fractale == BIRD)
# define MANDEL_OR_JULIA (p->fractale == MANDELBROT || p->fractale == JULIA)

# define BLUE blue(i, p->iter_max, mult)
# define AQUA_BLUE aqua_blue(p->iter_max, i, mult)
# define GREY grey(i, p->iter_max, mult)
# define SMOOTH_AQUA_BLUE smooth_aqua_blue(p->iter_max, i, mult)
# define FIRE fire(i, p->iter_max, mult)
# define SHADE_OF_GREY shade_of_grey(i, p->iter_max, mult)
# define SMOOTH_SHADE_OF_GREY smooth_shade_of_grey(i, p->iter_max, mult)
# define RAINBOW rainbow2(p->iter_max, i, mult)
# define PICOTS picots(p->iter_max, i, p->squares, mult)
# define VASARELY vasarely(p->z_im)
# define ZEBRA zebra(i, p->iter_max, mult)

typedef struct			s_p
{
	void				*mlx_ptr;
	void				*win;
	void				*img_ptr;
	char				*img;
	char				*nfractale;
	char				*fcolor;
	char				*fkernel;
	char				*fpalette1;
	char				*fpalette2;
	char				*fpalette3;
	char				*fbegin;
	const char			*opencl;
	unsigned int		blue;
	unsigned int		green;
	unsigned int		red;
	unsigned int		color;
	unsigned int		nb_pixels;
	unsigned int		padding;
	int					bpp;
	int					s_l;
	int					endian;
	int					keyflag[256];
	int					width;
	int					height;
	int					palette;
	int					iter_max;
	int					round;
	int					midx;
	int					midy;
	int					coorx;
	int					coory;
	int					mx;
	int					my;
	int					fractale;
	int					space;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				z_im;
	double				squares;
	double				c[2];
	double				z[2];
	double				offx;
	double				offy;
	double				zoom;
	size_t				global;
	size_t				local;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_mem				buffer;
	cl_program			program;
	cl_kernel			kernel;
}						t_p;

typedef struct			s_fgnl
{
	int					fd;
	int					gnl_ret;
	char				*line;
	char				*mew;
	char				*temp;
}						t_fgnl;

/*
** calc_fractales
*/

void					get_fractale(t_p *p, int *i);

/*
** choose_cpu_or_gpu
*/

void					init(t_p *p);
void					put_fractale(t_p *p);

/*
** do_fractol
*/

void					do_fractol(t_p *p);

/*
** fractales
*/

void					get_fractal_differences(t_p *p);
void					load_fractale(t_p *p);

/*
** free
*/

int						destroy_struct(t_p *p);

/*
** init_limits_fractales
*/

void					init_limits_fractale(t_p *p);

/*
** init_opencl
*/

void					init_opencl(t_p *p);

/*
** init_structs
*/

void					init_struct_p(t_p *p);
void					init_mlx(t_p *p);

/*
** int_rgb_converter
*/

void					int_to_rgb(t_p *p);
void					rgb_to_int(t_p *p, int red, int green, int blue);

/*
** key_loop
*/

int						loop_key(t_p *p);

/*
** key_press
*/

int						key_press(int keycode, t_p *p);
int						key_release(int keycode, t_p *p);

/*
** load_opencl
*/

void					load_arguments_opencl(t_p *p);
void					load_opencl(t_p *p);

/*
** main
*/

void					get_name_fractal(t_p *p);
int						main(int argc, char **argv);

/*
** mouse_events
*/

int						expose(t_p *p);
int						mouse_events(int button, int x, int y, t_p *p);
int						red_cross(t_p *p);

/*
** move_julia
*/

int						move_julia(int x, int y, t_p *p);

/*
** put_image_mlx
*/

void					put_image_mlx(t_p *p);

/*
** usefull
*/

void					put_pixel(t_p *p, int x, int y);

#endif
