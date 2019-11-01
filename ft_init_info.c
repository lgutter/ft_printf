/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:50:09 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/01 12:23:44 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_info(const char *format, t_info *info)
{
	int i;

	i = 1;
	info->flags = 0;
	info->width = 0;
	info->precision = 0;
	i = ft_find_flags(format, info, i);
	return (i);
}
