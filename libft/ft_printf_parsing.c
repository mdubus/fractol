/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/02/12 11:15:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	do_parsing(char *str, int nb_arg, t_format **current, va_list ap)
{
	int			i;
	t_format	*begin;

	i = 0;
	*current = malloc(sizeof(t_format));
	begin = *current;
	while (nb_arg > 0)
	{
		if (str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			i = do_parsing2(str, current, i);
			recup_argument(current);
			put_result(current, ap);
			if (nb_arg > 1)
			{
				(*current)->next = malloc(sizeof(t_format));
				*current = (*current)->next;
			}
			nb_arg--;
		}
	}
	(*current)->next = NULL;
	(*current) = begin;
}

int		do_parsing2(char *str, t_format **current, int i)
{
	int	j;

	j = 0;
	i++;
	i = i + (do_parsing_flag(str, &(*current), i));
	i = i + (do_parsing_width(str, &(*current), i));
	i = i + (do_parsing_precision(str, &(*current), i, j));
	i = i + (do_parsing_modifier(str, &(*current), i));
	i = i + (do_parsing_type(str, &(*current), i));
	return (i);
}
