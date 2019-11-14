/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:52:57 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/13 15:21:50 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_flags(t_info *info)
{
	if ((info->conv == 'd' || info->conv == 'i') && info->sign >= 0)
	{
		if (info->flags & e_plus)
		{
			info->len++;
			info->writer(info->target, "+", 1);
		}
		else if (info->flags & e_space)
		{
			info->len++;
			info->writer(info->target, " ", 1);
		}
	}
}
