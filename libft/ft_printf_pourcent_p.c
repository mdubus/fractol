/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/23 10:36:28 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printf_pourcent(t_format **current)
{
	char	*c;

	c = ft_strnew(1);
	c[0] = '%';
	c[1] = '\0';
	(*current)->result = c;
}

void	ft_printf_p2(t_format **current, unsigned long int value)
{
	char	*temp;
	int		i;
	int		j;

	i = 2;
	j = 0;
	(*current)->result = ft_itoa_b_ullint(value, 16);
	if ((*current)->result[0] != '0')
	{
		temp = ft_strdup((*current)->result);
		free((*current)->result);
		(*current)->result = ft_strnew(ft_strlen_secure(temp) + 1);
		(*current)->result[0] = '0';
		(*current)->result[1] = 'x';
		while (temp[j] != '\0')
			(*current)->result[i++] = temp[j++];
		free(temp);
	}
}

void	ft_printf_p(t_format **current, va_list ap)
{
	unsigned long int		value;

	value = va_arg(ap, unsigned long int);
	if (value == 0)
	{
		(*current)->result = ft_strnew(3);
		(*current)->result[0] = '0';
		(*current)->result[1] = 'x';
		(*current)->result[2] = '0';
	}
	else
		ft_printf_p2(current, value);
}
