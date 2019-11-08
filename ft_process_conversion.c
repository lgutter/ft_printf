/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_process_conversion.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 15:46:25 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/06 18:33:53 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process_conversion(const char *format, t_info *info)
{
	int			i;
	t_formatter	formatter;
	t_convinfo	convinfo;

	i = ft_init_info(format, info);
	formatter = ft_dispatcher(format[i]);
	if (formatter != NULL)
	{
		formatter(info, &convinfo);
	}
	else
	{
		ft_formatunknown(info, format[i]);
	}
	if (format[i] == '\0')
		return (i);
	return (i + 1);
}
