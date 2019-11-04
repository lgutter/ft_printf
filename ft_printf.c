/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:40:08 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/04 17:05:21 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	t_info		info;

	info.writer = &ft_writer;
	va_start(info.arguments, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += ft_process_conversion(&format[i], &info);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(info.arguments);
	return (0);
}
