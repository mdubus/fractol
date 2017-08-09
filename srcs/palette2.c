/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:49:26 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/03 20:00:23 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GPU
# include "../includes/fractol.h"
#endif

unsigned int	rainbow2(int iter_max, int i, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLANC);
	s.red = sin(0.3 * (double)i + 0.0) * 127.0 + 128.0;
	s.green = sin(0.3 * (double)i + 2.0) * 127.0 + 128.0;
	s.blue = sin(0.3 * (double)i + 4.0) * 127.0 + 128.0;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	picots(int iter_max, int i, double squares, double mult)
{
	double			index;
	t_color			s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLANC);
	index = (double)i + 15.0 - (log2(log2(fabs(squares)))) / log2(2.0);
	s.red = sin(0.01 * (index + (4.0 * M_PI / 3.0))) * 230.0 + 25.0;
	s.green = sin(0.01 * (index + (2.0 * M_PI / 3.0))) * 74.0 + 181.0;
	s.blue = sin(0.01 * (index + (1.0 * M_PI / 3.0))) * 1.0 + 254.0;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	vasarely(double zi)
{
	if (zi > 0)
		return (NOIR);
	return (BLANC);
}

unsigned int	zebra(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLANC);
	else
	{
		s.nu = (i + 5 - log2(log2(sqrt(s.mult)))) / iter_max;
		s.nu_frac = s.nu - (int)s.nu;
		s.red = (int)(0 / s.nu_frac);
		s.green = (int)(255 / s.nu_frac);
		s.blue = (int)(255 / s.nu_frac);
		return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
	}
}
