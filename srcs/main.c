/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:00:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 13:34:14 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(int ac, char **av)
{
    t_wolf env;

    ft_bzero(&env, sizeof(t_wolf));
    if (ac == 2 && (env.fd = open(av[1], O_RDONLY)) > 0 && ft_parse(&env))
    {
        ft_wolf(&env);
    }
    return (0);
}
