/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   middle_width_tests.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:09:09 by lgutter        #+#    #+#                */
/*   Updated: 2019/12/04 16:44:40 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_middle_width, str_even_width_even_len, .init = redirect_std_out)
{
	char *str = "test";
	ft_printf("%^8s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("  test  ");
}

Test(test_middle_width, str_even_width_uneven_len, .init = redirect_std_out)
{
	char *str = "hoi";
	ft_printf("%^8s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("   hoi  ");
}

Test(test_middle_width, str_even_width_uneven_len_minus, .init = redirect_std_out)
{
	char *str = "hoi";
	ft_printf("%^-8s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("  hoi   ");
}

Test(test_middle_width, str_uneven_width_even_len, .init = redirect_std_out)
{
	char *str = "test";
	ft_printf("%^9s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("   test  ");
}

Test(test_middle_width, str_uneven_width_even_len_minus, .init = redirect_std_out)
{
	char *str = "test";
	ft_printf("%^-9s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("  test   ");
}

Test(test_middle_width, str_uneven_width_uneven_len, .init = redirect_std_out)
{
	char *str = "hallo";
	ft_printf("%^9s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("  hallo  ");
}

Test(test_middle_width, str_uneven_width_uneven_len_minus, .init = redirect_std_out)
{
	char *str = "hallo";
	ft_printf("%^-9s", str);
	fflush(stdout);

	cr_assert_stdout_eq_str("  hallo  ");
}

Test(test_middle_width, int_even_width_even_len, .init = redirect_std_out)
{
	int d = 4242;
	ft_printf("%^8d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  4242  ");
}

Test(test_middle_width, int_even_width_uneven_len, .init = redirect_std_out)
{
	int d = 42420;
	ft_printf("%^8d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  42420 ");
}

Test(test_middle_width, int_even_width_uneven_len_minus, .init = redirect_std_out)
{
	int d = 42420;
	ft_printf("%^-8d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 42420  ");
}

Test(test_middle_width, int_uneven_width_even_len, .init = redirect_std_out)
{
	int d = 4242;
	ft_printf("%^9d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("   4242  ");
}

Test(test_middle_width, int_uneven_width_even_len_minus, .init = redirect_std_out)
{
	int d = 4242;
	ft_printf("%^-9d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  4242   ");
}

Test(test_middle_width, int_uneven_width_uneven_len, .init = redirect_std_out)
{
	int d = 42420;
	ft_printf("%^9d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  42420  ");
}

Test(test_middle_width, int_uneven_width_uneven_len_minus, .init = redirect_std_out)
{
	int d = 42420;
	ft_printf("%^-9d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  42420  ");
}

Test(test_middle_width, test_zero_flag, .init = redirect_std_out)
{
	int d = 42420;
	ft_printf("%0^9d", d);
	fflush(stdout);

	cr_assert_stdout_eq_str("  42420  ");
}

Test(test_middle_width, test_precision, .init = redirect_std_out)
{
	float f = 4.4242;
	ft_printf("%^-9.4f", f);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 4.4242  ");
}

Test(test_middle_width, test_hash_hex, .init = redirect_std_out)
{
	int d = 4243;
	ft_printf("%#0^-9.4x", d);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 0x1093  ");
}

Test(test_middle_width, test_hash_octal, .init = redirect_std_out)
{
	int d = 4243;
	ft_printf("%#0^-9.4o", d);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 010223  ");
}
