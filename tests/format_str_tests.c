/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_str_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:51:45 by lgutter        #+#    #+#                */
/*   Updated: 2019/11/27 18:12:02 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

static void redirect_std_out(void)
{
    cr_redirect_stdout();
}

static void		simplewriter(void *target, unsigned long long *totallen, const char *str, size_t len)
{
	int fd;

	fd = *((int *)target);
	if (len > 0)
	{
		write(fd, str, len);
	}
	else
	{
		write(fd, str, ft_strlen(str));
	}
	if (*totallen == 42)
		dprintf(2,"");
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 's';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

Test(test_format_str, test_simple_a, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "a";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a");
}

Test(test_format_str, test_b_width_1, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "b";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 1;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("b");
}

Test(test_format_str, test_42_width_5, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "*";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 5;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("    *");
}

Test(test_format_str, test_semicolon_p_width_minus_3, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = ";p";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 3;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str(";p ");
}

Test(test_format_str, test_semicolon_p_width_8, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = ";p";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 8;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str(";p      ");
}

Test(test_format_str_undefined, test_ab_width_4_zero, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "ab";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 4;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("00ab");
}

Test(test_format_str_undefined, test_a_width_7_minus, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "hello";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 7;
	info.target = &fd;
	info.precfound = 1;
	info.precision = 3;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("hel    ");
}

Test(test_format_str_invalid, test_c_width_3_plus, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "c";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.width = 3;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("  c");
}

Test(test_format_str_invalid, test_a_width_3_plus_minus, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "a";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_plus;
	info.flags |= e_minus;
	info.width = 3;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("a  ");
}

Test(test_format_str_invalid, test_a_width_2_space, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "a";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_space;
	info.width = 2;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str(" a");
}

Test(test_format_str_invalid, test_string_hash, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "testerdetest";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = e_hash;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("testerdetest");
}

Test(test_format_str_invalid, test_string_ll, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "hallo";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_ll;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("hallo");
}

Test(test_format_str_invalid, test_string_hh, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "hey";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_hh;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("hey");
}

Test(test_format_str_invalid, test_string_writer, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = "halo";
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_hh;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("halo");
}

Test(test_format_str_invalid, test_string_NULL, .init = redirect_std_out) {
    t_info info;
	char *c;
	int fd;

	fd = STDOUT_FILENO;
	c = NULL;
	init_struct(&info);
	init_va_list(&info, c);
	info.writer = &simplewriter;
	info.flags = 0;
	info.lenmod = e_hh;
	info.width = 0;
	info.target = &fd;
	info.precfound = -1;
	ft_formatstring(&info);
    fflush(stdout);

    cr_assert_stdout_eq_str("(null)");
}

Test(test_format_str_precision, test_string_5_precision, .init = redirect_std_out) {
	char *str = "hello";
	char *result = NULL;
	ft_printf("%.5s", str);
	fflush(stdout);

	asprintf(&result, "%.5s", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_empty_precision, .init = redirect_std_out) {
	char *str = "hello";
	char *result = NULL;
	ft_printf("|%.s|", str);
	fflush(stdout);

	asprintf(&result, "|%.s|", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_small_precision, .init = redirect_std_out) {
	char *str = "hello";
	char *result = NULL;
	ft_printf("%.2s", str);
	fflush(stdout);

	asprintf(&result, "%.2s", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_small_precision_large_width, .init = redirect_std_out) {
	char *str = "hello";
	char *result = NULL;
	ft_printf("%32.2s", str);
	fflush(stdout);

	asprintf(&result, "%32.2s", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_large_precision_small_width, .init = redirect_std_out) {
	char *str = "hello";
	char *result = NULL;
	ft_printf("%3.23s", str);
	fflush(stdout);

	asprintf(&result, "%3.23s", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_zero_prefix_precision_small_width_NULL, .init = redirect_std_out) {
	char *str = NULL;
	char *result = NULL;
	ft_printf("%3.03s", str);
	fflush(stdout);

	asprintf(&result, "%3.03s", str);
	cr_assert_stdout_eq_str(result);
}

Test(test_format_str_precision, test_string_zero_prefix_precision_asterisk_negative, .init = redirect_std_out) {
	char *str = "42";
	char *result = NULL;
	ft_printf("%3.*s", -5, str);
	fflush(stdout);

	asprintf(&result, "%3.*s", -5, str);
	cr_assert_stdout_eq_str(result);
}
