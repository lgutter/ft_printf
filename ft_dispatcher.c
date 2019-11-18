/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dispatcher.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:25:46 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/18 18:08:58 by ivan-tey      ########   odam.nl         */
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
		['X'] = &ft_formatupphex,
		['x'] = &ft_formatlowhex,
	};

	return (formatter[(unsigned int)conv_flag]);
}
