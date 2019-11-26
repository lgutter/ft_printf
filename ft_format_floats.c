/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_floats.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:52:44 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/26 17:49:55 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_sign(char *nb)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(nb) + 2));
	if (temp != NULL)
	{
		temp[0] = '-';
		ft_strcpy(&temp[1], nb);
	}
	return (temp);
}

static int	ft_floaty_things(t_info *info, long double f, int n, char *nb)
{
	size_t	prec;
	char	*temp;

	prec = 0;
	temp = NULL;
	ft_strexpand(&nb, ".");
	while (f != 0 && (prec < 100 || prec < info->precision))
	{
		f = (f - n) * 10;
		n = (int)f;
		temp = ft_itoa(n < 0 ? n * -1 : n);
		ft_strexpand(&nb, temp);
		free(temp);
		prec++;
	}
	nb = ft_float_precision(info, nb);
	if (info->sign == -1)
		nb = ft_add_sign(nb);
	info->len = ft_strlen(nb);
	if ((info->flags & e_minus) != 0)
		ft_write_order(info, nb, "rw");
	else
		ft_write_order(info, nb, "wr");
	free(nb);
	return (0);
}

static int	ft_formatlongdfloats(t_info *info, long double f)
{
	long long int	n;
	char			*nb;

	n = (long long int)f;
	nb = ft_itoa_base(n, 10);
	info->len = ft_strlen(nb);
	if (info->precfound < 0)
		info->precision = 6;
	return (ft_floaty_things(info, f, n, nb));
}

static int	ft_exceptions(t_info *info, long double f)
{
	char *err;

	err = NULL;
	if (f != f)
		err = "nan";
	else if (f > __LDBL_MAX__)
		err = "inf";
	else if (f < __LDBL_MAX__ * -1)
		err = "-inf";
	info->len = ft_strlen(err);
	if ((info->flags & e_zero) != 0)
		info->flags -= e_zero;
	if ((info->flags & e_minus) != 0)
		return (ft_write_order(info, err, "rw"));
	return (ft_write_order(info, err, "wr"));
}

int			ft_format_floats(t_info *info)
{
	long double	f;

	info->conv = 'f';
	if (info->precfound < 0)
		info->precision = 6;
	if ((info->lenmod & e_L) != 0)
		f = (long double)va_arg(info->arguments, long double);
	else
		f = (long double)va_arg(info->arguments, double);
	if (f < (long double)0.0)
	{
		f = f * -1;
		info->sign = -1;
	}
	if (f != f || f > __LDBL_MAX__ || f < __LDBL_MAX__ * -1)
	{
		return (ft_exceptions(info, f));
	}
	return (ft_formatlongdfloats(info, f));
}
