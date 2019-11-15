/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatpointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:33:13 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/15 13:46:36 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatpointer(t_info *info)
{
	unsigned long long	p;
	char				*pt;

	info->conv = 'p';
	p = va_arg(info->arguments, unsigned long long);
	info->len = ft_nbrlenbase_ull(p, 16) + 2;
	pt = ft_ulltoa_base_low(p, 16);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, "0x", 0);
		info->writer(info->target, pt, 0);
		ft_check_width(info, info->len);
		return (0);
	}
	if ((info->flags & e_zero) != 0)
		info->writer(info->target, "0x", 0);
	ft_check_width(info, info->len);
	if ((info->flags & e_zero) == 0)
		info->writer(info->target, "0x", 0);
	info->writer(info->target, pt, 0);
	return (0);
}
