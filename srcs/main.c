/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoismaury <francoismaury@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:00:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/29 19:00:23 by francoismau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(int ac, char **av)
{
    t_wolf env;
    t_map map;
    t_player player;

    bzero(&env, sizeof(t_wolf));
    bzero(&map, sizeof(t_map));
    bzero(&player, sizeof(t_player));
    env.map = &map;
    env.player = &player;
    if (ac == 2 && (env.fd = open(av[1], O_RDONLY)) > 0 && parse(&env, env.map, env.player))
        wolf(&env);
    return (0);
}
