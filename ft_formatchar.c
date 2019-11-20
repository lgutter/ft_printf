/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:40:16 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/20 16:42:45 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatchar(t_info *info)
{
	char c;

	info->conv = 'c';
	c = (char)va_arg(info->arguments, int);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, &c, 1);
		ft_check_width(info, 1);
	}
	else
	{
		ft_check_width(info, 1);
		info->writer(info->target, &c, 1);
	}
	return (0);
}
