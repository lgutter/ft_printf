/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_octal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 17:24:10 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 17:28:41 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_format_octal(t_info *info)
{
	unsigned long long n;

	info->conv = 'o';
	if ((info->lenmod & e_hh) != 0)
	{
		n = (unsigned char)va_arg(info->arguments, int);
		return (ft_formatulloctal(n, info));
	}
	if ((info->lenmod & e_h) != 0)
	{
		n = (unsigned short)va_arg(info->arguments, int);
		return (ft_formatulloctal(n, info));
	}
	if ((info->lenmod & e_ll) != 0 || (info->lenmod & e_l) != 0)
	{
		n = va_arg(info->arguments, unsigned long long);
		return (ft_formatulloctal(n, info));
	}
	n = (unsigned long long)va_arg(info->arguments, int);
	return (ft_formatulloctal(n, info));
}
