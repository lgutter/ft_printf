/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 15:44:36 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/09/30 17:18:59 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static char		*ft_please(signed long long n, int base, char *str, size_t i)
{
	int			res;
	char		*bstr;

	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base == 1 && i <= ft_nbrlenbase(n, base))
	{
		str[i] = '1';
		i++;
		if (i == ft_nbrlenbase(n, base))
			return (str);
	}
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
		printf("str = %s\n", str);
		str[nb_len] = '\0';
		//ft_swap(&str[0], &str[nb_len - 1]);
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

	nb = -124;
	base = 2;
	str = ft_itoa_base(nb, base);
	str = ft_strrev(str, 0);
	printf("str = %s\nnb = %lld\n", str, nb);
	return (0);
}
