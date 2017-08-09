/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_rgb_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:21:16 by mdubus            #+#    #+#             */
/*   Updated: 2017/07/22 13:58:41 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	int_to_rgb(t_p *p)
{
	p->red = (p->color >> 16) & 255;
	p->green = (p->color >> 8) & 255;
	p->blue = p->color & 255;
}

void	rgb_to_int(t_p *p, int red, int green, int blue)
{
	p->color = (UI)red << 16 | (UI)green << 8 |
		(UI)blue;
}
