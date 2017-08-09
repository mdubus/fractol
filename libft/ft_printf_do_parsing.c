/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:43 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/26 11:28:06 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	do_parsing_flag(char *str, t_format **current, int i)
{
	int		j;

	j = 0;
	if (is_flag(&str[i]))
	{
		while (is_flag(&str[i + j]))
			j++;
		(*current)->flag = ft_strnew((size_t)j);
		j = 0;
		while (is_flag(&str[i]))
			(*current)->flag[j++] = str[i++];
		return (j);
	}
	else
		(*current)->flag = NULL;
	return (0);
}

int	do_parsing_width(char *str, t_format **current, int i)
{
	int		j;

	j = 0;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i + j]))
			j++;
		(*current)->width = ft_strnew((size_t)j);
		j = 0;
		while (ft_isdigit(str[i]))
			(*current)->width[j++] = str[i++];
		return (j);
	}
	else
		(*current)->width = NULL;
	return (0);
}

int	do_parsing_precision(char *str, t_format **current, int i, int j)
{
	if (str[i] == '.')
	{
		i++;
		if (is_type(&str[i]))
		{
			(*current)->precision = ft_strnew(1);
			(*current)->precision[0] = '.';
			return (1);
		}
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i + j]))
				j++;
			(*current)->precision = ft_strnew((size_t)j);
			j = 0;
			while (ft_isdigit(str[i]))
				(*current)->precision[j++] = str[i++];
			return (j + 1);
		}
	}
	else
		(*current)->precision = NULL;
	return (0);
}

int	do_parsing_modifier(char *str, t_format **current, int i)
{
	int		j;

	j = 0;
	if (is_modifier(&str[i]))
	{
		while (is_modifier(&str[i + j]))
			j++;
		(*current)->modifier = ft_strnew((size_t)j);
		j = 0;
		while (is_modifier(&str[i]))
			(*current)->modifier[j++] = str[i++];
		return (j);
	}
	else
		(*current)->modifier = NULL;
	return (0);
}

int	do_parsing_type(char *str, t_format **current, int i)
{
	(*current)->type = ft_strnew(1);
	(*current)->type[0] = str[i];
	return (1);
}
