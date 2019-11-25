/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   upphex_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:04:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/25 16:25:09 by lgutter       ########   odam.nl         */
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

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 'X';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

Test(test_format_upphex, simple_nb, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("7C");
}

Test(test_format_upphex, nb_large_width, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 25;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("                       7C");
}

Test(test_format_upphex, nb_zero_width, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 25;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("000000000000000000000007C");
}

Test(test_format_upphex, nb_hash_width, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 25;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("                     0X7C");
}

Test(test_format_upphex, nb_hash_minus_width, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = e_hash + e_minus;
	info.width = 25;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0X7C                     ");
}

Test(test_format_upphex, nb_hash_zero_width, .init = redirect_std_out)
{
	t_info info;
	int X;
	int fd;

	fd = 1;
	X = 124;
	init_struct(&info);
	init_va_list(&info, X);
	info.writer = &simplewriter;
	info.flags = e_hash + e_zero;
	info.width = 25;
	info.target = &fd;
	info.conv = 'X';
	ft_formatullupphex(X, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0X0000000000000000000007C");
}

Test(test_printf_format_upphex, simple_nb, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%X", X);
	fflush(stdout);

	asprintf(&result, "%X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_small_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%2X", X);
	fflush(stdout);

	asprintf(&result, "%2X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_minus_zero_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%#-025X", X);
	fflush(stdout);

	asprintf(&result, "%#-25X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_minus_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%-50X", X);
	fflush(stdout);

	asprintf(&result, "%-50X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_zero_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%050X", X);
	fflush(stdout);

	asprintf(&result, "%050X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_zero_small_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%05X", X);
	fflush(stdout);

	asprintf(&result, "%05X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, nb_minus_hash_small_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 124;
	result = NULL;
	ft_printf("%#-5X", X);
	fflush(stdout);

	asprintf(&result, "%#-5X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, zero_zero, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 0;
	result = NULL;
	ft_printf("%X", X);
	fflush(stdout);

	asprintf(&result, "%X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, zero_hash, .init = redirect_std_out)
{
	unsigned int X;
	char *result;

	X = 0;
	result = NULL;
	ft_printf("%#X", X);
	fflush(stdout);

	asprintf(&result, "%#X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, zero_hash_zero_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 0;
	result = NULL;
	ft_printf("%#025X", X);
	fflush(stdout);

	asprintf(&result, "%#025X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, zero_hash_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 0;
	result = NULL;
	ft_printf("%#25X", X);
	fflush(stdout);

	asprintf(&result, "%#25X", X);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, zero_hash_minus_width, .init = redirect_std_out)
{
	int X;
	char *result;

	X = 0;
	result = NULL;
	ft_printf("%#-25X", X);
	fflush(stdout);

	asprintf(&result, "%#-25X", X);
	cr_assert_stdout_eq_str(result);
}
