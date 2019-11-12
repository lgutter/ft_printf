/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_handle_negint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:16:15 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/12 14:38:47 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_negint(int n, t_info *info)
{
	if (n < 0)
	{
		info->sign = -1;
		if ((info->flags & e_zero) != 0)
		{
			info->writer(info->target, "-", 1);
			n = n * -1;
			info->len = ft_nbrlenbase(n, 10) + 1;
		}
	}
	return (n);
}
