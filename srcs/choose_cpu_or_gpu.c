/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_cpu_or_gpu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:19:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/04 15:05:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#ifndef DO_GPU

void	init(t_p *p)
{
	ft_putendl("GPU not defined");
	init_struct_p(p);
	init_mlx(p);
}

void	put_fractale(t_p *p)
{
	if (p->fractale >= 0 && p->fractale <= 8)
		load_fractale(p);
	put_image_mlx(p);
}

#else

void	init(t_p *p)
{
	ft_putendl("GPU defined");
	init_struct_p(p);
	init_opencl(p);
	init_mlx(p);
}

void	put_fractale(t_p *p)
{
	get_fractal_differences(p);
	load_opencl(p);
	put_image_mlx(p);
}

#endif
