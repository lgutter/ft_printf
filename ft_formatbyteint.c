/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatbyteint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:34:50 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/16 16:38:21 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_negbyteint(char n, t_info *info)
{
	char *nb;

	info->sign = -1;
	if ((info->flags & e_zero) != 0)
	{
		info->writer(info->target, "-", 1);
		info->len = ft_nbrlenbase((long long)n, 10);
		n = n * -1;
	}
	else
		info->len = ft_nbrlenbase((long long)n, 10);
	nb = ft_itoa_base((long long)n, 10);
	if (nb == NULL)
		return (-1);
	if ((info->flags & e_minus) != 0)
	{
		ft_write_order(info, nb, "rw");
	}
	else
	{
		ft_write_order(info, nb, "wr");
	}
	return (0);
}

int			ft_formatbyteint(t_info *info)
{
	char	n;
	char	*nb;

	n = va_arg(info->arguments, int);
	info->len = ft_nbrlenbase((long long)n, 10);
	if (n < 0)
		return (ft_format_negbyteint(n, info));
	info->sign = 1;
	nb = ft_itoa_base((long long)n, 10);
	if ((info->flags & e_plus) != 0 || (info->flags & e_space) != 0)
	{
		info->len++;
	}
	if ((info->flags & e_minus) != 0)
	{
		ft_write_order(info, nb, "frw");
	}
	else
	{
		if ((info->flags & e_zero) != 0)
			ft_write_order(info, nb, "fwr");
		else
			ft_write_order(info, nb, "wfr");
	}
	return (0);
}
