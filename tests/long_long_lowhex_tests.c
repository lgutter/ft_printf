/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_long_lowhex_tests.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 11:58:14 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:54:04 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, long_long_large_hex, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%07llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_medium, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%-5llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_fortytwo, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%-5llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_space, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, long_long_width, .init = redirect_std_out)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5llx", d);
	fflush(stdout);

	asprintf(&result, "%5llx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_large_nb_width, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%5llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, long_long_hash, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15llx", (long long)d);
	fflush(stdout);

	asprintf(&result, "%#15llx", (long long)d);
	cr_assert_stdout_eq_str(result);
}
