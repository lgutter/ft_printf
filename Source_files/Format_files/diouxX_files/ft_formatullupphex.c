/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatullupphex.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 15:24:27 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/29 14:56:53 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatullupphex(unsigned long long n, t_info *info)
{
	char				*nb;

	info->sign = 1;
	nb = ft_ulltoa_base_upp(n, 16);
	if (info->precfound > 0)
		nb = ft_precision_int(info, nb);
	if (nb != NULL)
	{
		if ((info->flags & e_hash) != 0 && n == 0)
			info->flags -= e_hash;
		info->len = ft_strlen(nb) + (((info->flags & e_hash) != 0) ? 2 : 0);
		if ((info->flags & e_minus) != 0)
			ft_write_order(info, nb, "frw");
		else
		{
			if ((info->flags & e_zero) != 0)
				ft_write_order(info, nb, "fwr");
			else
				ft_write_order(info, nb, "wfr");
		}
		free(nb);
		return (0);
	}
	return (-1);
}
