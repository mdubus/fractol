/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flag_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:41:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/22 12:56:34 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	do_flag_hash(t_format **current)
{
	if ((*current)->type[0] == 'o' || (*current)->type[0] == 'O')
		do_flag_hash_with_o(current);
	else if ((*current)->type[0] == 'x' || (*current)->type[0] == 'X')
		do_flag_hash_with_x(current);
}

void	do_flag_hash_with_o(t_format **current)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	j = 0;
	if ((*current)->result)
	{
		if ((*current)->result[0] != '0')
		{
			temp = ft_strnew(ft_strlen_secure((*current)->result) + 1);
			temp[i++] = '0';
			while ((*current)->result[j] != '\0')
			{
				temp[i++] = (*current)->result[j++];
			}
			ft_swap_adress(&(*current)->result, &temp);
			free(temp);
		}
	}
}

void	do_flag_hash_with_x(t_format **current)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	j = 0;
	if ((*current)->result)
	{
		if ((*current)->result[0] != '0' && (*current)->result[0] != 0)
		{
			temp = ft_strnew(ft_strlen_secure((*current)->result) + 1);
			temp[i++] = '0';
			temp[i++] = 'x';
			while ((*current)->result[j] != '\0')
			{
				temp[i++] = (*current)->result[j++];
			}
			ft_swap_adress(&(*current)->result, &temp);
			free(temp);
		}
		if ((*current)->type[0] == 'X')
			ft_strtoupper(&(*current)->result);
	}
}
