/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/13 14:46:35 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

void redirect_std_out_format_int(void)
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

void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_int, int_simple_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24");
}

Test(test_format_int, int_simple_minus_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_int, int_width_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("   24");
}

Test(test_format_int, int_minus_flag_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24   ");
}

Test(test_format_int, int_zero_flag_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("00024");
}

Test(test_format_int, int_zero_minus_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-0024");
}

Test(test_format_int, int_space_negative_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = -24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_int, int_space_nb, .init = redirect_std_out_format_int)
{
	t_info info;
	int d;
	int fd;

	fd = 1;
	d = 24;
	init_va_list(&info, d);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 24");
}

Test(test_printf_format_int, int_zero_negative_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05d", d);
	fflush(stdout);

	asprintf(&result, "%05d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_negative_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05i", d);
	fflush(stdout);

	asprintf(&result, "%05i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_negative_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_negative_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5d", d);
	fflush(stdout);

	asprintf(&result, "% 5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_minus_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5d", d);
	fflush(stdout);

	asprintf(&result, "%-5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_minus_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5i", d);
	fflush(stdout);

	asprintf(&result, "%-5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% i", d);
	fflush(stdout);

	asprintf(&result, "% i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_plus_large_nb_i, .init = redirect_std_out_format_int)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5i", d);
	fflush(stdout);

	asprintf(&result, "%+5li", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_plus_large_neg_nb_i, .init = redirect_std_out_format_int)
{
	long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5i", d);
	fflush(stdout);

	asprintf(&result, "%+5li", d);
	cr_assert_stdout_eq_str(result);
}
