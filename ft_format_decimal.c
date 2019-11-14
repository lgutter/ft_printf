/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_decimal.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:13:13 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/13 14:37:54 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatdecimal(t_info *info)
{
	info->conv = 'd';
	if ((info->lenmod & e_hh) != 0)
	{
		return (ft_formatbyteint(info));
	}
	if ((info->lenmod & e_h) != 0)
	{
		return (ft_formatshort(info));
	}
	if ((info->lenmod & e_l) != 0)
	{
		return (ft_formatlong(info));
	}
	if ((info->lenmod & e_ll) != 0)
	{
		return (ft_formatlonglong(info));
	}
	return (ft_formatint(info));
}
