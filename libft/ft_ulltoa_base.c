/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulitoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/21 15:14:42 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/22 13:08:46 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(unsigned long long n, \
							const unsigned base, \
							char *str, size_t i)
{
	int			res;
	char		*bstr;

	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base == 1 && (i <= ft_nbrlenbase_ull(n, base)))
	{
		str[i] = '1';
		i++;
		if (i == ft_nbrlenbase_ull(n, base) - 1)
			return (str);
	}
	if (n > 0)
	{
		res = n % base;
		str[i] = bstr[res];
		i++;
		ft_convert(n / base, base, str, i);
	}
	return (str);
}

char			*ft_ulltoa_base(unsigned long long nb, const unsigned base)
{
	int			nb_len;
	char		*str;

	if (base <= 0)
		return (NULL);
	nb_len = ft_nbrlenbase_ull(nb, base);
	str = (char *)malloc(sizeof(char) * nb_len);
	if (nb == 0)
	{
		str = "0\0";
		return (str);
	}
	str = ft_convert(nb, base, str, 0);
	str[nb_len] = '\0';
	str = ft_strrev(str, 0);
	return (str);
}
