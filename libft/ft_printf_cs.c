/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:47:07 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/26 11:15:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printf_c2(va_list ap, t_format **current, char *c, char *temp3)
{
	char	temp2;

	temp2 = (char)va_arg(ap, int);
	if (!temp2 || temp2 == 0)
		(*current)->result = ft_strnew(1);
	else if (temp2 == '0')
	{
		(*current)->result = ft_strnew(1);
		(*current)->result[0] = '0';
	}
	else
	{
		c[0] = *ft_strdup(&temp2);
		c[1] = '\0';
		temp3 = ft_strdup(c);
		(*current)->result = ft_strdup(temp3);
		free(temp3);
	}
}

void	ft_printf_c(t_format **current, va_list ap)
{
	char	*c;
	int		temp;
	char	*temp3;

	temp = 0;
	temp3 = NULL;
	c = ft_strnew(1);
	if (((*current)->modifier && (*current)->modifier[0] == 'l') ||
			(*current)->type[0] == 'C')
	{
		temp = va_arg(ap, int);
		temp3 = ft_getwchar(temp);
		(*current)->result = ft_strdup(temp3);
		free(temp3);
	}
	else
		ft_printf_c2(ap, current, c, temp3);
	free(c);
}

void	ft_printf_s2(t_format **current, va_list ap, wchar_t *str, char *str2)
{
	str = va_arg(ap, wchar_t*);
	if (str == NULL)
		(*current)->result = ft_strdup("(null)");
	else if (str[0] == 0)
		(*current)->result = ft_strnew(1);
	else
	{
		str2 = ft_getwstring(str);
		(*current)->result = str2;
	}
}

void	ft_printf_s(t_format **current, va_list ap)
{
	wchar_t	*str;
	char	*str2;
	char	*str3;

	str = NULL;
	str2 = NULL;
	if (((*current)->modifier && (*current)->modifier[0] == 'l') ||
			(*current)->type[0] == 'S')
		ft_printf_s2(current, ap, str, str2);
	else
	{
		str3 = (char*)va_arg(ap, void*);
		if (str3 != NULL)
			(*current)->result = ft_strdup(str3);
		else
			(*current)->result = ft_strdup("(null)");
	}
}
