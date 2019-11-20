/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/20 16:49:12 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info)
{
	char *str;

	str = NULL;
	info->conv = 's';
	str = va_arg(info->arguments, char *);
	if (str == NULL)
		str = "(null)";
	str = ft_precision_string(info, str);
	if (str == NULL)
		return (-1);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, str, 0);
		ft_check_width(info, ft_strlen(str));
		return (0);
	}
	ft_check_width(info, ft_strlen(str));
	info->writer(info->target, str, 0);
	return (0);
}
