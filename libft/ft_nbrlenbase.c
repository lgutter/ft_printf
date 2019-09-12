/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlenbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 12:11:46 by lgutter       #+#    #+#                 */
/*   Updated: 2019/02/02 12:11:47 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase(long number, int base)
{
	size_t len;

	len = 1;
	if (base == 1)
	{
		return ((size_t)number);
	}
	if (number < 0)
	{
		len++;
	}
	while (number / base != 0)
	{
		len++;
		number /= base;
	}
	return (len);
}
