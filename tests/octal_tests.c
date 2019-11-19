/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   octal_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:28:04 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 17:31:48 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

void redirect_std_out_format_octal(void)
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

void init_va_list_octal(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_octal, int_simple_nb, .init = redirect_std_out_format_octal)
{
	t_info info;
	int o;
	int fd;

	fd = 1;
	o = 24;
	init_va_list_octal(&info, o);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("30");
}

Test(test_format_octal, int_width_nb, .init = redirect_std_out_format_octal)
{
	t_info info;
	int o;
	int fd;

	fd = 1;
	o = 24;
	init_va_list_octal(&info, o);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 10;
	info.target = &fd;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("        30");
}

Test(test_format_octal, int_zero_width_nb, .init = redirect_std_out_format_octal)
{
	t_info info;
	int o;
	int fd;

	fd = 1;
	o = 24;
	init_va_list_octal(&info, o);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 10;
	info.target = &fd;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0000000030");
}

Test(test_format_octal, int_minus_width_nb, .init = redirect_std_out_format_octal)
{
	t_info info;
	int o;
	int fd;

	fd = 1;
	o = 24;
	init_va_list_octal(&info, o);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 10;
	info.target = &fd;
	ft_formatulloctal(o, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("30        ");
}
