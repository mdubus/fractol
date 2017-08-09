/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_recup_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:48 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/23 10:17:51 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	recup_argument2(t_format **current, int j, int i)
{
	if ((*current)->precision != NULL)
	{
		j = 0;
		if ((*current)->precision[0] != '.')
			(*current)->argument[i++] = '.';
		while ((*current)->precision[j] != '\0')
			(*current)->argument[i++] = (*current)->precision[j++];
	}
	if ((*current)->modifier != NULL)
	{
		j = 0;
		while ((*current)->modifier[j] != '\0')
			(*current)->argument[i++] = (*current)->modifier[j++];
	}
	if ((*current)->type != NULL)
	{
		j = 0;
		while ((*current)->type[j] != '\0')
			(*current)->argument[i++] = (*current)->type[j++];
	}
}

void	recup_argument(t_format **current)
{
	size_t	length;
	int		i;
	int		j;

	i = 1;
	j = 0;
	length = ft_strlen_secure((*current)->flag) +
		ft_strlen_secure((*current)->width) +
		ft_strlen_secure((*current)->precision) +
		ft_strlen_secure((*current)->modifier) +
		ft_strlen_secure((*current)->type);
	(*current)->argument = ft_strnew(length + 2);
	(*current)->argument[0] = '%';
	if ((*current)->flag != NULL)
	{
		while ((*current)->flag[j] != '\0')
			(*current)->argument[i++] = (*current)->flag[j++];
	}
	if ((*current)->width != NULL)
	{
		j = 0;
		while ((*current)->width[j] != '\0')
			(*current)->argument[i++] = (*current)->width[j++];
	}
	recup_argument2(current, j, i);
}
