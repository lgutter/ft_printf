/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_std_arg_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:28:17 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/14 18:00:09 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out(void)
{
    cr_redirect_stdout();
}

Test(redirect, test_char, .init = redirect_std_out) {
    ft_printf("ha%clo!", 'l');
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

    cr_assert_stdout_eq_str("ha llo!");
}

Test(redirect, test_error, .init = redirect_std_out) {
    ft_printf("ha% b!", "llo");
    fflush(stdout);

    cr_assert_stdout_eq_str("ha!");
}
