/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/02/12 11:15:34 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	put_result2(t_format **current, va_list ap)
{
	if ((*current)->type[0] == 'c' || (*current)->type[0] == 'C')
		ft_printf_c(&(*current), ap);
	if ((*current)->type[0] == 's' || (*current)->type[0] == 'S')
		ft_printf_s(&(*current), ap);
	if ((*current)->type[0] == '%')
		ft_printf_pourcent(&(*current));
	if ((*current)->type[0] == 'p')
		ft_printf_p(&(*current), ap);
	if ((*current)->result != NULL)
	{
		check_precision(current);
		check_flags(current);
		check_width(current);
	}
}

void	put_result(t_format **current, va_list ap)
{
	if ((*current)->flag && ft_strchr((*current)->flag, '*'))
		(*current)->width = ft_itoa(va_arg(ap, int));
	if ((*current)->type[0] == 'd' || (*current)->type[0] == 'i' ||
			(*current)->type[0] == 'D')
		ft_printf_di(&(*current), ap);
	if ((*current)->type[0] == 'o' || (*current)->type[0] == 'O')
		ft_printf_o(&(*current), ap);
	if ((*current)->type[0] == 'u' || (*current)->type[0] == 'U')
		ft_printf_u(&(*current), ap);
	if ((*current)->type[0] == 'x')
		ft_printf_x(&(*current), ap);
	if ((*current)->type[0] == 'X')
		ft_printf_x_upper(&(*current), ap);
	put_result2(current, ap);
}

void	free_current_list(t_format **current)
{
	if ((*current)->flag != NULL)
		free((*current)->flag);
	if ((*current)->width != NULL)
		free((*current)->width);
	if ((*current)->precision != NULL)
		free((*current)->precision);
	if ((*current)->modifier != NULL)
		free((*current)->modifier);
	if ((*current)->type != NULL)
		free((*current)->type);
	if ((*current)->result != NULL)
		free((*current)->result);
	if ((*current)->argument != NULL)
		free((*current)->argument);
}
