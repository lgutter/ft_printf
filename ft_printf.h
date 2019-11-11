/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:10:30 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/11 12:23:48 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef void				(*t_writer)(const char *string, size_t len);

/*
**	enumerations for the flags and modifiers stored in lenmod and flags.
**	these are written down here as bitshifts, but in essence the exact number
**	linked to an enum is not relevant, just that we can uniquely store and fetch
**	any option (flag or modifier)
*/
enum					e_lenmod
{
	e_L = 1 << 0,
	e_l = 1 << 1,
	e_h = 1 << 2,
	e_ll = 1 << 3,
	e_hh = 1 << 4
};

enum					e_flags
{
	e_hash = 1 << 0,
	e_zero = 1 << 1,
	e_space = 1 << 2,
	e_minus = 1 << 3,
	e_plus = 1 << 4
};

typedef struct			s_info
{
	unsigned char		flags;
	unsigned char		lenmod;
	va_list				arguments;
	size_t				width;
	size_t				precision;
	t_writer			writer;
}						t_info;

typedef struct			s_convinfo
{
	size_t				negative;
	size_t				len;
	char				type;
}						t_convinfo;

typedef int				(*t_formatter)(t_info *info, t_convinfo *convinfo);
int						ft_printf(const char *restrict format, ...);
int						ft_process_conversion(const char *format, t_info *info);
int						ft_init_info(const char *format, t_info *info);
t_formatter				ft_dispatcher(char conv_flag);
void					ft_writer(const char *string, size_t len);

int						ft_formatchar(t_info *info, t_convinfo *convinfo);
int						ft_formatstring(t_info *info, t_convinfo *convinfo);
int						ft_formatunknown(t_info *info, char c);

int						ft_formatint(t_info *info, t_convinfo *convinfo);
int						ft_handle_negint\
						(int n, t_info *info, t_convinfo *convinfo);

int						ft_is_conv(const char ch);
int						ft_find_flags\
						(const char *format, t_info *info, int i);
int						ft_find_width(const char *format, t_info *info, int i);
int						ft_find_precision\
						(const char *format, t_info *info, int i);
int						ft_find_lenmod(const char *format, t_info *info, int i);

void					ft_check_width\
						(t_info *info, size_t len);

#endif
