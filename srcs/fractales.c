/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:00:07 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/04 14:48:19 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	get_palette(t_p *p, int i)
{
	double mult;

	mult = ZR * ZR + ZI * ZI;
	if (p->palette == 0)
		p->color = AQUA_BLUE;
	else if (p->palette == 1)
		p->color = SMOOTH_AQUA_BLUE;
	else if (p->palette == 2)
		p->color = BLUE;
	else if (p->palette == 3)
		p->color = GREY;
	else if (p->palette == 4)
		p->color = FIRE;
	else if (p->palette == 5)
		p->color = SHADE_OF_GREY;
	else if (p->palette == 6)
		p->color = SMOOTH_SHADE_OF_GREY;
	else if (p->palette == 7)
		p->color = RAINBOW;
	else if (p->palette == 8)
		p->color = PICOTS;
	else if (p->palette == 9)
		p->color = VASARELY;
	else if (p->palette == 10)
		p->color = ZEBRA;
}

static void	foreach_pixel(t_p *p)
{
	int	i;

	i = 0;
	if (p->coory >= HEIGHT_W * 96 / 100)
		p->color = 0x000000;
	else if (p->coory >= HEIGHT_W * 92 / 100)
		p->color = 0xFFFFFF;
	else
	{
		i = 0;
		get_fractal_differences(p);
		while (ZR * ZR + ZI * ZI <= p->round && i < p->iter_max)
			get_fractale(p, &i);
		p->squares = ZR;
		get_palette(p, i);
	}
	put_pixel(p, p->coorx, p->coory);
	(p->coorx)++;
}

void		get_fractal_differences(t_p *p)
{
	if (p->fractale == JULIA)
	{
		ZR = (p->coorx - p->midx) / p->zoom + p->x1 + p->offx;
		ZI = (p->coory - p->midy) / p->zoom + p->y1 + p->offy;
		CR = 0.285;
		CI = 0.01;
	}
	else
	{
		CR = (p->coorx - p->midx) / p->zoom + p->x1 + p->offx;
		CI = (p->coory - p->midy) / p->zoom + p->y1 + p->offy;
		ZR = 0;
		ZI = 0;
	}
}

void		load_fractale(t_p *p)
{
	p->coorx = 0;
	p->coory = 0;
	while (p->coory < HEIGHT_W)
	{
		while (p->coorx < WIDTH_W)
			foreach_pixel(p);
		(p->coory)++;
		p->coorx = 0;
	}
}
