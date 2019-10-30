/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/30 13:31:41 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info)
{
	char *string;

	string = NULL;
	if ((info->options & e_space) != 0)
	{
		info->writer(" ");
	}
	ft_strexpand(&string, va_arg(info->arguments, char *));
	if (string == NULL)
		return (1);
	info->writer(string);
	return (0);
}
