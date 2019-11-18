/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatlowhex.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:50:31 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/18 15:12:56 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatlowhex(t_info *info)
{
	unsigned long long	n;
	char				*nb;

	info->conv = 'x';
	n = va_arg(info->arguments, unsigned long long);
	info->len = ft_nbrlenbase_ull(n, 16);
	nb = ft_ulltoa_base_low(n, 16);
	if ((info->flags & e_hash) != 0)
		info->len += 2;
	if ((info->flags & e_minus) != 0)
		ft_write_order(info, nb, "frw");
	else
	{
		if ((info->flags & e_zero) != 0)
			ft_write_order(info, nb, "fwr");
		else
			ft_write_order(info, nb, "wfr");
	}
	return (0);
}
