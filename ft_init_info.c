/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:50:09 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/14 18:07:10 by lgutter       ########   odam.nl         */
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
	info->writer = &ft_putstr;
	while (format[i] == ' ' && format[i] != '\0')
	{
		(info->options) = 128;
		i++;
	}
	return (i);
}
