/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:36:21 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 17:55:37 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double     deg_to_rad(int deg)
{
    return (M_PI * deg / 180);
}

static void    ft_find_FIV(t_wolf *env)
{
    if (env->ray >= 90 && env->ray <= 270)
    {
        env->fihx = (int)(env->playerx / CUBE) * CUBE + 64;
        env->xa = -CUBE;
    }
    else
    {
        env->fihx = (int)(env->playerx / CUBE) * CUBE - 1;
        env->xa = CUBE;
    }
    env->fihy = env->playery + (env->playerx - env->fihx) / tan(deg_to_rad(env->ray));
}

void    ft_find_vert(t_wolf *env)
{
    env->ray = 60;
    env->playerx = 96;
    env->playery = 224;
    ft_find_FIV(env);
    env->ya = CUBE * tan(deg_to_rad(env->ray));
    while (env->fivx / CUBE >= 0 && env->fivy / CUBE >= 0 &&
    env->fivx / CUBE < env->mapx && env->fivy / CUBE < env->mapy)
    {
        if (env->map[env->fivy / 64][env->fivx / 64] == '1')
        {
            ft_printf("MUR EN X:%d Y:%d\n", env->fivx / CUBE, env->fivy / CUBE);
            break;
        }
        ft_printf("PAS MUR EN X:%d Y:%d\n", env->fivx / CUBE, env->fivy / CUBE);
        env->fivx = env->fivx + env->xa;
        env->fivy = env->fivy + env->ya;
    }
}
