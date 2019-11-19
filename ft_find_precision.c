/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_precision.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:31:26 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 15:26:22 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_precision(const char *format, t_info *info, int i)
{
	int	asterisk;

	asterisk = 0;
	if (format[i] == '.')
	{
		info->precfound = 1;
		i++;
		if (format[i] == '*')
		{
			asterisk = va_arg(info->arguments, int);
			info->precision = asterisk >= 0 ? asterisk : 1;
			i++;
		}
		else
			info->precision = ft_atoi(&format[i]);
		if (info->flags & e_zero)
			info->flags -= e_zero;
		if (ft_isdigit(format[i]) == 1)
			i += ft_nbrlenbase(info->precision, 10);
	}
	else
		info->precfound = -1;
	return (i);
}
