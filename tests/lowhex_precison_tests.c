/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lowhex_precison_tests.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:19:44 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:32:10 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void	redirect_std_out_lowhex_prec(void)
{
	cr_redirect_stdout();
}

Test(test_printf_precision_lowhex, lowhex_zero_23_zero_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%05.0x", d);
	fflush(stdout);

	asprintf(&result, "%05.0x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_zero_zero_zero_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.0x|", d);
	fflush(stdout);

	asprintf(&result, "|%0.0x|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_zero_zero_five_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%05.5x", d);
	fflush(stdout);

	asprintf(&result, "%05.5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_zero_zero_empty_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.x|", d);
	fflush(stdout);

	asprintf(&result, "|%0.x|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_2_width_zero_empty_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 0;
	ft_printf("%-2.x", d);
	fflush(stdout);

	asprintf(&result, "%-2.x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_zero_4242_five_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%0.5x", d);
	fflush(stdout);

	asprintf(&result, "%0.5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_4242_five_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5x", d);
	fflush(stdout);

	asprintf(&result, "%3.5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_5_width_4242_3_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5x", d);
	fflush(stdout);

	asprintf(&result, "%3.5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_4242_3_precision_d, .init = redirect_std_out_lowhex_prec)
{
	int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5x", d);
	fflush(stdout);

	asprintf(&result, "%-3.5x", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_4242_3_precision_hh_d, .init = redirect_std_out_lowhex_prec)
{
	char d;
	char *result = NULL;
	d = (char)4242;
	ft_printf("%-3.5hhx", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hhx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_4242_3_precision_h_d, .init = redirect_std_out_lowhex_prec)
{
	short d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5hx", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_0_3_precision_h_d, .init = redirect_std_out_lowhex_prec)
{
	short d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.5hx", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_4242_12_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.12lx", d);
	fflush(stdout);

	asprintf(&result, "%-3.12lx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_3_width_0_3_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.3lx", d);
	fflush(stdout);

	asprintf(&result, "%-3.3lx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_3_width_MAX_5_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-3.5lx", d);
	fflush(stdout);

	asprintf(&result, "%-3.5lx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_MAX_32_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-5.32lx", d);
	fflush(stdout);

	asprintf(&result, "%-5.32lx", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_MAX_asterisk_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-5.*lx", 32, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lx", 32, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_42_asterisk_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 42;
	ft_printf("%-5.*lx", -5, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lx", -5, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_lowhex, lowhex_minus_5_width_0_asterisk_precision_l_d, .init = redirect_std_out_lowhex_prec)
{
	long d;
	char *result = NULL;
	d = 0;
	ft_printf("%-5.*lx", 0, d);
	fflush(stdout);

	asprintf(&result, "%-5.*lx", 0, d);
	cr_assert_stdout_eq_str(result);
}
