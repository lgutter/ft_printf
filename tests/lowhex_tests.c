/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lowhex_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:18:37 by ivan-tey       #+#    #+#                */
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
	info->conv = 'x';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

Test(test_format_lowhex, simple_nb, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("7c");
}

Test(test_format_lowhex, nb_large_width, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 25;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("                       7c");
}

Test(test_format_lowhex, nb_zero_width, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 25;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("000000000000000000000007c");
}

Test(test_format_lowhex, nb_hash_width, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 25;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("                     0x7c");
}

Test(test_format_lowhex, nb_hash_minus_width, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = e_hash + e_minus;
	info.width = 25;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0x7c                     ");
}

Test(test_format_lowhex, nb_hash_zero_width, .init = redirect_std_out)
{
	t_info info;
	unsigned int x;
	int fd;

	fd = 1;
	x = 124;
	init_struct(&info);
	init_va_list(&info, x);
	info.writer = &simplewriter;
	info.flags = e_hash + e_zero;
	info.width = 25;
	info.target = &fd;
	info.conv = 'x';
	ft_formatulllowhex(x, &info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0x0000000000000000000007c");
}

Test(test_printf_format_lowhex, simple_nb, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%x", x);
	fflush(stdout);

	asprintf(&result, "%x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_small_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%2x", x);
	fflush(stdout);

	asprintf(&result, "%2x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_minus_zero_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%#-025x", x);
	fflush(stdout);

	asprintf(&result, "%#-25x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_minus_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%-50x", x);
	fflush(stdout);

	asprintf(&result, "%-50x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_zero_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%050x", x);
	fflush(stdout);

	asprintf(&result, "%050x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_zero_small_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%05x", x);
	fflush(stdout);

	asprintf(&result, "%05x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, nb_minus_hash_small_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 124;
	result = NULL;
	ft_printf("%#-5x", x);
	fflush(stdout);

	asprintf(&result, "%#-5x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, zero_zero, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 0;
	result = NULL;
	ft_printf("%x", x);
	fflush(stdout);

	asprintf(&result, "%x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, zero_hash, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 0;
	result = NULL;
	ft_printf("%#x", x);
	fflush(stdout);

	asprintf(&result, "%#x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, zero_hash_zero_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 0;
	result = NULL;
	ft_printf("%#025x", x);
	fflush(stdout);

	asprintf(&result, "%#025x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, zero_hash_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 0;
	result = NULL;
	ft_printf("%#25x", x);
	fflush(stdout);

	asprintf(&result, "%#25x", x);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_lowhex, zero_hash_minus_width, .init = redirect_std_out)
{
	unsigned int x;
	char *result;

	x = 0;
	result = NULL;
	ft_printf("%#-25x", x);
	fflush(stdout);

	asprintf(&result, "%#-25x", x);
	cr_assert_stdout_eq_str(result);
}
