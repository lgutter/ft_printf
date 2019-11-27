/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_width_tests.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 11:32:15 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/27 18:08:46 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"
#include <stdio.h>

static void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(test_width, width_char_none, .init = redirect_stdout) {
    ft_printf("ha%clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(test_width, width_char_ten, .init = redirect_stdout) {
    ft_printf("ha%10clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha         llo!");
}

Test(test_width, width_char_fourty, .init = redirect_stdout) {
    ft_printf("ha%40clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha                                       llo!");
}

Test(test_width, width_char_zero_ten, .init = redirect_stdout) {
    ft_printf("ha%010clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha000000000llo!");
}

Test(test_width, width_char_zero_fourty, .init = redirect_stdout) {
    ft_printf("ha%040clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha000000000000000000000000000000000000000llo!");
}

Test(test_width, width_char_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%-10clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hal         lo!");
}

Test(test_width, width_string_none, .init = redirect_stdout) {
    ft_printf("ha%so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(test_width, width_string_ten, .init = redirect_stdout) {
    ft_printf("ha%10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha        llo!");
}

Test(test_width, width_string_zero_ten, .init = redirect_stdout) {
    ft_printf("ha%010so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha00000000llo!");
}

Test(test_width, width_string_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%-10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hall        o!");
}

Test(test_width, width_string_zer_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%0-10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hall        o!");
}

Test(test_width, zero_minus_asterisk_string, .init = redirect_stdout)
{
	char *str = "hoi";
	char *result = NULL;
	ft_printf("%0-*s", 5, str);
	fflush(stdout);

	asprintf(&result, "%-*s", 5, str);
	cr_assert_stdout_eq_str(result);
}

Test(test_width, zero_minus_asterisk_int, .init = redirect_stdout)
{
	int d;
	char *result = NULL;
	d = 424242;
	ft_printf("%0-*i", 12, d);
	fflush(stdout);

	asprintf(&result, "%-*i", 12, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_width, double_minus_asterisk_int, .init = redirect_stdout)
{
	int d;
	char *result = NULL;
	d = 424242;
	ft_printf("%--*i", 12, d);
	fflush(stdout);

	asprintf(&result, "%--*i", 12, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_width, double_minus_twelve_int, .init = redirect_stdout)
{
	int d;
	char *result = NULL;
	d = 424242;
	ft_printf("%--12i", d);
	fflush(stdout);

	asprintf(&result, "%--12i", d);
	cr_assert_stdout_eq_str(result);
}

Test(test_width, asterisk_negative_width_int, .init = redirect_stdout)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%*i", -5, d);
	fflush(stdout);

	asprintf(&result, "%*i", -5, d);
	cr_assert_stdout_eq_str(result);
}

Test(test_width, minus_asterisk_negative_width_int, .init = redirect_stdout)
{
	int d;
	char *result = NULL;
	d = 42;
	ft_printf("%-*i", -5, d);
	fflush(stdout);

	asprintf(&result, "%-*i", -5, d);
	cr_assert_stdout_eq_str(result);
}
