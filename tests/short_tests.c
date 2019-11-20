/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 16:04:47 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, short_zero_negative_nb_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hd", d);
	fflush(stdout);

	asprintf(&result, "%05hd", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_outside_short_range_d, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hd", d);
	fflush(stdout);

	asprintf(&result, "%07hd", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_zero_negative_nb_i, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05hi", d);
	fflush(stdout);

	asprintf(&result, "%05hi", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_space_negative_nb_i, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hi", d);
	fflush(stdout);

	asprintf(&result, "% 5hi", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_space_negative_nb_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5hd", d);
	fflush(stdout);

	asprintf(&result, "% 5hd", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_minus_negative_nb_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05hd", d);
	fflush(stdout);

	asprintf(&result, "%-5hd", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_zero_minus_nb_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hd", d);
	fflush(stdout);

	asprintf(&result, "%-5hd", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_zero_minus_nb_i, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hi", d);
	fflush(stdout);

	asprintf(&result, "%-5hi", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_space_nb_i, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hi", d);
	fflush(stdout);

	asprintf(&result, "% hi", (short)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_int, short_space_nb_i_larger_width, .init = redirect_std_out)
{
	short d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_plus_large_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5hi", d);
	fflush(stdout);

	asprintf(&result, "%+5hi", (short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, short_plus_large_neg_nb_i, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5hi", d);
	fflush(stdout);

	asprintf(&result, "%+5hi", (short)d);
	cr_assert_stdout_eq_str(result);
}
