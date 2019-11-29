/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_flags_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 21:17:49 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/15 22:26:40 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(find_flags_simple_tests, no_flags)
{
	t_info info;
	int i = 0;
	unsigned char check = 0;
	info.flags = 0;

	i = ft_find_flags("hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 0);
}

Test(find_flags_simple_tests, only_plus)
{
	t_info info;
	int i = 1;
	unsigned char check = e_plus;
	info.flags = 0;

	i = ft_find_flags("%+hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 2);
}

Test(find_flags_simple_tests, three_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = check | e_plus | e_zero | e_hash;
	i = ft_find_flags("%+0#hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 4);
}

Test(find_flags_exclusive_tests, space_plus)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_plus;
	i = ft_find_flags("%+ hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 3);
}

Test(find_flags_exclusive_tests, minus_zero)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_minus;
	i = ft_find_flags("%-0hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 3);
}

Test(find_flags_exclusive_tests, all_five_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_minus | e_plus | e_hash;
	i = ft_find_flags("%0#- +hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 6);
}

Test(find_flags_duplicate_tests, double_0_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_plus | e_zero;
	i = ft_find_flags("%+00hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 4);
}

Test(find_flags_duplicate_tests, triple_plus_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_plus | e_zero;
	i = ft_find_flags("%+0++hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 5);
}

Test(find_flags_invalid_tests, letter_inbetween_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_zero | e_hash;
	i = ft_find_flags("%0#b +hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 3);
}

Test(find_flags_invalid_tests, whitespace_inbetween_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_plus | e_hash;
	i = ft_find_flags("%#+\t -hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 3);
}

Test(find_flags_invalid_tests, otherchar_inbetween_flags)
{
	t_info info;
	int i = 1;
	unsigned char check = 0;
	info.flags = 0;

	check = e_plus | e_minus;
	i = ft_find_flags("%-+0|#hello", &info, i);
	cr_assert_eq(info.flags, check);
	cr_assert_eq(i, 4);
}
