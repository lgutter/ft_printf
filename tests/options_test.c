/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 16:37:09 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/31 18:44:37 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(redirect, option_fail_nb, .init = redirect_stdout) {
    ft_printf("I% cre", 'm');
    fflush(stdout);

    cr_assert_stdout_eq_str("I mre");
}
