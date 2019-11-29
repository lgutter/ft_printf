/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/29 12:59:23 by lgutter       ########   odam.nl         */
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
	info->len = ft_precision_string(info, &str);
	if ((info->flags & e_minus) != 0)
	{
		info->writer(info->target, &info->totallen, str, info->len);
		ft_write_width(info, info->len);
		return (0);
	}
	ft_write_width(info, info->len);
	info->writer(info->target, &info->totallen, str, info->len);
	return (0);
}
