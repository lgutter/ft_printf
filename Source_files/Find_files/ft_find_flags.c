/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:25:51 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/15 21:57:32 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_flags(const char *format, t_info *info, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] == '+')
			info->flags |= e_plus;
		else if (format[i] == '-')
			info->flags |= e_minus;
		else if (format[i] == ' ')
			info->flags |= e_space;
		else if (format[i] == '0')
			info->flags |= e_zero;
		else if (format[i] == '#')
			info->flags |= e_hash;
		else
			return (i);
		if ((info->flags & e_space) != 0 && (info->flags & e_plus) != 0)
			info->flags -= e_space;
		if ((info->flags & e_zero) != 0 && (info->flags & e_minus) != 0)
			info->flags -= e_zero;
		i++;
	}
	return (i);
}
