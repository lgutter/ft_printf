/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_options.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:40:28 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/31 16:58:55 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_options(const char *format, t_info *info, int i)
{
	while (format[i] != '\0' && ft_is_conv(format[i]) == 0)
	{
		if (ft_isdigit(format[i] == 1 || format[i] == '.'))
			return (i);
		if (format[i] == '+')
			(info->options) |= e_plus;
		if (format[i] == '-')
			(info->options) |= e_minus;
		if (format[i] == ' ')
			(info->options) |= e_space;
		if (format[i] == '0')
			(info->options) |= e_zero;
		if (format[i] == '#')
			(info->options) |= e_hash;
		i++;
	}
	return (i);
}
