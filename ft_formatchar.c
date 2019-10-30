/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:40:16 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/30 13:30:30 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatchar(t_info *info)
{
	char c;
	char *str;

	c = va_arg(info->arguments, int);
	str = NULL;
	ft_strcharexpand(&str, c);
	if ((info->options & e_space) != 0)
	{
		info->writer(" ");
	}
	if (str == NULL)
	{
		return (1);
	}
	info->writer(str);
	return (0);
}
