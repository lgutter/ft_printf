/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strexpand_tests.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 17:13:20 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/14 13:48:25 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "ft_printf.h"

Test (basic_strexpand, two_strings_input)
{
    char *str1;
    char *str2;

    str1 = ft_strdup("Hello ");
    str2 = ft_strdup("World!");
    ft_strexpand(&str1, str2);
    cr_assert_str_eq(str1, "Hello World!");
}

Test (basic_strexpand, one_string_input)
{
    char *str1;
    char *str2;

    str1 = NULL;
    str2 = ft_strdup("World!");
    ft_strexpand(&str1, str2);
    cr_assert_str_eq(str1, "World!");
}
