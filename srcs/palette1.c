/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:00:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 16:00:12 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GPU
# include "../includes/fractol.h"
#endif

unsigned int	aqua_blue(int iter_max, int i, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (NOIR);
	s.red = sin(0.3 * (double)i);
	s.green = sin(0.3 * (double)i + 3) * 127 + 128;
	s.blue = sin(0.3 * (double)i + 3) * 127 + 128;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	smooth_aqua_blue(int iter_max, int i, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (NOIR);
	s.nu = (i + 2 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(74 * s.nu_frac);
	s.green = (int)(205 * s.nu_frac);
	s.blue = (int)(196 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	shade_of_grey(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLANC);
	s.red = sin(0.3 * (double)i) * 127 + 128;
	s.green = sin(0.3 * (double)i) * 127 + 128;
	s.blue = sin(0.3 * (double)i) * 127 + 128;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	smooth_shade_of_grey(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLANC);
	s.nu = (i + 5 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	s.green = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	s.blue = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}
