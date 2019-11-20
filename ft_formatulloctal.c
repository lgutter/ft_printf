/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatulloctal.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:02:41 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 12:47:44 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatulloctal(unsigned long long n, t_info *info)
{
	char	*nb;

	info->sign = 1;
	info->len = ft_nbrlenbase_ull(n, 8);
	nb = ft_ulltoa_base_low(n, 8);
	if (nb == NULL)
		return (-1);
	if ((info->flags & e_hash) != 0 && n == 0)
		info->flags -= e_hash;
	if ((info->flags & e_hash) != 0)
		info->len += 1;
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