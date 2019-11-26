/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_floats.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:52:44 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/26 10:52:51 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_format_floats(t_info *info)
{
	long double	f;

	info->conv = 'f';
	if (info->precfound < 0)
		info->precision = 6;
	if ((info->lenmod & e_L) != 0)
	{
		f = (long double)va_arg(info->arguments, long double);
		return (ft_formatlongdfloats(info, f));
	}
	f = (long double)va_arg(info->arguments, double);
	return (ft_formatlongdfloats(info, f));
}
