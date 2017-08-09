/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:59:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:59:54 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	key_palette(t_p *p)
{
	p->palette += 1;
	if (p->palette >= 11)
		p->palette = 0;
}

static void	key_fractale(t_p *p)
{
	p->space = 0;
	p->fractale += 1;
	if (p->fractale >= 8)
		p->fractale = 0;
	init_limits_fractale(p);
	get_name_fractal(p);
}

int			key_press(int keycode, t_p *p)
{
	if (keycode == ESC)
		destroy_struct(p);
	if (keycode == P)
		key_palette(p);
	if (keycode == SPACE)
	{
		p->space++;
		if (p->space > 1)
			p->space = 0;
	}
	if (keycode == RST)
	{
		p->round = 32;
		p->midx = WIDTH_W / 2;
		p->midy = HEIGHT_W / 2;
		init_limits_fractale(p);
	}
	if (keycode == FRACT)
		key_fractale(p);
	else if (keycode >= 0 && keycode <= 255)
		p->keyflag[keycode] = 1;
	if (keycode == P || keycode == RST || keycode == FRACT)
		put_fractale(p);
	return (0);
}

int			key_release(int keycode, t_p *p)
{
	if (keycode >= 0 && keycode <= 255)
		p->keyflag[keycode] = 0;
	return (0);
}
