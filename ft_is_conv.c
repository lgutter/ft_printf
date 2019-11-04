/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:29:53 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/31 16:56:51 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conv(const char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p')
		return (1);
	if (ch == 'd' || ch == 'i' || ch == 'u')
		return (1);
	if (ch == 'o' || ch == 'x' || ch == 'X' || ch == 'f')
		return (1);
	return (0);
}
