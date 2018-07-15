/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:10:28 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/15 12:39:32 by fanf             ###   ########.fr       */
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
            env->playerx = ((i - 1) * CUBE) + (CUBE / 2);
            env->playery = ((env->mapy - 1) * CUBE) + (CUBE / 2);
            printf ("x:%d y:%d cx:%d cy:%d\n", i, env->mapy, env->playerx, env->playery);
        }
        i++;
    }
}

int     ft_parse(t_wolf *env)
{
    int ret;
    char *line;

    while ((ret = get_next_line(env->fd, &line)) > 0)
    {
        env->map = ft_strtab(env->map, line);
        env->mapx = ft_strlen(line);
        ft_find_player(line, env);
        env->mapy++;
    }
    env->ray = 60;
    if (ret == -1)
        return (0);
    return (1);
}
