/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 14:40:03 by lgutter        #+#    #+#                */
/*   Updated: 2019/09/11 14:47:01 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(char *str);

int main (int argc, char **argv)
{
    if (argc != 2)
        return (0);
    ft_printf(argv[1]);
    return (0);
}