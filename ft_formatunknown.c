/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatunknown.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 17:35:37 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/11 18:36:12 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatunknown(t_info *info, char c)
{
	if ((info->flags & e_space) != 0)
	{
		info->writer(info->target, " ", 1);
	}
	if (c != '\0')
	{
		info->writer(info->target, &c, 1);
	}
	return (0);
}
