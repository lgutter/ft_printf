/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa_base_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 12:07:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/12 12:13:18 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test (valid_itoa_base, zero)
{
	cr_assert_str_eq(ft_itoa_base(0, 10), "0");
}