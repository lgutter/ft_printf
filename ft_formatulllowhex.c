/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatulllowhex.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:50:31 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 12:15:13 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatulllowhex(unsigned long long n, t_info *info)
{
	char				*nb;

	info->sign = 1;
	info->len = ft_nbrlenbase_ull(n, 16);
	nb = ft_ulltoa_base_low(n, 16);
	nb = ft_precision_int(info, nb);
	if (nb == NULL)
		return (-1);
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
