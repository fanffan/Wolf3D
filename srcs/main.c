/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:00:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/02 13:27:24 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	t_wolf		env;
	t_map		map;
	t_player	player;

	bzero(&env, sizeof(t_wolf));
	bzero(&map, sizeof(t_map));
	bzero(&player, sizeof(t_player));
	env.map = &map;
	env.player = &player;
	env.sound = 1;
	if (ac == 2 && (env.fd = open(av[1], O_RDONLY)) > 0 &&
	parse(&env, env.map, env.player))
		wolf(&env);
	return (0);
}
