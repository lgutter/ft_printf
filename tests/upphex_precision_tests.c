/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   upphex_precision_tests.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:19:58 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:33:05 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void	redirect_std_out_upphex_prec(void)
{
	cr_redirect_stdout();
}

Test(test_printf_precision_upphex, upphex_zero_23_zero_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%05.0X", d);
	fflush(stdout);

	asprintf(&result, "%05.0X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_zero_zero_zero_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.0X|", d);
	fflush(stdout);

	asprintf(&result, "|%0.0X|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_zero_zero_five_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%05.5X", d);
	fflush(stdout);

	asprintf(&result, "%05.5X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_zero_zero_empty_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.X|", d);
	fflush(stdout);

	asprintf(&result, "|%0.X|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_2_width_zero_empty_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%-2.X", d);
	fflush(stdout);

	asprintf(&result, "%-2.X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_zero_4242_five_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%0.5X", d);
	fflush(stdout);

	asprintf(&result, "%0.5X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_4242_five_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5X", d);
	fflush(stdout);

	asprintf(&result, "%3.5X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_5_width_4242_3_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5X", d);
	fflush(stdout);

	asprintf(&result, "%3.5X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_4242_3_precision_d, .init = redirect_std_out_upphex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5X", d);
	fflush(stdout);

	asprintf(&result, "%-3.5X", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_4242_3_precision_hh_d, .init = redirect_std_out_upphex_prec)
{
	char d;
	char *result = NULL;
	d = (char)4242;
	ft_printf("%-3.5hhX", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hhX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_4242_3_precision_h_d, .init = redirect_std_out_upphex_prec)
{
	short d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5hX", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_0_3_precision_h_d, .init = redirect_std_out_upphex_prec)
{
	short d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.5hX", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_4242_12_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.12lX", d);
	fflush(stdout);

	asprintf(&result, "%-3.12lX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_3_width_0_3_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.3lX", d);
	fflush(stdout);

	asprintf(&result, "%-3.3lX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_3_width_MAX_5_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-3.5lX", d);
	fflush(stdout);

	asprintf(&result, "%-3.5lX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_MAX_32_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-5.32lX", d);
	fflush(stdout);

	asprintf(&result, "%-5.32lX", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_MAX_asterisk_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-5.*lX", 32, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lX", 32, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_42_asterisk_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 42;
	ft_printf("%-5.*lX", -5, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lX", -5, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_upphex, upphex_minus_5_width_0_asterisk_precision_l_d, .init = redirect_std_out_upphex_prec)
{
	long d;
	char *result = NULL;
	d = 0;
	ft_printf("%-5.*lX", 0, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lX", 0, d);
	cr_assert_stdout_eq_str(result);
}
