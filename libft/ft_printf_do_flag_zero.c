/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flag_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:25:32 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/22 12:05:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	do_flag_zero3(t_format **current, int i, int j, char **temp)
{
	if ((*current)->result[j + 1] == '+')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = '+';
	}
	else if ((*current)->result[j + 1] == ' ')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = ' ';
	}
	else if ((*current)->result[j + 1] == '-')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = '-';
	}
}

void	do_flag_zero2(t_format **current, char **temp, int width_result, int i)
{
	int		j;

	width_result = ft_strlen_secure((*current)->result);
	j = width_result;
	if (ft_strchr((*current)->flag, '#'))
		if ((*current)->type[0] == 'x' || (*current)->type[0] == 'X')
			width_result = width_result - 2;
	while (width_result >= 0)
	{
		(*temp)[i--] = (*current)->result[j--];
		width_result--;
	}
	do_flag_zero3(current, i, j, temp);
	if (ft_strchr((*current)->flag, '#'))
	{
		if ((*current)->type[0] == 'x' || (*current)->type[0] == 'X')
		{
			if ((*current)->type[0] == 'x')
				(*temp)[1] = 'x';
			else
				(*temp)[1] = 'X';
		}
	}
	ft_swap_adress(&(*current)->result, temp);
	free(*temp);
}

void	do_flag_zero(t_format **current)
{
	int		width;
	char	*temp;
	int		i;
	int		width_result;

	if ((*current)->type[0] != 's' || (*current)->type[0] != 'S' ||
			(*current)->type[0] != 'p' || (*current)->type[0] != 'c' ||
			(*current)->type[0] != 'C')
	{
		i = 0;
		width_result = 0;
		if ((*current)->width)
		{
			width = ft_atoi((*current)->width);
			if (width > (int)ft_strlen((*current)->result))
			{
				temp = ft_strnew(width);
				while (i < width)
					temp[i++] = '0';
				do_flag_zero2(current, &temp, width_result, i);
			}
		}
	}
}
