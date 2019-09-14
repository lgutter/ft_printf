/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strexpand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 16:04:59 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/13 17:42:18 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_strexpand(char **source, const char *addition)
{
	void *temp;

	temp = *source;
	if (*source == NULL)
	{
		*source = ft_strdup(addition);
	}
	else
	{
		*source = ft_strjoin(*source, addition);
		free(temp);
	}
}
