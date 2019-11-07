/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:40:16 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/07 12:13:11 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatchar(t_info *info, t_convinfo *convinfo)
{
	char c;

	convinfo->type = 'c';
	c = va_arg(info->arguments, int);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(&c, 1);
		ft_check_width(info, 1);
		return (0);
	}
	ft_check_width(info, 1);
	info->writer(&c, 1);
	return (0);
}
