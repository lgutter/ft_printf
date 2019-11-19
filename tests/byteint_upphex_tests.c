/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteint_upphex_tests.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:08:36 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 16:09:16 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_byteint_upphex(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, byteint_large_hex, .init = redirect_std_out_byteint_upphex)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%07hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_medium, .init = redirect_std_out_byteint_upphex)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_fortytwo, .init = redirect_std_out_byteint_upphex)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_space, .init = redirect_std_out_byteint_upphex)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_width, .init = redirect_std_out_byteint_upphex)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_large_nb_width, .init = redirect_std_out_byteint_upphex)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byteint_hash, .init = redirect_std_out_byteint_upphex)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%#15hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}
