/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 16:37:09 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/04 14:39:00 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test(init_info_test, flags_minus)
{
	t_info info;

	char *format = "%-d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00001000, "info.flags contains %i instead of %i!", info.flags, 0b00001000);
}

Test(init_info_test, flags_minus_space)
{
	t_info info;

	char *format = "% -d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00001100, "info.flags contains %i instead of %i!", info.flags, 0b00001100);
}

Test(init_info_test, flags_minus_space_hash)
{
	t_info info;

	char *format = "%# -d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00001101, "info.flags contains %i instead of %i!", info.flags, 0b00001101);
}

Test(init_info_test, flags_plus_zero)
{
	t_info info;

	char *format = "%+0d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00010010, "info.flags contains %i instead of %i!", info.flags, 0b00010010);
}

Test(init_info_test, flags_plus_width_precision)
{
	t_info info;

	char *format = "%+15.50d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00010000, "info.flags contains %i instead of %i!", info.flags, 0b00010000);
}

Test(init_info_test, flags_space_plus)
{
	t_info info;

	char *format = "% +d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00010000, "info.flags contains %i instead of %i!", info.flags, 0b00010000);
}

Test(init_info_test, flags_minus_zero)
{
	t_info info;

	char *format = "%0-d";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00001000, "info.flags contains %i instead of %i!", info.flags, 0b00001000);
}

Test(init_info_test, flags_lenmod)
{
	t_info info;

	char *format = "%ld";
	ft_init_info(format, &info);
	cr_assert_eq(info.lenmod, 0b00000010, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00000010);
}
