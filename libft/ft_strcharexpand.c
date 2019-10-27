/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcharexpand.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 12:30:20 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/27 12:32:37 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcharexpand(char **source, const char addition)
{
	void *temp;

	temp = *source;
	if (*source == NULL)
	{
		*source = ft_strnew(2);
		if (*source == NULL)
			return (NULL);
		*source[0] = addition;
		*source[1] = '\0';
	}
	else
	{
		*source = ft_strcharjoin(*source, addition);
		free(temp);
	}
}
