/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 11:48:34 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/12 10:59:18 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatint(t_info *info)
{
	int		n;
	char	*nb;

	info->conv = 'd';
	n = va_arg(info->arguments, int);
	info->len = ft_nbrlenbase(n, 10);
	n = ft_handle_negint(n, info);
	nb = ft_itoa(n);
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
