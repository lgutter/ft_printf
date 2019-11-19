/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatunsigneddecimal.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 09:54:43 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/19 09:57:38 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatunsigneddecimal(t_info *info)
{
	unsigned long long	n;

	info->conv = 'd';
	if ((info->lenmod & e_hh) != 0)
	{
		n = (unsigned char)va_arg(info->arguments, unsigned int);
	}
	else if ((info->lenmod & e_h) != 0)
	{
		n = (unsigned short)va_arg(info->arguments, unsigned int);
	}
	else if ((info->lenmod & e_ll) != 0 || (info->lenmod & e_l) != 0)
	{
		n = va_arg(info->arguments, unsigned long long);
	}
	else
	{
		n = (unsigned long long)va_arg(info->arguments, unsigned int);
	}
	return (ft_formatunsignedlonglong(n, info));
}
