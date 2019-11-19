/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteint_tests.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/18 19:46:08 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_byteint(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, byte_int_zero_negative_nb_d, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hhd", d);
	fflush(stdout);

	asprintf(&result, "%05hhd", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_outside_char_range_d, .init = redirect_std_out_byteint)
{
	unsigned char d;
	char *result = NULL;
	d = 242;
	ft_printf("%05hhd", d);
	fflush(stdout);

	asprintf(&result, "%05hhd", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_zero_negative_nb_i, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hhi", d);
	fflush(stdout);

	asprintf(&result, "%05hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_space_negative_nb_i, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hhi", d);
	fflush(stdout);

	asprintf(&result, "% 5hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_space_negative_nb_d, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hhd", d);
	fflush(stdout);

	asprintf(&result, "% 5hhd", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_minus_negative_nb_d, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05hhd", d);
	fflush(stdout);

	asprintf(&result, "%-5hhd", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_zero_minus_nb_d, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hhd", d);
	fflush(stdout);

	asprintf(&result, "%-5hhd", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_zero_minus_nb_i, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hhi", d);
	fflush(stdout);

	asprintf(&result, "%-5hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_space_nb_i, .init = redirect_std_out_byteint)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hhi", d);
	fflush(stdout);

	asprintf(&result, "% hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, byte_int_space_nb_i_larger_width, .init = redirect_std_out_byteint)
{
	char d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_plus_large_nb_i, .init = redirect_std_out_byteint)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5hhi", d);
	fflush(stdout);

	asprintf(&result, "%+5hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, byte_int_plus_large_neg_nb_i, .init = redirect_std_out_byteint)
{
	long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5hhi", d);
	fflush(stdout);

	asprintf(&result, "%+5hhi", (char)d);
	cr_assert_stdout_eq_str(result);
}
