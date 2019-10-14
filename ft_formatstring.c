/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/14 16:51:42 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info)
{
	char *string;

	if (info->options & 128)
	{
		ft_putchar(' ');
	}
	string = va_arg(info->arguments, char *);
	ft_putstr(string);
	return (0);
}
