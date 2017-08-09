/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:20:32 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:58:57 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_struct_p3(t_p *p)
{
	p->opencl = NULL;
	p->fcolor = NULL;
	p->fkernel = NULL;
	p->fpalette1 = NULL;
	p->fpalette2 = NULL;
	p->fpalette3 = NULL;
	p->fbegin = NULL;
	p->img = NULL;
	p->global = 0;
	p->local = 0;
}

static void	init_struct_p2(t_p *p)
{
	p->device_id = NULL;
	p->context = NULL;
	p->commands = NULL;
	p->buffer = NULL;
	p->program = NULL;
	p->kernel = NULL;
	p->nb_pixels = WIDTH_W * HEIGHT_W;
	p->blue = 0;
	p->green = 0;
	p->red = 0;
	p->color = 0;
	p->offx = 0;
	p->offy = 0;
	p->c[I] = 0;
	p->c[R] = 0;
	p->z[I] = 0;
	p->z[R] = 0;
	p->x1 = 0;
	p->x2 = 0;
	p->y1 = 0;
	p->y2 = 0;
	p->z_im = 0;
	p->squares = 0;
	p->zoom = 200;
	init_struct_p3(p);
}

void		init_struct_p(t_p *p)
{
	p->mlx_ptr = NULL;
	p->win = NULL;
	p->img_ptr = NULL;
	p->round = 32;
	p->coorx = 0;
	p->coory = 0;
	p->mx = 0;
	p->my = 0;
	p->width = WIDTH_W;
	p->height = HEIGHT_W;
	p->space = 0;
	p->bpp = -1;
	p->s_l = -1;
	p->endian = -1;
	ft_bzero(p->keyflag, 256);
	p->midx = WIDTH_W / 2;
	p->midy = HEIGHT_W / 2;
	p->palette = 0;
	p->iter_max = 0;
	init_struct_p2(p);
}

void		init_mlx(t_p *p)
{
	p->mlx_ptr = mlx_init();
	p->win = mlx_new_window(p->mlx_ptr, WIDTH_W, HEIGHT_W,
			"Fract'ol");
	if ((p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH_W, HEIGHT_W)) == NULL)
		ft_print_error_exit(&ft_putendl, "Error");
	p->img = mlx_get_data_addr(p->img_ptr, &p->bpp, &p->s_l, &p->endian);
}
