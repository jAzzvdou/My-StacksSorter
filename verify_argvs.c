/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_argvs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:43:22 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/02 13:42:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_number(int nb)
{
        if (nb >= '0' && nb <= '9')
                return (1);
        return (0);
}

int     only_number(char *s)
{
        int     i;

        i = 0;
        if (s[i] == '-' || s[i] == '+')
                i++;
        while (s[i])
                if (!is_number(s[i++]))
                        return (0);
        return (1);
}

int     verify_argv(char **argv)
{
        int     i;

        i = -1;
        while (argv[++i])
                if (!only_number(argv[i]))
                        return (0);
        return (1);
}

int     is_int(char **argv)
{
        int     i;

        i = -1;
        while (argv[++i])
        {
                if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) > 2147483647
                        || ft_atol(argv[i]) < -2147483648)
                        return (0);
        }
        return (1);
}

int     is_duplicated(char **argv)
{
        int     i;
        int     ii;

        i = -1;
        while (argv[++i])
        {
                ii = i;
                while (argv[++ii])
                        if (ft_atoi(argv[i]) == ft_atoi(argv[ii]))
                                return (1);
        }
        return (0);
}
