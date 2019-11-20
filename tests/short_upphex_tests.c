/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_upphex_tests.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:02:37 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 16:05:19 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_format_upphex, short_large_hex_upp, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%07hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, short_medium_upp, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%-5hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, short_fortytwo, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%05hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%05hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, short_space_upp, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}


Test(test_printf_format_upphex, short_width_upp, .init = redirect_std_out)
{
	short d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%5hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, short_large_nb_width_upp, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%5hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_upphex, short_hash_upp, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15hX", (unsigned short)d);
	fflush(stdout);

	asprintf(&result, "%#15hX", (unsigned short)d);
	cr_assert_stdout_eq_str(result);
}
