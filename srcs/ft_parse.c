/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:10:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 16:07:34 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    ft_find_player(char *line, t_wolf *env)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'x')
        {
            env->playerx = i * (CUBE / 2);
            env->playery = env->mapy * (CUBE / 2);
        }
        i++;
    }
}

int     ft_parse(t_wolf *env)
{
    int i;
    int ret;
    char *line;

    i = 0;
    while ((ret = get_next_line(env->fd, &line)) > 0)
    {
        env->map = ft_strtab(env->map, line);
        env->mapx = ft_strlen(line);
        ft_find_player(line, env);
        env->mapy++;
    }
    if (ret == -1)
        return (0);
    return (1);
}
