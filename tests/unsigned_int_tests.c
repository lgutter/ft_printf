/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_unsigned_int_tests.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/19 11:07:47 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_unsigned_int, unsigned_int_zero_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05u", d);
	fflush(stdout);

	asprintf(&result, "%05u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%5u", d);
	fflush(stdout);

	asprintf(&result, "%5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_minus_negative_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05u", d);
	fflush(stdout);

	asprintf(&result, "%-5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_zero_minus_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5u", d);
	fflush(stdout);

	asprintf(&result, "%-5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_zero_minus_42_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5u", d);
	fflush(stdout);

	asprintf(&result, "%-5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_space_nb_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 42;
	ft_printf("% u", d);
	fflush(stdout);

	asprintf(&result, " %u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_nb_i_larger_width, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 42;
	ft_printf("%5u", d);
	fflush(stdout);

	asprintf(&result, "%5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_plus_large_nb_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5lu", d);
	fflush(stdout);

	asprintf(&result, "+%5lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_large_nb_largewidth_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%30lu", d);
	fflush(stdout);

	asprintf(&result, "%30lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_plus_large_neg_nb_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5lu", d);
	fflush(stdout);

	asprintf(&result, "+%5lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_unsigned_int, unsigned_int_plus_large_width_neg_nb_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 32lu", d);
	fflush(stdout);

	asprintf(&result, "           +%lu", d);
	cr_assert_stdout_eq_str(result);
}
