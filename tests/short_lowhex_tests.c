/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_lowhex_tests.c                               ::    ::            */
/*                                                     :                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         #                     */
/*                                                   #                      */
/*   Created: 2019/11/19 11:45:32 by ivan-tey       ##    ##                */
/*   Updated: 2019/11/19 11:47:51 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, short_large_hex, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hx", d);
	fflush(stdout);

	asprintf(&result, "%07hx", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_medium, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hx", d);
	fflush(stdout);

	asprintf(&result, "%-5hx", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_fortytwo, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hx", d);
	fflush(stdout);

	asprintf(&result, "%-5hx", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_space, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hx", d);
	fflush(stdout);

	asprintf(&result, "%hx", (short)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, short_width, .init = redirect_std_out)
{
	short d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5x", d);
	fflush(stdout);

	asprintf(&result, "%5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_large_nb_width, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hx", (short)d);
	fflush(stdout);

	asprintf(&result, "%5hx", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_hash, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15hx", (short)d);
	fflush(stdout);

	asprintf(&result, "%#15hx", (short)d);
	cr_assert_stdout_eq_str(result);
}
