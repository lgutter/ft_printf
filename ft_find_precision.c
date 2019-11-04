/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_precision.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:31:26 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/01 15:41:45 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_precision(const char *format, t_info *info, int i)
{
	size_t nb;

	nb = 0;
	if (format[i] == '.')
	{
		i++;
		nb = ft_atoi(&format[i]);
		info->precision = nb;
		i += ft_nbrlenbase(nb, 10);
	}
	return (i);
}
