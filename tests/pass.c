/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fail.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 18:16:11 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/11 19:56:16 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>

Test(misc, passing)
{
	cr_assert(1);
}
