/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcharexpand_tests.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 12:35:36 by lgutter        #+#    #+#                */
/*   Updated: 2019/10/27 12:37:58 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test (basic_strcharexpand, join_str_to_char)
{
    char *str1;
    char c;

    str1 = ft_strdup("Hello ");
    c = 'W';
    ft_strcharexpand(&str1, c);
    cr_assert_str_eq(str1, "Hello W");
}

Test (basic_strcharexpand, join_short_str_to_char)
{
    char *str1;
    char c;

    str1 = ft_strdup("H");
    c = '~';
    ft_strcharexpand(&str1, c);
    cr_assert_str_eq(str1, "H~");
}

Test (basic_strcharexpand, join_empty_str_to_char)
{
    char *str1;
    char c;

    str1 = ft_strdup("");
    c = '/';
    ft_strcharexpand(&str1, c);
    cr_assert_str_eq(str1, "/");
}

Test (basic_strcharexpand, join_str_to_special_char)
{
    char *str1;
    char c;

    str1 = ft_strdup("Hello ");
    c = '\t';
    ft_strcharexpand(&str1, c);
    cr_assert_str_eq(str1, "Hello \t");
}

Test (basic_strcharexpand, join_null_str_to_char)
{
    char *str1;
    char c;

    str1 = NULL;
    c = 'Y';
    ft_strcharexpand(&str1, c);
    cr_assert_str_eq(str1, "Y");
}
