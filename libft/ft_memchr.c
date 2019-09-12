/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 18:22:49 by lgutter       #+#    #+#                 */
/*   Updated: 2019/01/29 18:22:50 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *source, int character, size_t len)
{
	size_t				index;
	const unsigned char	*input;

	input = source;
	index = 0;
	while (index < len)
	{
		if (input[index] == (unsigned char)character)
		{
			return ((void *)&input[index]);
		}
		index++;
	}
	return (NULL);
}
