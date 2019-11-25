/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatlongdfloats.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:08:28 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/25 21:58:31 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_floaty_things(t_info *info, long double f, int n, char *nb)
{
	size_t	prec;
	char	*temp;

	prec = 0;
	temp = NULL;
	nb = ft_strjoin(nb, ".");
	info->len += 1;
	if (n < 0)
	{
		info->sign = -1;
		f = f * -1;
		n = n * -1;
	}
	while (prec < info->precision)
	{
		f = f - n;
		f = f * 10;
		n = (int)f;
		temp = ft_itoa(n);
		nb = ft_strjoin(nb, temp);
		prec++;
		info->len++;
	}
	ft_write_order(info, nb, "fwr");
	return (0);
}

int			ft_formatlongdfloats(t_info *info, long double f)
{
	int		n;
	char	*nb;

	n = (int)f;
	nb = ft_itoa_base(n, 10);
	info->len = ft_strlen(nb);
	if (info->precfound < 0)
		info->precision = 6;
	if (info->precfound > 0 && info->precision == 0)
	{
		if ((info->flags & e_hash) != 0)
		{
			info->len++;
			nb = ft_strjoin(nb, ".");
		}
		ft_write_order(info, nb, "fwr");
		return (0);
	}
	return (ft_floaty_things(info, f, n, nb));
}
