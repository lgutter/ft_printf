/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatpointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:33:13 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/13 15:05:41 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatpointer(t_info *info)
{
	int				p;
	unsigned char	*pt;

	info->conv = 'p';
	p = va_arg(info->arguments, int);
	info->len = ft_nbrlenbase(p, 16) + 2;
	pt = ft_ulltoa_base(p, 16);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, "0x", 0);
		info->writer(info->target, pt, 0);
		ft_check_width(info, info->len);
		return (0);
	}
	ft_check_width(info, info->len);
	info->writer(info->target, "0x", 0);
	info->writer(info->target, pt, 0);
	return (0);
}
