/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteint_upphex_tests.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:08:36 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/20 15:38:05 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

Test(test_printf_formatupphex, byteint_large_upphex, .init = redirect_std_out)
{
	unsigned short d;
	char *result = NULL;
	d = 56283;
	ft_printf("%07hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%07hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_medium_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 23;
	ft_printf("%0-5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_fortytwo_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%0-5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%-5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_space_upphex, .init = redirect_std_out)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("% hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_width_upphex, .init = redirect_std_out)
{
	long long d;
	char *result = NULL;
	d = 42;
	ft_printf("% 5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_large_nb_width_upphex, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 2123456987;
	ft_printf("%5hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%5hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_formatupphex, byteint_hash_upphex, .init = redirect_std_out)
{
	long d;
	char *result = NULL;
	d = 124;
	ft_printf("%#15hhX", (unsigned char)d);
	fflush(stdout);

	asprintf(&result, "%#15hhX", (unsigned char)d);
	cr_assert_stdout_eq_str(result);
}
