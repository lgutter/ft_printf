/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcharjoin_tests.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 12:24:42 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/27 12:29:48 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test (basic_strcharjoin, join_str_to_char)
{
    char *str1;
    char c;
	char *out;

    str1 = ft_strdup("Hello ");
    c = 'W';
    out = ft_strcharjoin(str1, c);
    cr_assert_str_eq(out, "Hello W");
}

Test (basic_strcharjoin, join_short_str_to_char)
{
    char *str1;
    char c;
	char *out;

    str1 = ft_strdup("H");
    c = '~';
    out = ft_strcharjoin(str1, c);
    cr_assert_str_eq(out, "H~");
}

Test (basic_strcharjoin, join_empty_str_to_char)
{
    char *str1;
    char c;
	char *out;

    str1 = ft_strdup("");
    c = '/';
    out = ft_strcharjoin(str1, c);
    cr_assert_str_eq(out, "/");
}

Test (basic_strcharjoin, join_str_to_special_char)
{
    char *str1;
    char c;
	char *out;

    str1 = ft_strdup("Hello ");
    c = '\t';
    out = ft_strcharjoin(str1, c);
    cr_assert_str_eq(out, "Hello \t");
}
