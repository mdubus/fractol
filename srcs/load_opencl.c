/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:00:00 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 16:00:01 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	load_part2(t_p *p, int *err)
{
	*err |= clSetKernelArg(p->kernel, 10, sizeof(p->x2), &p->x2);
	*err |= clSetKernelArg(p->kernel, 11, sizeof(p->y1), &p->y1);
	*err |= clSetKernelArg(p->kernel, 12, sizeof(p->y2), &p->y2);
	*err |= clSetKernelArg(p->kernel, 13, sizeof(CR), &CR);
	*err |= clSetKernelArg(p->kernel, 14, sizeof(CI), &CI);
	*err |= clSetKernelArg(p->kernel, 15, sizeof(ZR), &ZR);
	*err |= clSetKernelArg(p->kernel, 16, sizeof(ZI), &ZI);
	*err |= clSetKernelArg(p->kernel, 17, sizeof(p->iter_max), &p->iter_max);
	*err |= clSetKernelArg(p->kernel, 18, sizeof(p->mx), &p->mx);
	*err |= clSetKernelArg(p->kernel, 19, sizeof(p->my), &p->my);
	*err |= clSetKernelArg(p->kernel, 20, sizeof(p->midx), &p->midx);
	*err |= clSetKernelArg(p->kernel, 21, sizeof(p->midy), &p->midy);
}

void		load_arguments_opencl(t_p *p)
{
	int err;

	err = -1;
	err = clSetKernelArg(p->kernel, 0, sizeof(cl_mem), &p->buffer);
	err |= clSetKernelArg(p->kernel, 1, sizeof(p->fractale), &p->fractale);
	err |= clSetKernelArg(p->kernel, 2, sizeof(p->width), &p->width);
	err |= clSetKernelArg(p->kernel, 3, sizeof(p->height), &p->height);
	err |= clSetKernelArg(p->kernel, 4, sizeof(p->zoom), &p->zoom);
	err |= clSetKernelArg(p->kernel, 5, sizeof(p->offx), &p->offx);
	err |= clSetKernelArg(p->kernel, 6, sizeof(p->offy), &p->offy);
	err |= clSetKernelArg(p->kernel, 7, sizeof(p->round), &p->round);
	err |= clSetKernelArg(p->kernel, 8, sizeof(p->palette), &p->palette);
	err |= clSetKernelArg(p->kernel, 9, sizeof(p->x1), &p->x1);
	load_part2(p, &err);
	if (err != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl, "Error with clSetKernelArg");
}

void		load_opencl(t_p *p)
{
	int err;

	err = -1;
	load_arguments_opencl(p);
	p->global = p->nb_pixels;
	err = clEnqueueNDRangeKernel(p->commands, p->kernel, 1, NULL,
			&p->global, &p->local, 0, NULL, NULL);
	if (err)
		ft_print_error_exit(&ft_putendl, "Error with clEnqueueNDRangeKernel");
	clFinish(p->commands);
	err = clEnqueueReadBuffer(p->commands, p->buffer, CL_TRUE, 0,
			sizeof(unsigned int) * p->nb_pixels, p->img, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl, "Error with clEnqueueReadBuffer");
}
