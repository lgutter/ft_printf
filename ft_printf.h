/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:10:30 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/14 16:49:35 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef void				(*t_writer)(const char *string);

typedef struct			s_info
{
	unsigned short		options;
	va_list				arguments;
	size_t				width;
	size_t				precision;
	t_writer			writer;
}						t_info;

typedef int				(*t_formatter)(t_info *info);
int						ft_printf(const char *restrict format, ...);
void					ft_strexpand(char **source, const char *addition);
int						ft_init_info(const char *format, t_info *info);
t_formatter				ft_dispatcher(char conv_flag);
int						ft_formatchar(t_info *info);
int						ft_formatstring(t_info *info);

#endif
