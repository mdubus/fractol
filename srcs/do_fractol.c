/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:59:31 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:59:32 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	do_fractol(t_p *p)
{
	init_limits_fractale(p);
	put_fractale(p);
	mlx_mouse_hook(p->win, &mouse_events, p);
	mlx_expose_hook(p->win, &expose, p);
	mlx_hook(p->win, KeyPress, KeyPressMask, &key_press, p);
	mlx_hook(p->win, KeyRelease, KeyReleaseMask, &key_release, p);
	mlx_hook(p->win, DestroyNotify, (1L << 17), &red_cross, p);
	mlx_hook(p->win, MotionNotify, (1L << 6), &move_julia, p);
	mlx_loop_hook(p->mlx_ptr, &loop_key, p);
	mlx_loop(p->mlx_ptr);
}
