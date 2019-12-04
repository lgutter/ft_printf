/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 09:29:24 by lgutter        #+#    #+#                */
/*   Updated: 2019/12/04 12:36:19 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"
#include <float.h>
#include <math.h>

static void redirect_std_out(void)
{
	cr_redirect_stdout();
}

static void simplewriter(void *target, unsigned long long *totallen, const char *str, size_t len)
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

static void	init_struct(t_info *info)
{
	info->flags = 0;
	info->lenmod = 0;
	info->conv = 'f';
	info->precfound = -1;
	info->sign = 0;
	info->len = 0;
	info->width = 0;
	info->precision = 0;
	info->totallen = 0;
}

static void init_va_list(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_signed_float, float_simple_whole_nb, .init = redirect_std_out)
{
	t_info info;
	float f;
	int fd;

	fd = 1;
	f = 24;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24.000000");
}

Test(test_format_signed_float, float_simple_double_nb, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 34624.13454;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("34624.134540");
}

Test(test_format_signed_float, float_simple_float_nb, .init = redirect_std_out)
{
	t_info info;
	float f;
	int fd;

	fd = 1;
	f = 24.13454;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("24.134541");
}

Test(test_format_signed_float, float_simple_MIN_INT_nb, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = (double)INT32_MIN;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-2147483648.000000");
}

Test(test_format_signed_float, float_simple_MIN_INT_min_1_nb, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = (double)INT32_MIN - 1;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-2147483649.000000");
}


Test(test_format_signed_float, float_round_double_on_precision_edge, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.99999949;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("8.999999");
}

Test(test_format_signed_float, float_round_double_almost_on_precision_edge, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.99999949;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.precision = 7;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("8.9999995");
}

Test(test_format_signed_float, float_round_double_larger_whole_nb, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.99999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("9.000000");
}

Test(test_format_signed_float, float_round_double_longer_whole_nb, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 9.99999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("10.000000");
}

Test(test_format_flags_float, float_prec0, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.precision = 0;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("8");
}

Test(test_format_flags_float, float_prec0_larger_whole, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.59999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.precision = 0;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("9");
}

Test(test_format_flags_float, float_prec0_hash, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_hash;
	info.precision = 0;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("8.");
}

Test(test_format_flags_float, float_prec0_hash_negative, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = -8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_hash;
	info.precision = 0;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-8.");
}

Test(test_format_flags_float, float_width10, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.width = 10;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("  8.500000");
}

Test(test_format_flags_float, float_width10_zero, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_zero;
	info.width = 10;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("008.500000");
}

Test(test_format_flags_float, float_width10_plus, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_plus;
	info.width = 10;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" +8.500000");
}

Test(test_format_flags_float, float_width10_negative, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = -8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.width = 10;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" -8.500000");
}

Test(test_format_flags_float, float_width10_negative_zero, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = -8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_zero;
	info.width = 10;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-08.500000");
}

Test(test_format_flags_float, float_width10_prec0, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.precision = 0;
	info.width = 10;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("         8");
}

Test(test_format_flags_float, float_width10_prec0_hash, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_hash;
	info.precision = 0;
	info.width = 10;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("        8.");
}

Test(test_format_flags_float, float_width5_prec0_zer0, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_zero;
	info.precision = 0;
	info.width = 5;
	info.precfound = 1;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("00008");
}

Test(test_format_flags_float, float_plus, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_plus;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("+8.500000");
}

Test(test_format_flags_float, float_space, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = 8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_space;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str(" 8.500000");
}

Test(test_format_flags_float, float_plus_negative, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = -8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_plus;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-8.500000");
}

Test(test_format_flags_float, float_space_negative, .init = redirect_std_out)
{
	t_info info;
	double f;
	int fd;

	fd = 1;
	f = -8.49999999;
	init_struct(&info);
	init_va_list(&info, f);
	info.writer = &simplewriter;
	info.target = &fd;
	info.flags |= e_space;
	ft_format_floats(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("-8.500000");
}

Test(test_printf_float, simple_float, .init = redirect_std_out)
{
	float f;
	char *result = NULL;
	f = 3.1486949;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_double, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 42.424242;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_zero, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = -0.0L;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_zero, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 0.0L;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_nan, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = NAN * -1;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_nan, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = NAN;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_nan_plus, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = NAN;
	ft_printf("%+Lf", f);
	fflush(stdout);

	asprintf(&result, "%+Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_nan_space, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = NAN;
	ft_printf("% Lf", f);
	fflush(stdout);

	asprintf(&result, "% Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_nan_space_width, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = NAN;
	ft_printf("% 8Lf", f);
	fflush(stdout);

	asprintf(&result, "% 8Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_inf, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_inf, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY * -1;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_inf_plus, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY;
	ft_printf("%+Lf", f);
	fflush(stdout);

	asprintf(&result, "%+Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_inf_space, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY;
	ft_printf("% Lf", f);
	fflush(stdout);

	asprintf(&result, "% Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_inf_space_width, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY;
	ft_printf("% 8Lf", f);
	fflush(stdout);

	asprintf(&result, "% 8Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_inf_plus, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY * -1;
	ft_printf("%+Lf", f);
	fflush(stdout);

	asprintf(&result, "%+Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_inf_space, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY * -1;
	ft_printf("% Lf", f);
	fflush(stdout);

	asprintf(&result, "% Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_inf_zero, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY * -1;
	ft_printf("%0Lf", f);
	fflush(stdout);

	asprintf(&result, "%0Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_neg_inf_space_width, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY * -1;
	ft_printf("% 8Lf", f);
	fflush(stdout);

	asprintf(&result, "% 8Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 42.4242425999;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_weird_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 42.4242424999;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_overflow_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 42.499999999999;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_overflow_round_past_decimal_point_1, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 1.5;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, simple_overflow_round_past_decimal_point_2, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 2.5;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round_past_decimal_point_1, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 45.5;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round_past_decimal_point_2, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 49.5;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round_past_decimal_point_3, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 39.5;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round_past_decimal_point_4, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 35.5;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round_past_decimal_point_5, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 9.6;
	ft_printf("%.0f", f);
	fflush(stdout);

	asprintf(&result, "%.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_overflow_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 42.999999999999;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harderer_overflow_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 99.999999999999;
	ft_printf("%f", f);
	fflush(stdout);

	asprintf(&result, "%f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harder_double_round, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 0.87650894255;
	ft_printf("%.10f", f);
	fflush(stdout);

	asprintf(&result, "%.10f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, harderer_longdouble_round, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 3456346524.13454999L;
	ft_printf("%f", (double)f);
	fflush(stdout);

	asprintf(&result, "%f", (double)f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, unsigned_int_long_double, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 15745635345667846524.13454999L;
	ft_printf("%Lf", f);
	fflush(stdout);

	asprintf(&result, "%Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, unsigned_int_zero_width32_long_double, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 15745635345667846524.13454999L;
	ft_printf("%032Lf", f);
	fflush(stdout);

	asprintf(&result, "%032Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, unsigned_int_minus_width42_10prec_long_double, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 15745635345667846524.13454999L;
	ft_printf("%-42.10Lf", f);
	fflush(stdout);

	asprintf(&result, "%-42.10Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, float_minus_width42_long_double, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = 42.4242429L;
	ft_printf("%-42Lf", f);
	fflush(stdout);

	asprintf(&result, "%-42Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, inf_minus_width42_long_double, .init = redirect_std_out)
{
	long double f;
	char *result = NULL;
	f = INFINITY;
	ft_printf("%-42Lf", f);
	fflush(stdout);

	asprintf(&result, "%-42Lf", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, zero_width42_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 0;
	ft_printf("%42.0f", f);
	fflush(stdout);

	asprintf(&result, "%42.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, zero_hash_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 0.0;
	ft_printf("%#.0f", f);
	fflush(stdout);

	asprintf(&result, "%#.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, hash_prec_0_round_up, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 0.9;
	ft_printf("%#.0f", f);
	fflush(stdout);

	asprintf(&result, "%#.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, hash_round_past_decimal_point_1, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 9.6;
	ft_printf("%#.0f", f);
	fflush(stdout);

	asprintf(&result, "%#.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, neg_zero_hash_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = -0.0;
	ft_printf("%#.0f", f);
	fflush(stdout);

	asprintf(&result, "%#.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, zero_zero_hash_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = 0.0;
	ft_printf("%0#.0f", f);
	fflush(stdout);

	asprintf(&result, "%#.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, neg_zero_zero_hash_width_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = -0.0;
	ft_printf("%0#4.0f", f);
	fflush(stdout);

	asprintf(&result, "%0#4.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, neg_zero_plus_zero_hash_width_prec_0, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = -0.0;
	ft_printf("%+0#4.0f", f);
	fflush(stdout);

	asprintf(&result, "%+0#4.0f", f);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_float, neg_zero_plus_zero_hash_width_prec_args, .init = redirect_std_out)
{
	double f;
	char *result = NULL;
	f = -0.0;
	ft_printf("%+0#*.*f", 4, 0, f);
	fflush(stdout);

	asprintf(&result, "%+0#*.*f", 4, 0, f);
	cr_assert_stdout_eq_str(result);
}
