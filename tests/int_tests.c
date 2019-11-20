/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:39:00 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_format_int(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_int, int_zero_negative_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05d", d);
	fflush(stdout);

	asprintf(&result, "%05d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_negative_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%05i", d);
	fflush(stdout);

	asprintf(&result, "%05i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_negative_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_negative_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("% 5d", d);
	fflush(stdout);

	asprintf(&result, "% 5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_minus_negative_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = -24;
	ft_printf("%-05d", d);
	fflush(stdout);

	asprintf(&result, "%-5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_minus_nb_d, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5d", d);
	fflush(stdout);

	asprintf(&result, "%-5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_zero_minus_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5i", d);
	fflush(stdout);

	asprintf(&result, "%-5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_nb_i, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% i", d);
	fflush(stdout);

	asprintf(&result, "% i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_space_nb_i_larger_width, .init = redirect_std_out_format_int)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5i", d);
	fflush(stdout);

	asprintf(&result, "% 5i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_plus_large_nb_i, .init = redirect_std_out_format_int)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 5i", d);
	fflush(stdout);

	asprintf(&result, "%+5li", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_plus_large_nb_largewidth_d, .init = redirect_std_out_format_int)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%+ 30d", d);
	fflush(stdout);

	asprintf(&result, "%+30ld", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_int, int_plus_large_neg_nb_i, .init = redirect_std_out_format_int)
{
	long d;
	char *result = NULL;
	d = -2123456987;
	ft_printf("%+ 5i", d);
	fflush(stdout);

	asprintf(&result, "%+5li", d);
	cr_assert_stdout_eq_str(result);
}
