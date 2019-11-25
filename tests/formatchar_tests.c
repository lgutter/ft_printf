/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatchar_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:23:04 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/25 16:25:09 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
    cr_redirect_stdout();
}

static void simplewriter(void *target, unsigned long long *totallen, const char *str, unsigned long len)
{
	int fd;

		if (*totallen == 42)
		dprintf(2,"");
	fd = *((int *)target);
	write(fd, str, len);
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 'c';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

Test(test_format_char, test_simple_a, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char, test_b_width_1, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'b';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 1;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("b");
}

Test(test_format_char, test_42_width_5, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = '*';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("    *");
}

Test(test_format_char, test_semicolon_width_minus_3, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = ';';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 3;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str(";  ");
}

Test(test_format_char_undefined, test_a_width_4_zero, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 4;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("000a");
}

Test(test_format_char_undefined, test_a_width_7_zero_minus, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.flags |= e_minus;
	info.width = 7;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a000000");
}

Test(test_format_char_invalid, test_a_width_3_plus, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.width = 3;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("  a");
}

Test(test_format_char_invalid, test_a_width_3_plus_minus, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.flags |= e_minus;
	info.width = 3;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a  ");
}

Test(test_format_char_invalid, test_a_width_2_space, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 2;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str(" a");
}

Test(test_format_char_invalid, test_a_hash, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 0;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char_invalid, test_a_ll, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_ll;
	info.width = 0;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_char_invalid, test_a_hh, .init = redirect_std_out) {
    t_info info;
	char c;
	int fd;

	fd = STDOUT_FILENO;
	c = 'a';
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_hh;
	info.width = 0;
	info.target = &fd;
	ft_formatchar(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

