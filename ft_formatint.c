/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 11:48:34 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/11 12:25:13 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatint(t_info *info, t_convinfo *convinfo)
{
	int		n;
	char	*nb;

	convinfo->type = 'd';
	n = va_arg(info->arguments, int);
	convinfo->len = ft_nbrlenbase(n, 10);
	n = ft_handle_negint(n, info, convinfo);
	nb = ft_itoa(n);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(nb, 0);
		ft_check_width(info, convinfo->len);
		return (0);
	}
	ft_check_width(info, convinfo->len);
	info->writer(nb, 0);
	return (0);
}
