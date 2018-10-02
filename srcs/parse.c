/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:10:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/02 13:52:12 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	find_player(char *line, t_map *map, t_player *player)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'x')
		{
			player->x = map->y;
			player->y = i;
		}
		i++;
	}
	player->planex = 0;
	player->planey = 0.66;
	player->dirx = -1;
	player->diry = 0;
	player->movespeed = 0.2;
	player->rotspeed = 0.2;
}

int		parse(t_wolf *env, t_map *map, t_player *player)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		map->map = ft_strtab(map->map, line);
		map->x = (int)ft_strlen(line);
		find_player(line, map, player);
		map->y++;
	}
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	if (ret == -1 || !checker(map))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	system("killall afplay 2&>/dev/null >/dev/null\n afplay \
				./sound/sound.mp3&");
	return (1);
}
