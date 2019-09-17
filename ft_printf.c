/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:40:08 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/17 09:47:52 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			i = i + 2;
			ft_putchar(va_arg(arg, int));
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(arg);
	return (0);
}
