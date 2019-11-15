/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_tests.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 17:00:19 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/15 16:42:29 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out_format_pointer(void)
{
	cr_redirect_stdout();
}

void init_va_list_pointer(t_info *info, ...)
{
	va_start(info->arguments, info);
}

static void simplewriter(void *target, const char *str, size_t len)
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
}

Test(test_printf_format_pointer, pointer_simple, .init = redirect_std_out_format_pointer)
{
	int a;
	int *p;

	a = 24;
	p = &a;
	char *result = NULL;
	ft_printf("%p", p);
	fflush(stdout);

	asprintf(&result, "%p", p);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_pointer, pointer_width_simple, .init = redirect_std_out_format_pointer)
{
	int a;
	int *p;

	a = 24;
	p = &a;
	char *result = NULL;
	ft_printf("%15p", p);
	fflush(stdout);

	asprintf(&result, "%15p", p);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_pointer, pointer_width_small, .init = redirect_std_out_format_pointer)
{
	int a;
	int *p;

	a = 24;
	p = &a;
	char *result = NULL;
	ft_printf("%2p", p);
	fflush(stdout);

	asprintf(&result, "%2p", p);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_pointer, pointer_width_large, .init = redirect_std_out_format_pointer)
{
	int a;
	int *p;

	a = 24;
	p = &a;
	char *result = NULL;
	ft_printf("%200p", p);
	fflush(stdout);

	asprintf(&result, "%200p", p);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_pointer, pointer_minus_width, .init = redirect_std_out_format_pointer)
{
	int a;
	int *p;

	a = 24;
	p = &a;
	char *result = NULL;
	ft_printf("%-10p", p);
	fflush(stdout);

	asprintf(&result, "%-10p", p);
	cr_assert_stdout_eq_str(result);
}

Test(test_printf_format_pointer, pointer_zero_width, .init = redirect_std_out_format_pointer)
{
	int *p;

	p = (int *)0xabfc421ffa2b3342;
	ft_printf("%010p", p);
	fflush(stdout);

	cr_assert_stdout_eq_str("0xabfc421ffa2b3342");
}

Test(test_printf_format_pointer, pointer_zero, .init = redirect_std_out_format_pointer)
{
	int *p;

	p = (int *)0xabfc421ffa2b3342;
	ft_printf("%025p", p);
	fflush(stdout);

	cr_assert_stdout_eq_str("0x0000000abfc421ffa2b3342");
}

Test(test_printf_format_pointer, pointer_zero_smaller_width, .init = redirect_std_out_format_pointer)
{
	t_info info;
	int fd;
	int *p;

	p = (int *)0xabfc421ffa2b3342;
	fd = 1;
	init_va_list_pointer(&info, p);
	info.writer = &simplewriter;
	info.flags = e_zero;
	info.width = 20;
	info.target = &fd;
	info.conv = 'p';
	ft_formatpointer(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0x00abfc421ffa2b3342");
}

Test(test_printf_format_pointer, pointer_minus_large_width, .init = redirect_std_out_format_pointer)
{
	t_info info;
	int fd;
	int *p;

	p = (int *)0xabfc421ffa2b3342;
	fd = 1;
	init_va_list_pointer(&info, p);
	info.writer = &simplewriter;
	info.flags = e_minus;
	info.width = 20;
	info.target = &fd;
	info.conv = 'p';
	ft_formatpointer(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0xabfc421ffa2b3342  ");
}
