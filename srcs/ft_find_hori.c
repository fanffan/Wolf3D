/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hori.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:28:48 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 17:28:52 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double     deg_to_rad(int deg)
{
    return (M_PI * deg / 180);
}

void    ft_find_FIH(t_wolf *env)
{
    if (env->ray >= 0 && env->ray <= 180)
    {
        env->fihy = (int)(env->playery / CUBE) * CUBE - 1;
        env->ya = -CUBE;
    }
    else
    {
        env->fihy = (int)(env->playery / CUBE) * CUBE + CUBE;
        env->ya = CUBE;
    }
    env->fihx = env->playerx + (env->playery - env->fihy) / tan(deg_to_rad(env->ray));
}

void    ft_find_hori(t_wolf *env)
{
    env->ray = 60;
    env->playerx = 96;
    env->playery = 224;
    ft_find_FIH(env);
    env->xa = CUBE / tan(deg_to_rad(env->ray));
    while (env->fihx / CUBE >= 0 && env->fihy / CUBE >= 0 &&
    env->fihx / CUBE < env->mapx && env->fihy / CUBE < env->mapy)
    {
        if (env->map[env->fihy / 64][env->fihx / 64] == '1')
        {
            ft_printf("MUR EN X:%d Y:%d\n", env->fihx / CUBE, env->fihy / CUBE);
            break;
        }
        ft_printf("PAS MUR EN X:%d Y:%d\n", env->fihx / CUBE, env->fihy / CUBE);
        env->fihx = env->fihx + env->xa;
        env->fihy = env->fihy + env->ya;

    }
}
