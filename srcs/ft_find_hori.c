/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_hori.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:28:48 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/15 12:40:13 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    ft_find_FIH(t_wolf *env)
{
    if (env->ray >= 0 && env->ray <= 180)
    {
        env->ihy = (int)(env->playery / CUBE) * CUBE - 1;
        env->ya = -CUBE;
    }
    else
    {
        env->ihy = (int)(env->playery / CUBE) * CUBE + CUBE;
        env->ya = CUBE;
    }
    env->ihx = env->playerx + (env->playery - env->ihy) / tan(deg_to_rad(env->angle_cast));
    printf("PREM ihx:%d ihy:%d tanangl:%f\n", env->ihx, env->ihy, tan(deg_to_rad(env->angle_cast)));
}

int    ft_find_hori(t_wolf *env)
{

    ft_find_FIH(env);
    env->xa = CUBE / tan(deg_to_rad(env->angle_cast));
    printf("XA:%d\n",env->xa);
    while (env->ihx / CUBE >= 0 && env->ihy / CUBE >= 0 &&
    env->ihx / CUBE < env->mapx && env->ihy / CUBE < env->mapy)
    {
        if (env->map[env->ihy / 64][env->ihx / 64] == '1')
        {
            ft_printf("MUR HORI EN X:%d Y:%d\n", env->ihx / CUBE, env->ihy / CUBE);
            printf("LASTihx:%d ihy:%d\n", env->ihx, env->ihy);
            return (1);
        }
        ft_printf("PAS MUR HORI EN X:%d Y:%d\n", env->ihx / CUBE, env->ihy / CUBE);
        env->ihx = env->ihx + env->xa;
        env->ihy = env->ihy + env->ya;
    }
    return (0);
}
