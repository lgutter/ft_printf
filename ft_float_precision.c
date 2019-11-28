/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float_precision.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:43:10 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/28 15:35:28 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_one(char *nb)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(nb) + 2));
	if (temp != NULL)
	{
		temp[0] = '1';
		ft_strcpy(&temp[1], nb);
	}
	return (temp);
}

static char	*ft_padzeros(char *nb, size_t prec)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (prec + 1));
	if (new != NULL)
	{
		while (ft_isdigit(nb[i]) == 1 || nb[i] == '.')
		{
			new[i] = nb[i];
			i++;
		}
		while (i <= prec)
		{
			new[i] = '0';
			i++;
		}
		free(nb);
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_round_float(char *nb, size_t i, size_t prec)
{
	if (nb[prec + 1] < '5' && nb[prec + 1] >= '0')
		return (nb);
	i = prec + 1;
	if (nb[i] > '4' || (nb[i] == '5' &&\
		(ft_isdigit(nb[i - 1]) && nb[i - 1] % 2 != 0)))
	{
		i--;
		while (i > 0 && (nb[i] == '9' || nb[i] == '.'))
		{
			if (nb[i] != '0')
				nb[i] = '0';
			if (i > 1 && nb[i - 1] == '.')
				i--;
			i--;
		}
		if (i == 0)
		{
			if (nb[i] == '9')
				nb[i] = '0';
			if (nb[i] == '0')
				return (ft_add_one(nb));
		}
		nb[i]++;
	}
	return (nb);
}

static int	ft_ugh(char *nb)
{
	int		i;

	i = 0;
	while (nb[i] != '\0')
	{
		if (nb[i] >= '1' && nb[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_float_precision(t_info *info, char *nb)
{
	size_t	i;
	size_t	prec;

	prec = 0;
	while (nb[prec] != '.')
		prec++;
	prec += info->precision;
	i = ft_strlen(nb);
	if (i <= prec)
		return (ft_padzeros(nb, prec));
	if (nb[0] % 2 == 0 && info->precision == 0 && nb[1] == '.' &&\
		nb[2] == '5' && ft_ugh(&nb[3]) == 0)
	{
		nb[0] = nb[0];
		nb[prec + (info->precision != 0 || (info->flags & e_hash) == 1)] = '\0';
		return (nb);
	}
	nb = ft_round_float(nb, i, prec);
	nb[prec + (info->precision != 0 || (info->flags & e_hash) == 1)] = '\0';
	return (nb);
}
