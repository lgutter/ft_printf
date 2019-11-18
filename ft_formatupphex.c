/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatupphex.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:03:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/18 18:11:33 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatupphex(t_info *info)
{
	unsigned long long	n;
	char				*nb;

	info->conv = 'X';
	n = va_arg(info->arguments, unsigned long long);
	info->len = ft_nbrlenbase_ull(n, 16);
	nb = ft_ulltoa_base_upp(n, 16);
	if ((info->flags & e_hash) != 0 && n == 0)
		info->flags -= e_hash;
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
