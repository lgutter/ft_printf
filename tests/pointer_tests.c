/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_tests.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 17:00:19 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/11/15 10:31:08 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

void redirect_std_out_format_pointer(void)
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

void init_va_list_pointer(t_info *info, ...)
{
	va_start(info->arguments, info);
}

Test(test_format_pointer, pointer_simple, .init = redirect_std_out_format_pointer)
{
	t_info info;
	int *p;
	int a;
	int fd;

	fd = 1;
	a = 24;
	p = &a;
	init_va_list_pointer(&info, p);
	info.writer = &simplewriter;
	info.flags = 0;
	info.width = 0;
	info.target = &fd;
	info.conv = 'p';
	ft_formatint(&info);
	fflush(stdout);

	cr_assert_stdout_eq_str("0x7ffeea58f9b8");
}
