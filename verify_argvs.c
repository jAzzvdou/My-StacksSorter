/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_argvs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:43:22 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/01 17:55:56 by jazevedo         ###   ########.fr       */
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

int     verify_argv(int argc, char **argv)
{
        int     i;

        i = 0;
        if (argc == 2)
                i = -1;
        while (argv[++i] != NULL)
                if (!only_number(argv[i]))
                        return (0);
        return (1);
}

int     is_int(int argc, char **argv)
{
        int     i;

        i = 0;
        if (argc == 2)
                i = -1;
        while (argv[++i] != NULL)
        {
                if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) > 2147483647
                        || ft_atol(argv[i]) < -2147483648)
                        return (0);
        }
        return (1);
}

int     is_duplicated(int argc, char **argv)
{
        int     i;
        int     ii;

        i = 0;
        if (argc == 2)
                i = -1;
        while (argv[++i] != NULL)
        {
                ii = i;
                while (argv[++ii] != NULL)
                        if (ft_atoi(argv[i]) == ft_atoi(argv[ii]))
                                return (1);
        }
        return (0);
}
