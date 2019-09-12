/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memexpand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 13:29:30 by lgutter       #+#    #+#                 */
/*   Updated: 2019/02/15 13:29:31 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memexpand(void **src, size_t *size1, const void *add, size_t size2)
{
	void *temp;

	temp = *src;
	if (*src == NULL)
	{
		*src = ft_memdup(add, size2);
	}
	else
	{
		*src = ft_memjoin(*src, *size1, add, size2);
		free(temp);
	}
	*size1 += size2;
}
