/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:10:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/15 12:39:32 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    find_player(char *line, t_map *map, t_player *player)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'x')
        {
            player->x = map->y;
            player->y = i;
            ft_printf ("x:%d y:%d cx:%d cy:%d\n", i, map->y, player->x, player->y);
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

int     parse(t_wolf *env, t_map *map, t_player *player)
{
    int ret;
    char *line;

    while ((ret = get_next_line(env->fd, &line)) > 0)
    {
        map->map = ft_strtab(map->map, line);
        map->x = (int)ft_strlen(line);
        find_player(line, map, player);
        map->y++;
    }
    int i;
    i = 0;
    while (map->map[i])
    {
        printf("%s\n", map->map[i]);
        i++;
    }
    if (ret == -1)
        return (0);
    return (1);
}
