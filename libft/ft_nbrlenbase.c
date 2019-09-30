/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlenbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 12:11:46 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/30 18:05:24 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase(long number, int base)
{
	size_t len;

	len = 1;
	if (number < 0)
		len++;
	if (base == 1)
	{
		if (number < 0)
			number = number * -1;
		return ((size_t)number + len);
	}
	while (number / base != 0)
	{
		len++;
		number /= base;
	}
	return (len);
}
