/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_precision_tests.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:44:54 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/18 16:51:46 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void	redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_precision_int, int_zero_23_zero_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%05.0d", d);
	fflush(stdout);

	asprintf(&result, "%05.0d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_neg_23_zero_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -23;
	ft_printf("%05.0d", d);
	fflush(stdout);

	asprintf(&result, "%05.0d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_zero_zero_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.0d|", d);
	fflush(stdout);

	asprintf(&result, "|%0.0d|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_zero_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%05.5d", d);
	fflush(stdout);

	asprintf(&result, "%05.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_zero_empty_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.d|", d);
	fflush(stdout);

	asprintf(&result, "|%0.d|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_zero_empty_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%+.d", d);
	fflush(stdout);

	asprintf(&result, "%+.d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_minus_2_width_zero_empty_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%-2.d", d);
	fflush(stdout);

	asprintf(&result, "%-2.d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%0.5d", d);
	fflush(stdout);

	asprintf(&result, "%0.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_zero_neg_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%0.5d", d);
	fflush(stdout);

	asprintf(&result, "%0.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5d", d);
	fflush(stdout);

	asprintf(&result, "%3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_neg_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%12.5d", d);
	fflush(stdout);

	asprintf(&result, "%12.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+.5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_neg_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+.5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_666666_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 666666;
	ft_printf("%+.5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_neg_666666_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -666666;
	ft_printf("%+.5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_666666_empty_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 666666;
	ft_printf("%+.d", d);
	fflush(stdout);

	asprintf(&result, "%+.d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_neg_666666_empty_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -666666;
	ft_printf("%+.d", d);
	fflush(stdout);

	asprintf(&result, "%+.d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_space_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+ .5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_space_neg_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+ .5d", d);
	fflush(stdout);

	asprintf(&result, "%+.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_space_3_width_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+ 3.5d", d);
	fflush(stdout);

	asprintf(&result, "%+3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_plus_space_neg_3_width_4242_five_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+ 3.5d", d);
	fflush(stdout);

	asprintf(&result, "%+3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5d", d);
	fflush(stdout);

	asprintf(&result, "%3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_neg_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%3.5d", d);
	fflush(stdout);

	asprintf(&result, "%3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_space_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("% 3.5d", d);
	fflush(stdout);

	asprintf(&result, "% 3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_space_neg_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("% 3.5d", d);
	fflush(stdout);

	asprintf(&result, "% 3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_minus_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5d", d);
	fflush(stdout);

	asprintf(&result, "%-3.5d", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_int, int_minus_neg_5_width_4242_3_precision_d, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%-3.5d", d);
	fflush(stdout);

	asprintf(&result, "%-3.5d", d);
	cr_assert_stdout_eq_str(result);
}
