/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_negint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:16:15 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/13 14:24:54 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format_negint(int n, t_info *info)
{
	char *nb;

	info->sign = -1;
	if ((info->flags & e_zero) != 0)
	{
		info->writer(info->target, "-", 1);
		info->len = ft_nbrlenbase(n, 10);
		n = n * -1;
	}
	else
		info->len = ft_nbrlenbase(n, 10);
	nb = ft_itoa_base(n, 10);
	if (nb == NULL)
		return (-1);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, nb, 0);
		ft_check_width(info, info->len);
	}
	else
	{
		ft_check_width(info, info->len);
		info->writer(info->target, nb, 0);
	}
	return (0);
}
