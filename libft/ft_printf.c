/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:43:22 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/26 11:24:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_printf4(t_format **current, size_t *size)
{
	if (((*current)->type[0] == 'c' || (*current)->type[0] == 'C')
				&& (*current)->result[0] == '\0')
	{
		ft_putchar('\0');
		(*size)++;
	}
	else if ((*current)->type[0] == 'c' || (*current)->type[0] == 'C')
	{
		if ((*current)->width)
			*size = ft_atoi((*current)->width);
		else
			*size = ft_strlen_secure((*current)->result);
	}
}

size_t		ft_printf3(char **str, t_format **current, int *i, int *nb_arg)
{
	int			j;
	size_t		size;
	t_format	*temp;

	j = 0;
	size = 0;
	while ((*str)[*i] != '%')
	{
		ft_putchar((*str)[(*i)++]);
		size++;
	}
	while ((*current)->result[j] != '\0')
	{
		ft_putchar((*current)->result[j++]);
		size++;
	}
	ft_printf4(current, &size);
	*i = *i + ft_strlen((*current)->argument);
	(*nb_arg)--;
	j = 0;
	free_current_list(&(*current));
	temp = *current;
	*current = (*current)->next;
	free(temp);
	return (size);
}

void		ft_printf2(char **str, size_t *size, t_format **current, va_list ap)
{
	int		nb_arg;
	int		i;

	i = 0;
	nb_arg = ft_count_args_printf(*str, '%');
	*str = ft_colors(*str);
	if (nb_arg > 0)
		do_parsing(*str, nb_arg, current, ap);
	while (nb_arg > 0)
		*size = *size + ft_printf3(str, current, &i, &nb_arg);
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '%')
		{
			ft_putchar('\0');
			i++;
			while ((*str)[i] == ' ')
				i++;
		}
		else
		{
			ft_putchar((*str)[i++]);
			(*size)++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*str;
	size_t			size;
	t_format		*current;

	size = 0;
	current = NULL;
	str = ft_strdup(format);
	va_start(ap, format);
	ft_printf2(&str, &size, &current, ap);
	free(str);
	va_end(ap);
	return ((int)size);
}
