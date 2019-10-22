/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa_base_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 12:07:23 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/10/22 13:14:00 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test (valid_itoa_base, zero_ten)
{
	cr_assert_str_eq(ft_itoa_base(0, 10), "0");
}

Test (valid_itoa_base, five_one)
{
	cr_assert_str_eq(ft_itoa_base(5, 1), "11111");
}

Test (valid_itoa_base, ten_one)
{
	cr_assert_str_eq(ft_itoa_base(10, 1), "1111111111");
}

Test (valid_itoa_base, ten_binary)
{
	cr_assert_str_eq(ft_itoa_base(10, 2), "1010");
}

Test (valid_itoa_base, sixteen_binary)
{
	cr_assert_str_eq(ft_itoa_base(16, 2), "10000");
}

Test (valid_itoa_base, fifty_binary)
{
	cr_assert_str_eq(ft_itoa_base(50, 2), "110010");
}

Test (valid_itoa_base, min_fifty_binary)
{
	cr_assert_str_eq(ft_itoa_base(-50, 2), "-110010");
}

Test (valid_itoa_base, five_octal)
{
	cr_assert_str_eq(ft_itoa_base(5, 8), "5");
}

Test (valid_itoa_base, ten_octal)
{
	cr_assert_str_eq(ft_itoa_base(10, 8), "12");
}

Test (valid_itoa_base, sixteen_octal)
{
	cr_assert_str_eq(ft_itoa_base(16, 8), "20");
}

Test (valid_itoa_base, fifty_octal)
{
	cr_assert_str_eq(ft_itoa_base(50, 8), "62");
}

Test (valid_itoa_base, min_fifty_octal)
{
	cr_assert_str_eq(ft_itoa_base(-50, 8), "-62");
}

Test (valid_itoa_base, five_hex)
{
	cr_assert_str_eq(ft_itoa_base(5, 16), "5");
}

Test (valid_itoa_base, ten_hex)
{
	cr_assert_str_eq(ft_itoa_base(10, 16), "A");
}

Test (valid_itoa_base, sixteen_hex)
{
	cr_assert_str_eq(ft_itoa_base(16, 16), "10");
}

Test (valid_itoa_base, fifty_hex)
{
	cr_assert_str_eq(ft_itoa_base(50, 16), "32");
}

Test (valid_itoa_base, large_hex)
{
	cr_assert_str_eq(ft_itoa_base(124, 16), "7C");
}

Test (valid_itoa_base, min_large_hex)
{
	cr_assert_str_eq(ft_itoa_base(-124, 16), "-7C");
}

Test (valid_itoa_base, max_long_binary)
{
	cr_assert_str_eq(ft_itoa_base(9223372036854775807, 2), \
	"111111111111111111111111111111111111111111111111111111111111111");
}

Test (valid_itoa_base, max_long_hex)
{
	cr_assert_str_eq(ft_itoa_base(9223372036854775807, 16), "7FFFFFFFFFFFFFFF");
}

Test (valid_itoa_base, min_long_binary)
{
	cr_assert_str_eq(ft_itoa_base(-9223372036854775807, 2), \
	"-111111111111111111111111111111111111111111111111111111111111111");
}

Test (valid_itoa_base, min_long_hex)
{
	cr_assert_str_eq(ft_itoa_base(-9223372036854775807, 16), "-7FFFFFFFFFFFFFFF");
}

Test (invalid_itoa_base, ten_zero)
{
	cr_assert_eq(ft_itoa_base(10, 0), NULL);
}