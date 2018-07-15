/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:36:21 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/14 17:15:22 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void    ft_find_FIV(t_wolf *env)
{
    if (env->ray >= 90 && env->ray <= 270)
    {
        env->ivx = (int)(env->playerx / CUBE) * CUBE + 64;
        env->xa = -CUBE;
    }
    else
    {
        env->ivx = (int)(env->playerx / CUBE) * CUBE - 1;
        env->xa = CUBE;
    }
    env->ivy = env->playery + (env->playerx - env->ivx) / tan(deg_to_rad(env->ray));
}

void    ft_find_vert(t_wolf *env)
{
    env->ray = 60;
    env->playerx = 96;
    env->playery = 224;
    ft_find_FIV(env);
    env->ya = CUBE * tan(deg_to_rad(env->ray));
    while (env->ivx / CUBE >= 0 && env->ivy / CUBE >= 0 &&
    env->ivx / CUBE < env->mapx && env->ivy / CUBE < env->mapy)
    {
        if (env->map[env->ivy / 64][env->ivx / 64] == '1')
        {
            ft_printf("MUR VERT EN X:%d Y:%d\n", env->ivx / CUBE, env->ivy / CUBE);
            break;
        }
        ft_printf("PAS MUR VERT EN X:%d Y:%d\n", env->ivx / CUBE, env->ivy / CUBE);
        env->ivx = env->ivx + env->xa;
        env->ivy = env->ivy + env->ya;
    }
}
