/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:19:09 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/22 10:37:47 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	flag_hash(t_format **current)
{
	do_flag_hash(current);
	if (ft_strchr((*current)->flag, '-'))
		do_flag_minus(current);
	else if (ft_strchr((*current)->flag, '0'))
		do_flag_zero(current);
}

void	flag_zero2(t_format **current)
{
	if (ft_strchr((*current)->flag, ' '))
	{
		do_flag_space(current);
		do_flag_zero(current);
	}
	else if (ft_strchr((*current)->flag, '-'))
		do_flag_minus(current);
	else if (ft_strchr((*current)->flag, '+'))
	{
		do_flag_plus(current);
		do_flag_zero(current);
	}
	else
		do_flag_zero(current);
}

void	flag_zero(t_format **current)
{
	if (ft_strchr((*current)->flag, '-') && ft_strchr((*current)->flag, '+'))
	{
		do_flag_plus(current);
		do_flag_minus(current);
	}
	else if (ft_strchr((*current)->flag, ' ') &&
			ft_strchr((*current)->flag, '+'))
	{
		do_flag_plus(current);
		do_flag_zero(current);
	}
	else if (ft_strchr((*current)->flag, ' ') &&
			ft_strchr((*current)->flag, '-'))
	{
		do_flag_space(current);
		do_flag_minus(current);
	}
	else
		flag_zero2(current);
}

void	flag_minus(t_format **current)
{
	if (ft_strchr((*current)->flag, '+'))
	{
		do_flag_plus(current);
		do_flag_minus(current);
	}
	else if (ft_strchr((*current)->flag, ' '))
	{
		do_flag_space(current);
		do_flag_minus(current);
	}
	else
		do_flag_minus(current);
}

void	check_flags(t_format **current)
{
	if ((*current)->flag)
	{
		if (ft_strchr((*current)->flag, '#'))
			flag_hash(&(*current));
		else if (ft_strchr((*current)->flag, '0'))
			flag_zero(&(*current));
		else if (ft_strchr((*current)->flag, '-'))
			flag_minus(&(*current));
		else if (ft_strchr((*current)->flag, '+'))
			do_flag_plus(&(*current));
		else if (ft_strchr((*current)->flag, ' '))
			do_flag_space(&(*current));
	}
}
