/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_upphex.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 15:25:06 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 12:36:10 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_format_upphex(t_info *info)
{
	unsigned long long n;

	info->conv = 'X';
	if ((info->lenmod & e_hh) != 0)
	{
		n = (unsigned char)va_arg(info->arguments, int);
		return (ft_formatullupphex(n, info));
	}
	if ((info->lenmod & e_h) != 0)
	{
		n = (unsigned short)va_arg(info->arguments, int);
		return (ft_formatullupphex(n, info));
	}
	if ((info->lenmod & e_ll) != 0 || (info->lenmod & e_l) != 0)
	{
		n = va_arg(info->arguments, unsigned long long);
		return (ft_formatullupphex(n, info));
	}
	n = (unsigned int)va_arg(info->arguments, int);
	return (ft_formatullupphex(n, info));
}
