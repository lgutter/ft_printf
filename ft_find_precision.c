/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_precision.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:31:26 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 11:52:08 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_precision(const char *format, t_info *info, int i)
{
	size_t nb;

	nb = 0;
	if (format[i] == '.')
	{
		info->precfound = 1;
		i++;
		nb = ft_atoi(&format[i]);
		info->precision = nb;
		if (info->flags & e_zero)
		{
			info->flags -= e_zero;
		}
		if (ft_isdigit(format[i]) == 1)
		{
			i += ft_nbrlenbase(nb, 10);
		}
	}
	else
	{
		info->precfound = -1;
	}
	return (i);
}
