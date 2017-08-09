/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_limits_fractales.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:28:55 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/04 15:11:41 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_limits_ship_bird(t_p *p)
{
	if (p->fractale == SHIP)
	{
		p->x1 = -2.1;
		p->x2 = 1.5;
		p->y1 = -2.3;
		p->y2 = 1.9;
		p->iter_max = 40;
	}
	else if (p->fractale == BIRD)
	{
		p->x1 = -1.6;
		p->x2 = 1.5;
		p->y1 = -1.5;
		p->y2 = 1.9;
		p->iter_max = 40;
	}
}

static void	init_limits_mandel_julia(t_p *p)
{
	if (p->fractale == MANDELBROT)
	{
		p->x1 = -2.0;
		p->x2 = 1.0;
		p->y1 = -1.5;
		p->y2 = 1.5;
		p->iter_max = 40;
	}
	else if (p->fractale == JULIA)
	{
		p->x1 = -1.5;
		p->x2 = 1;
		p->y1 = -1.6;
		p->y2 = 1.2;
		p->iter_max = 80;
	}
}

void		init_limits_fractale(t_p *p)
{
	if (MANDEL_OR_JULIA)
		init_limits_mandel_julia(p);
	else if (p->fractale == DUOBROT || p->fractale == TRIOBROT ||
			p->fractale == MANDELBAR)
	{
		p->x1 = -1.5;
		p->x2 = 1.2;
		p->y1 = -1.5;
		p->y2 = 1.5;
		p->iter_max = 40;
	}
	else if (p->fractale == BUFFALO)
	{
		p->x1 = -2.3;
		p->x2 = 1.0;
		p->y1 = -1.9;
		p->y2 = 1.5;
		p->iter_max = 40;
	}
	else if (SHIP_OR_BIRD)
		init_limits_ship_bird(p);
	p->offx = 1.5;
	p->offy = 1.5;
	p->zoom = 200.0;
}
