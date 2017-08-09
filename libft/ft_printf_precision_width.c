/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:54:47 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/22 15:33:24 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	check_precision(t_format **current)
{
	size_t		size;
	size_t		precision;
	char		*temp;

	size = 0;
	precision = 0;
	temp = NULL;
	size = ft_strlen_secure((*current)->result);
	if ((*current)->precision && (*current)->type[0] != 'C')
	{
		precision = (size_t)ft_atoi((*current)->precision);
		preci2(current, precision, size, temp);
		if (ft_strchr((*current)->result, '-'))
			preci3(current, temp);
	}
}

void	check_width2(t_format **current, size_t width)
{
	size_t	i;
	size_t	size;
	int		nb;

	i = 0;
	size = 0;
	nb = 0;
	nb = ft_atoi((*current)->result);
	if ((*current)->flag && ft_strchr((*current)->flag, '0'))
	{
		size = (size_t)ft_atoi((*current)->precision);
		if (width > size && nb >= 0)
		{
			i = 0;
			while (width > size)
			{
				(*current)->result[i] = ' ';
				i++;
				size++;
			}
		}
	}
}

void	check_width_sup_size(t_format **current, size_t size, size_t width)
{
	char	*temp;
	size_t	i;
	size_t	j;

	temp = NULL;
	i = 0;
	j = 0;
	temp = ft_strdup((*current)->result);
	free((*current)->result);
	(*current)->result = ft_fill_with(width - 1, ' ');
	i = width - size;
	while (i < width)
		(*current)->result[i++] = temp[j++];
	free(temp);
}

void	check_width(t_format **current)
{
	size_t		size;
	size_t		width;

	width = 0;
	size = ft_strlen_secure((*current)->result);
	if ((*current)->width)
	{
		width = (size_t)ft_atoi((*current)->width);
		if (((*current)->type[0] == 'c' || (*current)->type[0] == 'C')
				&& (*current)->result[0] == '\0')
			width--;
		if (width > size)
			check_width_sup_size(current, size, width);
	}
	if ((*current)->precision)
		check_width2(current, width);
}
