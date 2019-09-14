/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_std_arg_test.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:28:17 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/09/14 13:35:10 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out(void)
{
    cr_redirect_stdout();
}

Test(redirect, test_outputs, .init = redirect_std_out) {
    ft_printf("ha%clo%c", 'l', '!');
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo!");
}