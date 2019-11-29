/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 16:37:09 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/29 11:56:01 by lgutter       ########   odam.nl         */
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

	char *format = "%0ld";
	ft_init_info(format, &info);
	cr_assert_eq(info.lenmod, 0b00000010, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00000010);
	cr_assert_eq(info.flags, 0b00000010, "info.lenmod contains %i instead of %i!", info.flags, 0b00000010);
}

Test(init_info_test, width_lenmod_L)
{
	t_info info;

	char *format = "%5Ld";
	ft_init_info(format, &info);
	cr_assert_eq(info.lenmod, 0b00000001, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00000001);
	cr_assert_eq(info.width, (size_t)5, "info.lenmod contains %zu instead of %zu!", info.width, (size_t)5);
}

Test(init_info_test, presicion_lenmod_ll)
{
	t_info info;

	char *format = "%.5llf";
	ft_init_info(format, &info);
	cr_assert_eq(info.lenmod, 0b00001000, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00001000);
	cr_assert_eq(info.precision, (size_t)5, "info.lenmod contains %zu instead of %zu!", info.precision, (size_t)5);
}

Test(init_info_test, presicion_lenmod_hh)
{
	t_info info;

	char *format = "%#0hhf";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, 0b00000011, "info.lenmod contains %i instead of %i!", info.flags, 0b00000011);
	cr_assert_eq(info.lenmod, 0b00010000, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00010000);
}

Test(init_info_test, width_lenmod_h)
{
	t_info info;

	char *format = "%5hf";
	ft_init_info(format, &info);
	cr_assert_eq(info.width, (size_t)5, "info.lenmod contains %zu instead of %zu!", info.width, (size_t)5);
	cr_assert_eq(info.lenmod, 0b00000100, "info.lenmod contains %i instead of %i!", info.lenmod, 0b00000100);
}

Test(init_info_test, only_flags)
{
	t_info			info;
	unsigned char	expected = (0 | e_plus | e_zero);

	char *format = "%+0 ";
	ft_init_info(format, &info);
	cr_assert_eq(info.flags, expected, "info.flags contains %hhu instead of %hhu!", info.flags, expected);
}

Test(init_info_test, only_lenmod)
{
	t_info			info;
	unsigned char	expected = (e_h);

	char *format = "%h";
	ft_init_info(format, &info);
	cr_assert_eq(info.lenmod, expected, "info.flags contains %hhu instead of %hhu!", info.lenmod, expected);
}
