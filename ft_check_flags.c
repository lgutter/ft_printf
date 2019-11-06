/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:56:20 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/06 15:17:49 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_flags(t_info *info, char type)
{
	if ((info->flags & e_space) != 0 && (type == 'd' || type == 'i'))
		info->writer(" ", 1);
}
