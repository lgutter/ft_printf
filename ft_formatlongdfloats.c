/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatlongdfloats.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:08:28 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/21 22:25:37 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_formatlongdfloats(t_info *info, float f)
{
	int		n;
	char	*nb;
	size_t	prec;

	n = (int)f;
	prec = 0;
	nb = ft_itoa_base(n, 10);
	info->writer(info->target, nb, 0);
	if (info->precfound == 1 && info->precision == 0)
		return (0);
	info->writer(info->target, ".", 1);
	if (n < 0)
	{
		info->sign = -1;
		f = f * -1;
		n = n * -1;
	}
	while (f > 0 && prec < info->precision)
	{
		f = f - n;
		f = f * 10;
		n = (int)f;
		nb = ft_itoa(n);
		info->writer(info->target, nb, 0);
		prec++;
	}
	return (0);
}
