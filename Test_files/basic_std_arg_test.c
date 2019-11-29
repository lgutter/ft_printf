/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_std_arg_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:28:17 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/29 11:38:38 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
    cr_redirect_stdout();
}

Test(redirect, test_char, .init = redirect_std_out) {
    ft_printf("ha%clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, test_empty_conversion, .init = redirect_std_out) {
    ft_printf("ha%", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha");
}

Test(redirect, test_char_space, .init = redirect_std_out) {
    ft_printf("ha% clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, test_string, .init = redirect_std_out) {
    ft_printf("ha%s!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, test_space, .init = redirect_std_out) {
    ft_printf("ha%  s!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, test_unknown, .init = redirect_std_out) {
    ft_printf("ha% b!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hab!");
}

Test(redirect, test_endofstring, .init = redirect_std_out) {
    ft_printf("ha%15k", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha              k");
}

Test(redirect, test_unknownminuswidth, .init = redirect_std_out) {
    ft_printf("ha%-15k", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("hak               ");
}
