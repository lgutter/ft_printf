/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_long_upphex_tests.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:10:34 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:56:22 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_upphex, long_long_large_upphex, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%07llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, long_long_medium_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%-5llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, long_long_fortytwo_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%-5llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, long_long_space_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_upphex, long_long_width_upphex, .init = redirect_std_out)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5llX", d);
	fflush(stdout);

	asprintf(&result, "%5llX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, long_long_large_nb_width_upphex, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%5llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, long_long_hash_upphex, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15llX", (long long)d);
	fflush(stdout);

	asprintf(&result, "%#15llX", (long long)d);
	cr_assert_stdout_eq_str(result);
}
