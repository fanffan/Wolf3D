/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:10:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/04 09:39:15 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		find_player(char *line, t_map *map, t_player *player)
{
	int	i;
	int plyr;

	i = 0;
	plyr = 0;
	while (line[i])
	{
		if (line[i] == 'x')
		{
			plyr = 1;
			player->x = map->y;
			player->y = i;
		}
		i++;
	}
	player->planex = 0;
	player->planey = 0.66;
	player->dirx = -1;
	player->diry = 0;
	player->movespeed = 0.1;
	player->rotspeed = 0.2;
	if (plyr == 0)
		return (0);
	return (1);
}

int		fill_map(t_wolf *env, t_map *map, t_player *player)
{
	int		ret;
	char	*line;
	int		i;
	int		plyr;

	i = 0;
	plyr = 0;
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		map->map = ft_strtab(map->map, line);
		map->x = (int)ft_strlen(line);
		if (find_player(line, map, player))
			plyr = 1;
		map->y++;
		free(line);
	}
	if (line)
		free(line);
	if (!plyr || ret == -1)
		return (0);
	return (1);
}

int		parse(t_wolf *env, t_map *map, t_player *player)
{
	if (!fill_map(env, map, player) || !checker(map))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	player->x += 0.5;
	player->y += 0.5;
	system("killall afplay 2&>/dev/null >/dev/null\n afplay \
				./sound/sound.mp3&");
	return (1);
}
