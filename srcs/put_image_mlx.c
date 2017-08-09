/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 18:32:52 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:28:57 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_text(t_p *p)
{
	mlx_string_put(p->mlx_ptr, p->win, 20, 20, 0xFFFFFF, "fractale : f");
	mlx_string_put(p->mlx_ptr, p->win, 20, 40, 0xFFFFFF, "iter : { }");
	mlx_string_put(p->mlx_ptr, p->win, 20, 60, 0xFFFFFF, "zoom : + -");
	mlx_string_put(p->mlx_ptr, p->win, 20, 80, 0xFFFFFF, "reinit : r");
	mlx_string_put(p->mlx_ptr, p->win, 20, 100, 0xFFFFFF, "palette : p");
	mlx_string_put(p->mlx_ptr, p->win, 310, 740, 0x000000, "Fractale : ");
}

void		put_image_mlx(t_p *p)
{
	char	*mx;
	char	*my;
	char	*iter_max;

	mx = ft_itoa(p->mx);
	my = ft_itoa(p->my);
	iter_max = ft_itoa(p->iter_max);
	mlx_put_image_to_window(p->mlx_ptr, p->win, p->img_ptr, 0, 0);
	put_text(p);
	mlx_string_put(p->mlx_ptr, p->win, 420, 740, 0x000000, p->nfractale);
	mlx_string_put(p->mlx_ptr, p->win, 270, 770, 0xFFFFFF, "Iter : ");
	mlx_string_put(p->mlx_ptr, p->win, 335, 770, 0xFFFFFF, iter_max);
	mlx_string_put(p->mlx_ptr, p->win, 375, 770, 0xFFFFFF, "| x : ");
	mlx_string_put(p->mlx_ptr, p->win, 430, 770, 0xFFFFFF, mx);
	mlx_string_put(p->mlx_ptr, p->win, 480, 770, 0xFFFFFF, "| y : ");
	mlx_string_put(p->mlx_ptr, p->win, 535, 770, 0xFFFFFF, my);
	mlx_string_put(p->mlx_ptr, p->win, 720, 770, 0xFFFFFF, "mdubus");
	if (p->fractale == JULIA)
		mlx_string_put(p->mlx_ptr, p->win, 20, 120, 0xFFFFFF, "pause : space");
	free(mx);
	free(my);
	free(iter_max);
}
