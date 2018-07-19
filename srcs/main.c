/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:00:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/19 13:54:08 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(int ac, char **av)
{
    t_wolf env;

    bzero(&env, sizeof(t_wolf));
    if (ac == 2 && (env.fd = open(av[1], O_RDONLY)) > 0 && parse(&env))
    {
        wolf(&env);
    }
    return (0);
}
