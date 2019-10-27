/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcharjoin.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 12:13:40 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/27 12:22:04 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char *str, char c)
{
	char	*strnew;
	int		i;

	i = 0;
	strnew = ft_strnew(ft_strlen(str) + 2);
	if (strnew == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		strnew[i] = str[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (strnew);
}
