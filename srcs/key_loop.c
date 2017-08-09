/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:33:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 12:55:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_center_key(t_p *p)
{
	p->offx += ((double)(WIDTH_W / 2 - p->midx)) / p->zoom;
	p->offy += ((double)(HEIGHT_W / 2 - p->midy)) / p->zoom;
	p->midx = (WIDTH_W / 2);
	p->midy = (HEIGHT_W / 2);
}

static void	key_plus(t_p *p)
{
	set_center_key(p);
	if (p->zoom > -1.0 && p->zoom < 0.0)
		p->zoom += 1.5;
	if (p->zoom < -1.0)
		p->zoom /= 1.0 + ZOOM / 100;
	else
		p->zoom *= 1.0 + ZOOM / 100;
}

static void	key_minus(t_p *p)
{
	set_center_key(p);
	if (p->zoom > 0.0 && p->zoom < 1.0)
		p->zoom -= 1.5;
	if (p->zoom < 1.0)
		p->zoom *= 1 + ZOOM / 100;
	else
		p->zoom /= 1 + ZOOM / 100;
}

int			loop_key(t_p *p)
{
	if (p->keyflag[PLUS] == 1)
		key_plus(p);
	if (p->keyflag[MINUS] == 1)
		key_minus(p);
	if (p->keyflag[LEFT] == 1)
		p->offx -= 10.0 / p->zoom;
	else if (p->keyflag[RIGHT] == 1)
		p->offx += 10.0 / p->zoom;
	if (p->keyflag[TOP] == 1)
		p->offy -= 10.0 / p->zoom;
	else if (p->keyflag[BOTTOM] == 1)
		p->offy += 10.0 / p->zoom;
	if (p->keyflag[ACCG] == 1)
		p->iter_max -= 1;
	else if (p->keyflag[ACCD] == 1)
		p->iter_max += 1;
	if (p->keyflag[LEFT] == 1 || p->keyflag[RIGHT] == 1 ||
			p->keyflag[TOP] == 1 || p->keyflag[BOTTOM] == 1 ||
			p->keyflag[ACCG] == 1 || p->keyflag[ACCD] == 1 ||
			p->keyflag[MINUS] == 1 || p->keyflag[PLUS] == 1)
		put_fractale(p);
	return (0);
}
