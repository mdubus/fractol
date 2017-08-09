/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:17:42 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/22 10:45:31 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	do_flag_minus(t_format **current)
{
	int		width;
	char	*temp;
	int		i;

	i = 0;
	if ((*current)->width)
	{
		width = ft_atoi((*current)->width);
		if (width > (int)ft_strlen((*current)->result))
		{
			temp = ft_strnew(width);
			temp = ft_strcpy(temp, ((*current)->result));
			i = ft_strlen((*current)->result);
			while (i < width)
				temp[i++] = ' ';
			ft_swap_adress(&(*current)->result, &temp);
			free(temp);
		}
	}
}

void	do_flag_space(t_format **current)
{
	int		result;
	char	*temp;
	int		i;
	int		j;
	int		width;

	i = 0;
	j = 0;
	width = ft_strlen_secure((*current)->result);
	result = ft_atoi((*current)->result);
	if ((*current)->type[0] == 'd' || (*current)->type[0] == 'D' ||
			(*current)->type[0] == 'i')
	{
		if (result >= 0)
			width++;
		temp = ft_strnew(width);
		if (result >= 0)
			temp[i++] = ' ';
		while ((*current)->result[j] != '\0')
			temp[i++] = (*current)->result[j++];
		ft_swap_adress(&(*current)->result, &temp);
		free(temp);
	}
}

void	do_flag_plus(t_format **current)
{
	int		result;
	char	*temp;
	int		i;
	int		j;
	int		width;

	i = 0;
	j = 0;
	width = ft_strlen_secure((*current)->result);
	result = ft_atoi((*current)->result);
	if ((*current)->type[0] == 'd' || (*current)->type[0] == 'D' ||
			(*current)->type[0] == 'i')
	{
		if (result >= 0)
			width++;
		temp = ft_strnew(width);
		if (result >= 0)
			temp[i++] = '+';
		while ((*current)->result[j] != '\0')
			temp[i++] = (*current)->result[j++];
		ft_swap_adress(&(*current)->result, &temp);
		free(temp);
	}
}
