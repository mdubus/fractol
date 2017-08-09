/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:13:13 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 16:01:31 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_p *p, int x, int y)
{
	int	somme;

	somme = 0;
	if (x > 0 && x < WIDTH_W && y > 0 && y < HEIGHT_W)
	{
		somme = (int)(y * WIDTH_W + x) << 2;
		int_to_rgb(p);
		p->img[somme++] = (char)p->blue;
		p->img[somme++] = (char)p->green;
		p->img[somme++] = (char)p->red;
	}
}
