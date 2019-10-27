/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatunknown.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 17:35:37 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/27 17:37:54 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatunknown(t_info *info, char c)
{
	char *str;

	str = NULL;
	ft_strcharexpand(&str, c);
	if ((info->options & e_space) != 0)
	{
		ft_strcharexpand(&str, ' ');
	}
	if (str == NULL)
	{
		return (1);
	}
	info->writer(str);
	return (0);
}
