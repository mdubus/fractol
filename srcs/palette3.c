/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:00:19 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 16:00:20 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GPU
# include "../includes/fractol.h"
#endif

void			init_struct_s(t_color *s, int i, double mult, int iter_max)
{
	s->mult = mult;
	s->i = i;
	s->nu = 0;
	s->nu_frac = 0;
	s->red = 0;
	s->green = 0;
	s->blue = 0;
	s->iter_max = iter_max;
}

unsigned int	grey(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (NOIR);
	s.nu = (i + 3 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(185 * s.nu_frac + 70 * s.nu_frac);
	s.green = (int)(55 * s.nu_frac + 200 * s.nu_frac);
	s.blue = (int)(25 * s.nu_frac + 230 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	fire(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (NOIR);
	s.nu = (i + 3 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(185 * s.nu_frac + 70 * s.nu_frac);
	s.green = (int)(55 * s.nu_frac);
	s.blue = (int)(25 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	blue(int i, int iter_max, double mult)
{
	t_color	s;

	init_struct_s(&s, i, mult, iter_max);
	if (i == iter_max)
		return (NOIR);
	s.nu = (i + 3 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(255 * s.nu_frac - 221 * s.nu_frac);
	s.green = (int)(255 * s.nu_frac - 88 * s.nu_frac);
	s.blue = (int)(255 * s.nu_frac - 15 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}
