/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 11:48:34 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/13 14:24:10 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatint(t_info *info)
{
	int		n;
	char	*nb;

	n = va_arg(info->arguments, int);
	info->len = ft_nbrlenbase(n, 10);
	if (n < 0)
		return (ft_format_negint(n, info));
	info->sign = 1;
	nb = ft_itoa_base(n, 10);
	if ((info->flags & e_minus) != 0)
	{
		ft_write_flags(info);
		info->writer(info->target, nb, 0);
		ft_check_width(info, info->len);
	}
	else
	{
		if ((info->flags & e_zero) != 0)
			ft_write_flags(info);
		ft_check_width(info, info->len);
		if ((info->flags & e_zero) == 0)
			ft_write_flags(info);
		info->writer(info->target, nb, 0);
	}
	return (0);
}
