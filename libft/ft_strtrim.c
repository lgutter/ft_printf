/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 14:47:49 by lgutter       #+#    #+#                 */
/*   Updated: 2019/01/19 14:47:50 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	size_t	end;
	size_t	index;
	char	*ret;

	index = 0;
	while (str[index] == '\n' || str[index] == '\t' || str[index] == ' ')
		index++;
	end = (ft_strlen(str));
	if (end > 0)
		end--;
	while ((str[end] == '\n' || str[end] == '\t' || str[end] == ' ') && end > 0)
		end--;
	if (end == 0)
		index = (end + 1);
	ret = ft_strsub(str, (unsigned int)index, (end - index) + 1);
	if (!ret)
		return (NULL);
	return (ret);
}
