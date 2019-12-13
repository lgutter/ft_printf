/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:28:17 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/12/13 11:19:48 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"
#include <stdio.h>

static void redirect_std_out(void)
{
    cr_redirect_stdout();
}

Test(ft_dprintf_basics, test_char, .init = redirect_std_out) {
    ft_dprintf(1, "ha%clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(ft_dprintf_basics, test_empty_conversion, .init = redirect_std_out) {
    ft_dprintf(1, "ha%", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha");
}

Test(ft_dprintf_basics, test_char_space, .init = redirect_std_out) {
    ft_dprintf(1, "ha% clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(ft_dprintf_basics, test_string, .init = redirect_std_out) {
    ft_dprintf(1, "ha%s!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(ft_dprintf_basics, test_space, .init = redirect_std_out) {
    ft_dprintf(1, "ha%  s!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(ft_dprintf_basics, test_unknown, .init = redirect_std_out) {
    ft_dprintf(1, "ha% b!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hab!");
}

Test(ft_dprintf_basics, test_endofstring, .init = redirect_std_out) {
    ft_dprintf(1, "ha%15k", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha              k");
}

Test(ft_dprintf_basics, test_unknownminuswidth, .init = redirect_std_out) {
    ft_dprintf(1, "ha%-15k", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hak               ");
}

Test(ft_dprintf_basics, test_pointer, .init = redirect_std_out) {
	char *result = NULL;
    ft_dprintf(1, "ha%-15p", (void *)12345);
    fflush(stdout);

	asprintf(&result, "ha%-15p", (void *)12345);
    cr_assert_stdout_eq_str(result);
}

Test(ft_dprintf_basics, test_integer, .init = redirect_std_out) {
	char *result = NULL;
	int d = 42424242;
    ft_dprintf(1, "%+5.2d", d);
    fflush(stdout);

	asprintf(&result, "%+5.2d", d);
    cr_assert_stdout_eq_str(result);
}

Test(ft_dprintf_basics, test_float, .init = redirect_std_out) {
	char *result = NULL;
	float f = 4242.424242;
    ft_dprintf(1, "%+42.15f", f);
    fflush(stdout);

	asprintf(&result, "%+42.15f", f);
    cr_assert_stdout_eq_str(result);
}

