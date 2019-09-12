/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 21:17:53 by lgutter       #+#    #+#                 */
/*   Updated: 2019/01/29 21:17:54 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*ret;
	size_t	index;

	index = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (ret == NULL)
		return (NULL);
	while (string[index] != '\0')
	{
		ret[index] = string[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
