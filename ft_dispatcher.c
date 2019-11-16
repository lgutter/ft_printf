/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dispatcher.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:25:46 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/16 15:42:01 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_formatter	ft_dispatcher(char conv_flag)
{
	const t_formatter formatter[255] = {
		['c'] = &ft_formatchar,
		['s'] = &ft_formatstring,
		['d'] = &ft_formatdecimal,
		['i'] = &ft_formatdecimal,
		['o'] = &ft_formatoctal,
		['p'] = &ft_formatpointer,
	};

	return (formatter[(unsigned int)conv_flag]);
}
