/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/04 17:07:46 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info)
{
	char *string;

	if ((info->flags & e_space) != 0)
	{
		info->writer(" ", 1);
	}
	string = va_arg(info->arguments, char *);
	info->writer(string, 0);
	return (0);
}
