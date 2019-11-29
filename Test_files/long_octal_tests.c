/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   long_octal_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 17:44:27 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:56:47 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_octal, long_large_octal, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%07lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, long_medium, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%-5lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, long_fortytwo, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%-5lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, long_space, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_octal, long_width, .init = redirect_std_out)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%5lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, long_large_nb_width, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%5lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, long_hash, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15lo", (unsigned long)d);
	fflush(stdout);

	asprintf(&result, "%#15lo", (unsigned long)d);
	cr_assert_stdout_eq_str(result);
}
