/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:44:32 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/04 13:16:48 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define BLANC 16777215
# define VERT 1817755
# define BLEU_FONCE 4484275
# define VIOLET 6697881
# define BLEU_CLAIR 1684990
# define JAUNE 16044095
# define ORANGE 15890507
# define ROUGE 15869459
# define NOIR 0x000000

# define MANDELBROT 0
# define DUOBROT 1
# define TRIOBROT 2
# define MANDELBAR 3
# define JULIA 4
# define BUFFALO 5
# define SHIP 6
# define BIRD 7

typedef struct	s_color
{
	double		nu;
	double		nu_frac;
	double		red;
	double		green;
	double		blue;
	double		mult;
	int			i;
	int			iter_max;
}				t_color;

void			init_struct_s(t_color *s, int i, double mult, int iter_max);
unsigned int	aqua_blue(int iter_max, int i, double mult);
unsigned int	smooth_aqua_blue(int iter_max, int i, double mult);
unsigned int	shade_of_grey(int i, int iter_max, double mult);
unsigned int	smooth_shade_of_grey(int i, int iter_max, double mult);
unsigned int	rainbow2(int iter_max, int i, double mult);
unsigned int	picots(int iter_max, int i, double squares, double mult);
unsigned int	vasarely(double zi);
unsigned int	zebra(int i, int iter_max, double mult);
unsigned int	grey(int i, int iter_max, double mult);
unsigned int	fire(int i, int iter_max, double mult);
unsigned int	blue(int i, int iter_max, double mult);

#endif
