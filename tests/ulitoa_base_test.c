/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ulitoa_base_test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/22 11:14:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/22 11:54:08 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"
#include <limits.h>

Test (valid_ulitoa_base, five_one)
{
	cr_assert_str_eq(ft_ulitoa_base(5, 1), "11111");
}

Test (valid_ulitoa_base, zero_decimal)
{
	cr_assert_str_eq(ft_ulitoa_base(0, 10), "0");
}

Test (valid_ulitoa_base, ten_decimal)
{
	cr_assert_str_eq(ft_ulitoa_base(10, 10), "10");
}

Test (valid_ulitoa_base, five_binary)
{
	cr_assert_str_eq(ft_ulitoa_base(5, 2), "101");
}

Test (valid_ulitoa_base, ten_binary)
{
	cr_assert_str_eq(ft_ulitoa_base(10, 2), "1010");
}

Test (valid_ulitoa_base, fifty_binary)
{
	cr_assert_str_eq(ft_ulitoa_base(50, 2), "110010");
}

Test (valid_ulitoa_base, ten_octal)
{
	cr_assert_str_eq(ft_ulitoa_base(10, 8), "12");
}

Test (valid_ulitoa_base, fifty_octal)
{
	cr_assert_str_eq(ft_ulitoa_base(50, 8), "62");
}

Test (valid_ulitoa_base, ten_hex)
{
	cr_assert_str_eq(ft_ulitoa_base(10, 16), "A");
}

Test (valid_ulitoa_base, fifty_hex)
{
	cr_assert_str_eq(ft_ulitoa_base(50, 16), "32");
}

Test (valid_ulitoa_base, largenb_hex)
{
	cr_assert_str_eq(ft_ulitoa_base(124, 16), "7C");
}

Test (valid_ulitoa_base, max_ulong_ten)
{
	cr_assert_str_eq(ft_ulitoa_base(ULLONG_MAX, 10), "18446744073709551615");
}

Test (valid_ulitoa_base, max_ulong_binary)
{
	cr_assert_str_eq(ft_ulitoa_base(ULLONG_MAX, 2), \
    "1111111111111111111111111111111111111111111111111111111111111111");
}

Test (valid_ulitoa_base, max_ulong_octal)
{
	cr_assert_str_eq(ft_ulitoa_base(ULLONG_MAX, 8), "1777777777777777777777");
}

Test (valid_ulitoa_base, max_ulong_hex)
{
	cr_assert_str_eq(ft_ulitoa_base(ULLONG_MAX, 16), "FFFFFFFFFFFFFFFF");
}

Test (invalid_ulitoa_base, ten_zero)
{
	cr_assert_eq(ft_ulitoa_base(10, 0), NULL);
}