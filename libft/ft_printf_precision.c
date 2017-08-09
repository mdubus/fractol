/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:42:54 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/19 16:44:22 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	preci21(char *temp, t_format **current, size_t i, size_t precision)
{
	temp = ft_strdup((*current)->result);
	free((*current)->result);
	(*current)->result = ft_strnew(precision);
	while (i < precision)
	{
		(*current)->result[i] = temp[i];
		i++;
	}
}

void	preci22(char *temp, t_format **current, size_t precision, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	temp = ft_strdup((*current)->result);
	free((*current)->result);
	(*current)->result = ft_fill_with(precision - 1, '0');
	i = precision - size;
	while (i < precision)
		(*current)->result[i++] = temp[j++];
	free(temp);
}

void	preci2(t_format **current, size_t precision, size_t size, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (((*current)->type[0] != 's' && (*current)->type[0] != 'S' &&
				(*current)->type[0] != 'c') && precision > size)
		preci22(temp, current, precision, size);
	else if (precision < size && ((*current)->type[0] == 's' ||
				(*current)->type[0] == 'S'))
		preci21(temp, current, i, precision);
	else if (((*current)->precision[0] == '.' ||
				(*current)->precision[0] == '0') &&
			((*current)->result[0] == '0' || (*current)->result == NULL))
	{
		free((*current)->result);
		(*current)->result = ft_strnew(0);
	}
}

void	preci3(t_format **current, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_replace_char_with_char_in_str(&(*current)->result, '-', '0');
	temp = ft_strdup((*current)->result);
	free((*current)->result);
	(*current)->result = ft_strnew(ft_strlen_secure(temp + 1));
	i = ft_strlen_secure(temp) + 1;
	j = i - 1;
	while (i > 0)
		(*current)->result[i--] = temp[j--];
	(*current)->result[0] = '-';
}
