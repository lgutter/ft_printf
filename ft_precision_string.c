/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision_string.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:02:07 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/19 16:34:29 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_precision_string(t_info *info, char *string)
{
	size_t	len;
	char	*new;

	new = NULL;
	if (info->precfound < 0)
	{
		return (string);
	}
	if (string != NULL)
	{
		len = ft_strlen(string);
		if (len > info->precision)
		{
			new = (char *)ft_memdup(string, info->precision);
			new[info->precision] = '\0';
		}
		else
		{
			return (string);
		}
	}
	return (new);
}
