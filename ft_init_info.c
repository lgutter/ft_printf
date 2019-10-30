/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:50:09 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/30 15:10:52 by ivan-tey      ########   odam.nl         */
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
	while (format[i] != '\0' && ft_is_conv(format[i]) == 1)
	{
		if (format[i] == '\0')
			return (i);
		if (format[i] == ' ')
			(info->options) |= e_space;
		i++;
	}
	return (i);
}
