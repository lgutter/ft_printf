/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteint_octal_tests.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 17:34:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 18:00:14 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_byteint_octal(void)
{
	cr_redirect_stdout();
}

Test(test_printf_formatoctal, byteint_large_octal, .init = redirect_std_out_byteint_octal)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%07hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatoctal, byteint_medium_octal, .init = redirect_std_out_byteint_octal)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatoctal, byteint_fortytwo_octal, .init = redirect_std_out_byteint_octal)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatoctal, byteint_space_octal, .init = redirect_std_out_byteint_octal)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_formatoctal, byteint_width_octal, .init = redirect_std_out_byteint_octal)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatoctal, byteint_large_nb_width_octal, .init = redirect_std_out_byteint_octal)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatoctal, byteint_no_hash_octal, .init = redirect_std_out_byteint_octal)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15hho", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%#15hho", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}
