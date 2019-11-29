/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_int_precision_tests.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:44:54 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/19 11:40:19 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void	redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_23_zero_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 23;
	ft_printf("%05.0u", d);
	fflush(stdout);

	asprintf(&result, "%05.0u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_neg_23_zero_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -23;
	ft_printf("%05.0u", d);
	fflush(stdout);

	asprintf(&result, "%05.0u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_zero_zero_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.0u|", d);
	fflush(stdout);

	asprintf(&result, "|%0.0u|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_zero_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("%05.5u", d);
	fflush(stdout);

	asprintf(&result, "%05.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_zero_empty_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("|%0.u|", d);
	fflush(stdout);

	asprintf(&result, "|%0.u|", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_zero_empty_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("%+.u", d);
	fflush(stdout);

	asprintf(&result, "+%.u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_2_width_zero_empty_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("%-2.u", d);
	fflush(stdout);

	asprintf(&result, "%-2.u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%0.5u", d);
	fflush(stdout);

	asprintf(&result, "%0.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_zero_neg_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%0.5u", d);
	fflush(stdout);

	asprintf(&result, "%0.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5u", d);
	fflush(stdout);

	asprintf(&result, "%3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_neg_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%12.5u", d);
	fflush(stdout);

	asprintf(&result, "%12.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+.5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_neg_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+.5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_666666_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 666666;
	ft_printf("%+.5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_neg_666666_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -666666;
	ft_printf("%+.5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_666666_empty_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 666666;
	ft_printf("%+.u", d);
	fflush(stdout);

	asprintf(&result, "+%.u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_neg_666666_empty_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -666666;
	ft_printf("%+.u", d);
	fflush(stdout);

	asprintf(&result, "+%.u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_space_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+ .5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_space_neg_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+ .5u", d);
	fflush(stdout);

	asprintf(&result, "+%.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_space_3_width_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%+ 3.5u", d);
	fflush(stdout);

	asprintf(&result, "+%3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_plus_space_neg_3_width_4242_five_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%+ 3.5u", d);
	fflush(stdout);

	asprintf(&result, "+%3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%3.5u", d);
	fflush(stdout);

	asprintf(&result, "%3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_neg_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%3.5u", d);
	fflush(stdout);

	asprintf(&result, "%3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_space_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("% 3.5u", d);
	fflush(stdout);

	asprintf(&result, " %3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_space_neg_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("% 3.5u", d);
	fflush(stdout);

	asprintf(&result, " %3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5u", d);
	fflush(stdout);

	asprintf(&result, "%-3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_neg_5_width_4242_3_precision_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = -4242;
	ft_printf("%-3.5u", d);
	fflush(stdout);

	asprintf(&result, "%-3.5u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_4242_3_precision_hh_u, .init = redirect_std_out)
{
	unsigned char d;
	char *result = NULL;
	d = (unsigned char)4242;
	ft_printf("%-3.5hhu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hhu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_neg_5_width_4242_3_precision_hh_u, .init = redirect_std_out)
{
	unsigned char d;
	char *result = NULL;
	d = (unsigned char)-4242;
	ft_printf("%-3.5hhu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hhu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_4242_3_precision_h_u, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.5hu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_neg_5_width_4242_3_precision_h_u, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = -4242;
	ft_printf("%-3.5hu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_0_3_precision_h_u, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.5hu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5hu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_neg_32768_9_precision_h_u, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = -32768;
	ft_printf("%-3.9hu", d);
	fflush(stdout);

	asprintf(&result, "%-3.9hu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_4242_12_precision_l_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 4242;
	ft_printf("%-3.12lu", d);
	fflush(stdout);

	asprintf(&result, "%-3.12lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_3_width_neg_4242_5_precision_l_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = -4242;
	ft_printf("%-3.5lu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_3_width_0_3_precision_l_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3.3lu", d);
	fflush(stdout);

	asprintf(&result, "%-3.3lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_3_width_MAX_5_precision_h_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-3.5lu", d);
	fflush(stdout);

	asprintf(&result, "%-3.5lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_MAX_32_precision_h_u, .init = redirect_std_out)
{
	unsigned long d;
	char *result = NULL;
	d = 9223372036854775807;
	ft_printf("%-5.32lu", d);
	fflush(stdout);

	asprintf(&result, "%-5.32lu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_5_width_MAX_UNSIGNED_32_precision_h_u, .init = redirect_std_out)
{
	unsigned long long d;
	char *result = NULL;
	d = 18446744073709551615ULL;
	ft_printf("%-5.32llu", d);
	fflush(stdout);

	asprintf(&result, "%-5.32llu", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_3_width_0_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("%3u", d);
	fflush(stdout);

	asprintf(&result, "%3u", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_precision_unsigned_int, unsigned_int_minus_3_width_0_u, .init = redirect_std_out)
{
	unsigned int d;
	char *result = NULL;
	d = 0;
	ft_printf("%-3u", d);
	fflush(stdout);

	asprintf(&result, "%-3u", d);
	cr_assert_stdout_eq_str(result);
}

