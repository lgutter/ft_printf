/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ulltoa_base_low_test.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/22 11:14:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/14 17:05:22 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <limits.h>

Test (valid_ulltoa_base_low, five_one)
{
	cr_assert_str_eq(ft_ulltoa_base_low(5, 1), "11111");
}

Test (valid_ulltoa_base_low, zero_decimal)
{
	cr_assert_str_eq(ft_ulltoa_base_low(0, 10), "0");
}

Test (valid_ulltoa_base_low, ten_decimal)
{
	cr_assert_str_eq(ft_ulltoa_base_low(10, 10), "10");
}

Test (valid_ulltoa_base_low, five_binary)
{
	cr_assert_str_eq(ft_ulltoa_base_low(5, 2), "101");
}

Test (valid_ulltoa_base_low, ten_binary)
{
	cr_assert_str_eq(ft_ulltoa_base_low(10, 2), "1010");
}

Test (valid_ulltoa_base_low, fifty_binary)
{
	cr_assert_str_eq(ft_ulltoa_base_low(50, 2), "110010");
}

Test (valid_ulltoa_base_low, ten_octal)
{
	cr_assert_str_eq(ft_ulltoa_base_low(10, 8), "12");
}

Test (valid_ulltoa_base_low, fifty_octal)
{
	cr_assert_str_eq(ft_ulltoa_base_low(50, 8), "62");
}

Test (valid_ulltoa_base_low, ten_hex)
{
	cr_assert_str_eq(ft_ulltoa_base_low(10, 16), "a");
}

Test (valid_ulltoa_base_low, fifty_hex)
{
	cr_assert_str_eq(ft_ulltoa_base_low(50, 16), "32");
}

Test (valid_ulltoa_base_low, largenb_hex)
{
	cr_assert_str_eq(ft_ulltoa_base_low(124, 16), "7c");
}

Test (valid_ulltoa_base_low, max_ulong_ten)
{
	cr_assert_str_eq(ft_ulltoa_base_low(ULLONG_MAX, 10), "18446744073709551615");
}

Test (valid_ulltoa_base_low, max_ulong_binary)
{
	cr_assert_str_eq(ft_ulltoa_base_low(ULLONG_MAX, 2), \
    "1111111111111111111111111111111111111111111111111111111111111111");
}

Test (valid_ulltoa_base_low, max_ulong_octal)
{
	cr_assert_str_eq(ft_ulltoa_base_low(ULLONG_MAX, 8), "1777777777777777777777");
}

Test (valid_ulltoa_base_low, max_ulong_hex)
{
	cr_assert_str_eq(ft_ulltoa_base_low(ULLONG_MAX, 16), "ffffffffffffffff");
}

Test (invalid_ulltoa_base_low, ten_zero)
{
	cr_assert_eq(ft_ulltoa_base_low(10, 0), NULL);
}
