/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:50:09 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/30 13:14:18 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_info(const char *format, t_info *info)
{
	int i;

	i = 1;
	info->options = 0;
	info->width = 0;
	info->precision = 0;
	while (format[i] != '\0' && format[i] != 'c' && format[i] != 's')
	{
		if (format[i] == '\0')
			return (i);
		if (format[i] == ' ')
			(info->options) |= e_space;
		i++;
	}
	return (i);
}
