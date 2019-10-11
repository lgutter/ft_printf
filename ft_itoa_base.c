/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 15:44:36 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/11 12:38:13 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> //remove

static char		*ft_please(signed long long n,\
					int base,\
					char *str,\
					size_t i)
{
	int			res;
	char		*bstr;

	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base == 1 && (i <= ft_nbrlenbase(n, base)))
	{
		str[i] = '1';
		i++;
		if (i == ft_nbrlenbase(n, base) - 1)
			return (str);
	}
	if (n > 0)
	{
		res = n % base;
		str[i] = bstr[res];
		i++;
		ft_please(n / base, base, str, i);
	}
	return (str);
}

char			*ft_itoa_base(signed long long nb, int base)
{
	int			nb_len;
	char		*str;

	if (base == 0)
		return (NULL);
	nb_len = ft_nbrlenbase(nb, base);
	str = (char *)malloc(sizeof(char) * nb_len);
	if (nb == 0)
	{
		str = "0\0";
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str = ft_please(nb, base, str, (str[0] == '-' ? 1 : 0));
	str[nb_len] = '\0';
	str = ft_strrev(str, (str[0] == '-' ? 1 : 0));
	return (str);
}

int						main(void)
{
	signed long long	nb;
	int					base;
	char				*str;

	nb = 5;
	base = 0;
	str = ft_itoa_base(nb, base);	
	printf("str = %s\nnb = %lld\n", str, nb);
	return (0);
}
