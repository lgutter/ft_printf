/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:31:48 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/11 17:38:27 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out_format_int(void)
{
    cr_redirect_stdout();
}

void simplewriter(const char *str, unsigned long len)
{
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
    t_convinfo convinfo;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 0;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("24");
}

Test(test_format_int, int_simple_minus_nb, .init = redirect_std_out_format_int) 
{
    t_info info;
    t_convinfo convinfo;
    int d;

    d = -24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 0;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("-24");
}

Test(test_format_int, int_width_nb, .init = redirect_std_out_format_int) 
{
    t_info info;
    t_convinfo convinfo;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = 0;
    info.width = 5;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("   24");
}

Test(test_format_int, int_minus_flag_nb, .init = redirect_std_out_format_int) 
{
    t_info info;
    t_convinfo convinfo;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_minus;
    info.width = 5;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("24   ");
}

Test(test_format_int, int_zero_flag_nb, .init = redirect_std_out_format_int) 
{
    t_info info;
    t_convinfo convinfo;
    int d;

    d = 24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_zero;
    info.width = 5;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("00024");
}

Test(test_format_int, int_zero_minus_nb, .init = redirect_std_out_format_int) 
{
    t_info info;
    t_convinfo convinfo;
    int d;

    d = -24;
    init_va_list(&info, d);
    info.writer = &simplewriter;
    info.flags = e_zero;
    info.width = 5;
    ft_formatint(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("-0024");
}
