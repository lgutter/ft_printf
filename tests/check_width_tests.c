/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_width_tests.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 11:32:15 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/10 17:52:49 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(redirect, width_char_none, .init = redirect_stdout) {
    ft_printf("ha%clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, width_char_ten, .init = redirect_stdout) {
    ft_printf("ha%10clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha         llo!");
}

Test(redirect, width_char_fourty, .init = redirect_stdout) {
    ft_printf("ha%40clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha                                       llo!");
}

Test(redirect, width_char_zero_ten, .init = redirect_stdout) {
    ft_printf("ha%010clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha000000000llo!");
}

Test(redirect, width_char_zero_fourty, .init = redirect_stdout) {
    ft_printf("ha%040clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("ha000000000000000000000000000000000000000llo!");
}

Test(redirect, width_char_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%-10clo!", 'l');
    fflush(stdout);

    cr_assert_stdout_eq_str("hal         lo!");
}

Test(redirect, width_string_none, .init = redirect_stdout) {
    ft_printf("ha%so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}

Test(redirect, width_string_ten, .init = redirect_stdout) {
    ft_printf("ha%10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha        llo!");
}

Test(redirect, width_string_zero_ten, .init = redirect_stdout) {
    ft_printf("ha%010so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha00000000llo!");
}

Test(redirect, width_string_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%-10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hall        o!");
}

Test(redirect, width_string_zer_minus_ten, .init = redirect_stdout) {
    ft_printf("ha%0-10so!", "ll");
    fflush(stdout);

    cr_assert_stdout_eq_str("hall        o!");
}
