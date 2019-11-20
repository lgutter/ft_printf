/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   octal_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:28:04 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 17:17:52 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

static void simplewriter(void *target, const char *str, unsigned long len)
{
	int fd;

	fd = *((int *)target);
	if (len > 0)
	{
		write(1, str, len);
	}
	else
	{
		write(1, str, ft_strlen(str));
	}
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 'o';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
}

Test(test_format_octal, int_simple_nb, .init = redirect_std_out)
{
	t_info info;
	unsigned long long	o;
	int fd;

	fd = 1;
	o = 24;
	init_struct(&info);
	init_va_list(&info, o);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.precision = 0;
	info.lenmod = 0;
	info.conv = 0;
	info.sign = 0;
	info.precfound = 0;
	info.len = 0;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("30");
}

Test(test_format_octal, int_width_nb, .init = redirect_std_out)
{
	t_info info;
	unsigned long long	o;
	int fd;

	fd = 1;
	o = 24;
	init_struct(&info);
	init_va_list(&info, o);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 10;
	info.target = &fd;
	info.precision = 0;
	info.lenmod = 0;
	info.conv = 0;
	info.sign = 0;
	info.precfound = 0;
	info.len = 0;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("        30");
}

Test(test_format_octal, int_zero_width_nb, .init = redirect_std_out)
{
	t_info info;
	unsigned long long	o;
	int fd;

	fd = 1;
	o = 24;
	init_struct(&info);
	init_va_list(&info, o);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 10;
	info.target = &fd;
	info.precision = 0;
	info.lenmod = 0;
	info.conv = 0;
	info.sign = 0;
	info.precfound = 0;
	info.len = 0;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0000000030");
}

Test(test_format_octal, int_minus_width_nb, .init = redirect_std_out)
{
	t_info info;
	unsigned long long	o;
	int fd;

	fd = 1;
	o = 24;
	init_struct(&info);
	init_va_list(&info, o);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 10;
	info.target = &fd;
	info.precision = 0;
	info.lenmod = 0;
	info.conv = 0;
	info.sign = 0;
	info.precfound = 0;
	info.len = 0;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("30        ");
}

Test(test_format_octal, int_zero, .init = redirect_std_out)
{
	t_info info;
	unsigned long long	o;
	int fd;

	fd = 1;
	o = 0;
	init_struct(&info);
	init_va_list(&info, o);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 0;
	info.target = &fd;
	info.precision = 0;
	info.lenmod = 0;
	info.conv = 0;
	info.sign = 0;
	info.precfound = 0;
	info.len = 0;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0");
}
