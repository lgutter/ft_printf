/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatoctal.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:02:41 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/13 12:18:56 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatoctal(t_info *info)
{
	int		n;
	char	*nb;

	info->conv = 'o';
	n = va_arg(info->arguments, int);
	info->len = ft_nbrlenbase(n, 8);
	nb = ft_itoa_base(n, 8);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, nb, 0);
		ft_check_width(info, info->len);
		return (0);
	}
	ft_check_width(info, info->len);
	info->writer(info->target, nb, 0);
	return (0);
}
