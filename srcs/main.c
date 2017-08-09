/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:13:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:59:00 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	print_usage(void)
{
	ft_putstr("Usage : ./fractol [mandelbrot / duobrot / triobrot");
	ft_putendl(" / mandelbar / julia / buffalo / ship / bird]");
	exit(1);
}

static void	do_parsing_fractol(t_p *p, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		p->fractale = MANDELBROT;
	else if (ft_strcmp("julia", argv) == 0)
		p->fractale = JULIA;
	else if (ft_strcmp("duobrot", argv) == 0)
		p->fractale = DUOBROT;
	else if (ft_strcmp("triobrot", argv) == 0)
		p->fractale = TRIOBROT;
	else if (ft_strcmp("ship", argv) == 0)
		p->fractale = SHIP;
	else if (ft_strcmp("bird", argv) == 0)
		p->fractale = BIRD;
	else if (ft_strcmp("buffalo", argv) == 0)
		p->fractale = BUFFALO;
	else if (ft_strcmp("mandelbar", argv) == 0)
		p->fractale = MANDELBAR;
	else
		print_usage();
	get_name_fractal(p);
}

void		get_name_fractal(t_p *p)
{
	if (p->fractale == MANDELBROT)
		p->nfractale = "Mandelbrot";
	if (p->fractale == JULIA)
		p->nfractale = "Julia";
	if (p->fractale == DUOBROT)
		p->nfractale = "Duobrot";
	if (p->fractale == TRIOBROT)
		p->nfractale = "Triobrot";
	if (p->fractale == SHIP)
		p->nfractale = "Burning Ship";
	if (p->fractale == BIRD)
		p->nfractale = "Bird of Prey";
	if (p->fractale == BUFFALO)
		p->nfractale = "Buffalo";
	if (p->fractale == MANDELBAR)
		p->nfractale = "Mandelbar";
}

int			main(int argc, char **argv)
{
	t_p		p;

	if (argc != 2)
		print_usage();
	else
	{
		do_parsing_fractol(&p, argv[1]);
		init(&p);
		do_fractol(&p);
	}
	return (0);
}
