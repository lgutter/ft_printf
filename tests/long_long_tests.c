/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_long_tests.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/16 16:47:58 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_long_long(void)
{
	cr_redirect_stdout();
}

static void simplewriter(void *target, const char *str, size_t len)
{
	int fd;

	fd = *((int *)target);
	if (len > 0)
	{
		write(fd, str, len);
	}
	else
	{
		write(fd, str, ft_strlen(str));
	}
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_long_long, long_long_simple_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24");
}

Test(test_format_long_long, long_long_simple_minus_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_long_long, long_long_width_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("   24");
}

Test(test_format_long_long, long_long_minus_flag_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24   ");
}

Test(test_format_long_long, long_long_zero_flag_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("00024");
}

Test(test_format_long_long, long_long_zero_negative_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-0024");
}

Test(test_format_long_long, long_long_space_negative_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_long_long, long_long_space_nb, .init = redirect_std_out_long_long)
{
	t_info info;
	long long d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 24");
}

Test(test_printf_format_int, long_long_zero_negative_nb_d, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -24;
	ft_printf("%05lld", d);
	fflush(stdout);

	asprintf(&result, "%05lld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_outside_char_range_d, .init = redirect_std_out_long_long)
{
	unsigned long long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%05lld", d);
	fflush(stdout);

	asprintf(&result, "%05lld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_zero_negative_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -24;
	ft_printf("%05lli", d);
	fflush(stdout);

	asprintf(&result, "%05lli", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_space_negative_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5lli", d);
	fflush(stdout);

	asprintf(&result, "% 5lli", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_space_negative_nb_d, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5lld", d);
	fflush(stdout);

	asprintf(&result, "% 5lld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_minus_negative_nb_d, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05lld", d);
	fflush(stdout);

	asprintf(&result, "%-5lld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_zero_minus_nb_d, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5lld", d);
	fflush(stdout);

	asprintf(&result, "%-5lld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_zero_minus_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5lli", d);
	fflush(stdout);

	asprintf(&result, "%-5lli", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_space_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% lli", d);
	fflush(stdout);

	asprintf(&result, "% lli", d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, long_long_space_nb_i_larger_width, .init = redirect_std_out_long_long)
{
	char d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_plus_large_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5lli", d);
	fflush(stdout);

	asprintf(&result, "%+5lli", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_plus_large_neg_nb_i, .init = redirect_std_out_long_long)
{
	long long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5lli", d);
	fflush(stdout);

	asprintf(&result, "%+5lli", d);
	cr_assert_stdout_eq_str(result);
}
