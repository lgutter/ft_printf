/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatchar_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:23:04 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/11 14:21:30 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out_format_char(void)
{
    cr_redirect_stdout();
}

static void simplewriter(const char *str, unsigned long len)
{
	write(1, str, len);
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_char, test_simple_a, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char, test_b_width_1, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'b';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 1;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("b");
}

Test(test_format_char, test_42_width_5, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = '*';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("    *");
}

Test(test_format_char, test_semicolon_width_minus_3, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = ';';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 3;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str(";  ");
}

Test(test_format_char_undefined, test_a_width_4_zero, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 4;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("000a");
}

Test(test_format_char_undefined, test_a_width_7_zero_minus, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.flags |= e_minus;
	info.width = 7;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a000000");
}

Test(test_format_char_invalid, test_a_width_3_plus, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.width = 3;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("  a");
}

Test(test_format_char_invalid, test_a_width_3_plus_minus, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.flags |= e_minus;
	info.width = 3;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a  ");
}

Test(test_format_char_invalid, test_a_width_2_space, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 2;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str(" a");
}

Test(test_format_char_invalid, test_a_hash, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 0;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char_invalid, test_a_ll, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_ll;
	info.width = 0;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char_invalid, test_a_hh, .init = redirect_std_out_format_char) {
    t_info info;
	t_convinfo convinfo;
	char c;

	c = 'a';
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_hh;
	info.width = 0;
	ft_formatchar(&info, &convinfo);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

