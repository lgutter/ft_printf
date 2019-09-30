/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 15:44:36 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/09/30 15:48:23 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static char		*ft_please(signed long long n, int base, char *str, int i)
{
	int			res;
	char		*bstr;

	bstr = "0123456789abcdef";
	if (n > 0)
	{
		res = n % base;
		str[i] = bstr[res];
		i++;
		ft_please(n/base, base, str, i);
	}
	return (str);
}

char			*ft_itoa_base(signed long long nb, int base)
{
	int			nb_len;
	char		*str;

	nb_len = ft_nbrlenbase(nb, base);
	str = (char *)malloc(sizeof(char) * nb_len);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
		str = ft_please(nb, base, str, 1);
		str[nb_len] = '\0';
	}
	else
	{
		str = ft_please(nb, base, str, 0);
		str[nb_len] = '\0';
	}
	return (str);
}

int						main(void)
{
	signed long long	nb;
	int 				base;
	char 				*str;

	nb = 124;
	base = 8;
	str = ft_itoa_base(nb, base);
	str = ft_strrev(str, 0);
	printf("str = %s, nb = %lld\n", str, nb);
	return (0);
}
