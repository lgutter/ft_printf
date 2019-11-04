/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_width.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:57:09 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/01 16:44:19 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_find_width(const char *format, t_info *info, int i)
{
	size_t	nb;

	nb = 0;
	nb = ft_atoi(&format[i]);
	info->width = nb;
	if (nb > 0)
		i += ft_nbrlenbase(nb, 10);
	return (i);
}
