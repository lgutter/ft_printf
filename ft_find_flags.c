/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:25:51 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/01 12:25:53 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_flags(const char *format, t_info *info, int i)
{
	while (format[i] != '\0' && ft_is_conv(format[i]) == 0)
	{
		if (ft_isdigit(format[i]) == 1 || format[i] == '.')
			return (i);
		if (format[i] == '+')
			(info->flags) |= e_plus;
		if (format[i] == '-')
			(info->flags) |= e_minus;
		if (format[i] == ' ')
			(info->flags) |= e_space;
		if (format[i] == '0')
			(info->flags) |= e_zero;
		if (format[i] == '#')
			(info->flags) |= e_hash;
		i++;
	}
	return (i);
}
