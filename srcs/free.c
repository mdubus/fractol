/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:30:16 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 12:35:15 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		destroy_struct(t_p *p)
{
	clReleaseProgram(p->program);
	clReleaseKernel(p->kernel);
	clReleaseCommandQueue(p->commands);
	clReleaseContext(p->context);
	clReleaseMemObject(p->buffer);
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	free((char*)p->opencl);
	exit(1);
}
