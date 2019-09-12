/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplecall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 14:40:03 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/11 18:27:50 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int	ft_printf(char *str);

void redirect_std_out(void)
{
    cr_redirect_stdout();
}

Test(redirect, test_outputs, .init = redirect_std_out) {
    ft_printf("foo");
    fflush(stdout);

    cr_assert_stdout_eq_str("foo");
}
