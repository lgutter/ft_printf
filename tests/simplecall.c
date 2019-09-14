/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplecall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 14:40:03 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/13 14:57:18 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out_for_simple_call(void)
{
		cr_redirect_stdout();
}

Test(redirect, test_foo, .init = redirect_std_out_for_simple_call) {
	ft_printf("foo");
	fflush(stdout);

	cr_assert_stdout_eq_str("foo");
}
