/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/01 12:26:56 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info)
{
	char *string;

	string = NULL;
	if ((info->flags & e_space) != 0)
	{
		info->writer(" ");
	}
	ft_strexpand(&string, va_arg(info->arguments, char *));
	if (string == NULL)
		return (1);
	info->writer(string);
	return (0);
}
