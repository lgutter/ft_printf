/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:03:28 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/04 17:05:13 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writer(const char *string, size_t len)
{
	if (len > 0)
	{
		write(1, string, len);
	}
	else
	{
		write(1, string, ft_strlen(string));
	}
}
