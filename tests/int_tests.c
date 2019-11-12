/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/12 18:41:57 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

void redirect_std_out_format_int(void)
{
    cr_redirect_stdout();
}

static void simplewriter(void *target, const char *str, unsigned long len)
{
	int fd;

	fd = *((int *)target);
	if (len > 0)
	{
		write(1, str, len);
	}
	else
	{
		write(1, str, ft_strlen(str));
	}
}

void init_va_list(t_info *info, ...)
{
    va_start(info->arguments, info);
}

Test(test_format_int, int_simple_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 0;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("24");
}

Test(test_format_int, int_simple_minus_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = -24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 0;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("-24");
}

Test(test_format_int, int_width_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 5;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("   24");
}

Test(test_format_int, int_minus_flag_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_minus;
    info.width = 5;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("24   ");
}

Test(test_format_int, int_zero_flag_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_zero;
    info.width = 5;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("00024");
}

Test(test_format_int, int_zero_minus_nb, .init = redirect_std_out_format_int)
{
    t_info info;
    int d;

    d = -24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_zero;
    info.width = 5;
    ft_formatint(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("-0024");
}
