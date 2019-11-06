/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatstring.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:45:31 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/06 19:12:04 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_formatstring(t_info *info, t_convinfo *convinfo)
{
	char *str;

	convinfo->type = 's';
	str = va_arg(info->arguments, char *);
	ft_check_width(info, convinfo, ft_strlen(str));
	info->writer(str, 0);
	return (0);
}
