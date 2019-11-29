/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_tests.c                                    :+:    :+:            */
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

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

static void simplewriter(void *target, unsigned long long *totallen, const char *str, size_t len)
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
		if (*totallen == 42)
		dprintf(2,"");
}

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 'd';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

Test(test_format_long, long_simple_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = 24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24");
}

Test(test_format_long, long_simple_minus_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = -24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_long, long_width_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = 24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("   24");
}

Test(test_format_long, long_minus_flag_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = 24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24   ");
}

Test(test_format_long, long_zero_flag_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = 24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("00024");
}

Test(test_format_long, long_zero_negative_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = -24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 5;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-0024");
}

Test(test_format_long, long_space_negative_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = -24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-24");
}

Test(test_format_long, long_space_nb, .init = redirect_std_out)
{
	t_info info;
	long d;
	int fd;

	fd = 1;
	d = 24;
	init_struct(&info);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 0;
	info.target = &fd;
	info.conv = 'd';
	ft_formatlonglong(d, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 24");
}

Test(test_printf_format_int, long_zero_negative_nb_d, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -24;
	ft_printf("%05ld", d);
	fflush(stdout);

	asprintf(&result, "%05ld", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_outside_char_range_d, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%05ld", d);
	fflush(stdout);

	asprintf(&result, "%05ld", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_zero_negative_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -24;
	ft_printf("%05li", d);
	fflush(stdout);

	asprintf(&result, "%05li", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_space_negative_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5li", d);
	fflush(stdout);

	asprintf(&result, "% 5li", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_space_negative_nb_d, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5ld", d);
	fflush(stdout);

	asprintf(&result, "% 5ld", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_minus_negative_nb_d, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05ld", d);
	fflush(stdout);

	asprintf(&result, "%-5ld", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_zero_minus_nb_d, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5ld", d);
	fflush(stdout);

	asprintf(&result, "%-5ld", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_zero_minus_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5li", d);
	fflush(stdout);

	asprintf(&result, "%-5li", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_space_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 42;
	ft_printf("% li", d);
	fflush(stdout);

	asprintf(&result, "% li", (long)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, long_space_nb_i_larger_width, .init = redirect_std_out)
{
	char d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_plus_large_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5li", d);
	fflush(stdout);

	asprintf(&result, "%+5li", (long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_plus_large_neg_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5li", d);
	fflush(stdout);

	asprintf(&result, "%+5li", (long)d);
	cr_assert_stdout_eq_str(result);
}
