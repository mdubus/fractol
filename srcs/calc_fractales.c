/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:38:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/04 15:11:18 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	get_fractale2(t_p *p, double *tmp)
{
	if (p->fractale == MANDELBAR)
	{
		*tmp = -(ZR * ZR - (ZI * ZI * 3.0)) * ZR + CR;
		ZI = ((ZR * ZR * 3.0) - ZI * ZI) * ZI + CI;
	}
	else if (p->fractale == JULIA)
	{
		*tmp = ZR * ZR - ZI * ZI + CR * WIDTH_W / 2 / p->mx;
		ZI = 2 * ZR * ZI + CI * HEIGHT_W / 2 / p->my;
	}
	else if (p->fractale == BUFFALO)
	{
		*tmp = ft_absolute_double(ZR * ZR - ZI * ZI) + CR;
		ZI = 2 * ft_absolute_double(ZR * ZI) + CI;
	}
	else if (p->fractale == SHIP)
	{
		*tmp = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ft_absolute_double(ZI * ZR) + CI;
	}
	else if (p->fractale == BIRD)
	{
		*tmp = (ZR * ZR - (ZI * ZI * 3)) * ft_absolute_double(ZR) + CR;
		ZI = ((ZR * ZR * 3) - ZI * ZI) * ft_absolute_double(ZI) + CI;
	}
}

void		get_fractale(t_p *p, int *i)
{
	double tmp;

	tmp = 0;
	if (p->fractale == MANDELBROT)
	{
		tmp = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZR * ZI + CI;
	}
	else if (p->fractale == DUOBROT)
	{
		tmp = ZR * ZR * ZR - 3 * ZR * ZI * ZI + CR;
		ZI = 3 * ZR * ZR * ZI - ZI * ZI * ZI + CI;
	}
	else if (p->fractale == TRIOBROT)
	{
		tmp = ZR * ZR * ZR * ZR + ZI * ZI * ZI * ZI - 6 *
			ZR * ZR * ZI * ZI + CR;
		ZI = 4 * ZR * ZI * (ZR * ZR - ZI * ZI) + CI;
	}
	else
		get_fractale2(p, &tmp);
	ZR = tmp;
	(*i)++;
	p->z_im = ZI;
}
