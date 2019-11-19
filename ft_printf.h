/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:10:30 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 16:57:51 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef void			(*t_writer)\
						(void *target, const char *string, size_t len);

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

/*
**	the info struct! this contains anything that we might need.
**	A short explanation of every variable in the struct:
**	flags & lenmod:	Uses the above mentioned enums to store flags / lenmods.
**	conv:			Contains the char representing the conversion specifier.
**	precfound:		positive if a precision was found, negative if it was not.
**	sign:			Used to specify if a number is positive or negative.
**	arguments:		Va_list with all the arguments that printf received.
**	width:			Simple value representing the width provided.
**	precision:		Simple value representing the precision provided.
**	writer:			A function pointer to the writer function.
**	target:			Where to write to. * to FILE *, filedescriptor, or char *.
*/
typedef struct			s_info
{
	unsigned char		flags;
	unsigned char		lenmod;
	unsigned char		conv;
	char				precfound;
	int					sign;
	size_t				len;
	va_list				arguments;
	size_t				width;
	size_t				precision;
	t_writer			writer;
	void				*target;
}						t_info;

typedef int				(*t_formatter)(t_info *info);
int						ft_printf(const char *restrict format, ...);
int						ft_process_conversion(const char *format, t_info *info);
int						ft_init_info(const char *format, t_info *info);
t_formatter				ft_dispatcher(char conv_flag);
void					ft_writer_fd\
						(void *target, const char *string, size_t len);
char					*ft_precision_int(t_info *info, char *number);
int						ft_formatunsigneddecimal(t_info *info);

int						ft_formatchar(t_info *info);
int						ft_formatstring(t_info *info);
int						ft_formatunknown(t_info *info, char c);
int						ft_formatdecimal(t_info *info);
int						ft_formatunsignedlonglong(\
						unsigned long long n, t_info *info);
int						ft_formatlonglong(long long n, t_info *info);
int						ft_formatoctal(t_info *info);
int						ft_formatpointer(t_info *info);
int						ft_format_upphex(t_info *info);
int						ft_formatullupphex(unsigned long long n, t_info *info);
int						ft_format_lowhex(t_info *info);
int						ft_formatulllowhex(unsigned long long n, t_info *info);

int						ft_find_flags(const char *format, t_info *info, int i);
int						ft_find_width(const char *format, t_info *info, int i);
int						ft_find_precision\
						(const char *format, t_info *info, int i);
int						ft_find_lenmod(const char *format, t_info *info, int i);

void					ft_check_width(t_info *info, size_t len);
void					ft_write_flags(t_info *info);
int						ft_write_order(t_info *info, char *str, char *order);

#endif
