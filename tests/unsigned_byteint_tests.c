/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_byteint_tests.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 16:06:23 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_zero_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hhu", d);
	fflush(stdout);

	asprintf(&result, "%05hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_outside_char_range_u, .init = redirect_std_out)
{
	unsigned char d;
	char *result = NULL;
	d = 242;
	ft_printf("%05hhu", d);
	fflush(stdout);

	asprintf(&result, "%05hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_zero_negative_nb_i, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hhu", d);
	fflush(stdout);

	asprintf(&result, "%05hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_space_negative_nb_i, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hhu", d);
	fflush(stdout);

	asprintf(&result, "%5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_space_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hhu", d);
	fflush(stdout);

	asprintf(&result, "%5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_minus_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05hhu", d);
	fflush(stdout);

	asprintf(&result, "%-5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_zero_minus_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hhu", d);
	fflush(stdout);

	asprintf(&result, "%-5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_zero_minus_nb_i, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hhu", d);
	fflush(stdout);

	asprintf(&result, "%-5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_space_nb_i, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hhu", d);
	fflush(stdout);

	asprintf(&result, " %hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_nb_i_larger_width, .init = redirect_std_out)
{
	unsigned char d;
	char *result = NULL;
	d = 42;
	ft_printf("%5u", d);
	fflush(stdout);

	asprintf(&result, "%5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_plus_large_nb_i, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hhu", d);
	fflush(stdout);

	asprintf(&result, "%5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_byte_int, unsigned_byte_int_large_neg_nb_i, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%5hhu", d);
	fflush(stdout);

	asprintf(&result, "%5hhu", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}
