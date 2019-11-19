/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_octal_tests.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 17:46:25 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 17:59:26 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_short_octal(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_octal, short_large_octal, .init = redirect_std_out_short_octal)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07ho", d);
	fflush(stdout);

	asprintf(&result, "%07ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, short_medium, .init = redirect_std_out_short_octal)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5ho", d);
	fflush(stdout);

	asprintf(&result, "%-5ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, short_fortytwo, .init = redirect_std_out_short_octal)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5ho", d);
	fflush(stdout);

	asprintf(&result, "%-5ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, short_space, .init = redirect_std_out_short_octal)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% ho", d);
	fflush(stdout);

	asprintf(&result, "%ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_octal, short_width, .init = redirect_std_out_short_octal)
{
	short d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5o", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%5o", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, short_large_nb_width, .init = redirect_std_out_short_octal)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5ho", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%5ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_octal, short_hash, .init = redirect_std_out_short_octal)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15ho", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%#15ho", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}
