/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:15:24 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/03 19:42:40 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_center_mouse(t_p *p, int x, int y)
{
	p->offx -= ((double)(p->midx - x)) / p->zoom;
	p->offy -= ((double)(p->midy - y)) / p->zoom;
	p->midx = x;
	p->midy = y;
}

int			expose(t_p *p)
{
	put_fractale(p);
	return (0);
}

int			mouse_events(int button, int x, int y, t_p *p)
{
	if (button == 5)
	{
		set_center_mouse(p, x, y);
		p->zoom *= 1.0 + ZOOM / 100;
		put_fractale(p);
	}
	if (button == 4)
	{
		set_center_mouse(p, x, y);
		p->zoom /= 1.0 + ZOOM / 100;
		put_fractale(p);
	}
	return (0);
}

int			red_cross(t_p *p)
{
	destroy_struct(p);
	return (0);
}
