/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writer_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:03:28 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/11 18:38:57 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writer_fd(void *target, const char *string, size_t len)
{
	int fd;

	fd = *((int *)target);
	if (len > 0)
	{
		write(fd, string, len);
	}
	else
	{
		write(fd, string, ft_strlen(string));
	}
}
