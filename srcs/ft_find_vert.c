/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:36:21 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/14 17:15:22 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    find_fiv(t_wolf *env)
{
    if (env->angle_cast > 90 && env->angle_cast <= 270)
    {
        env->ivx = (int)(env->playerx / CUBE) * CUBE + 64;
        env->xa = CUBE;
    }
    else
    {
        env->ivx = (int)(env->playerx / CUBE) * CUBE - 1;
        env->xa = -CUBE;
    }
    env->ivy = env->playery + (env->playerx - env->ivx) * tan(deg_to_rad(env->angle_cast));
    ft_printf("PREM ihx:%d ihy:%d tanangl:%f\n", env->ihx, env->ihy, tan(deg_to_rad(env->angle_cast)));
}

int    find_vert(t_wolf *env)
{

    find_fiv(env);
    env->ya = (double)CUBE * tan(deg_to_rad(env->angle_cast));
    ft_printf("YA:%d\n",env->ya);
    ft_printf("FIRST MUR HORI EN X:%d Y:%d\n", env->ivx / CUBE, env->ivy / CUBE);
    while (env->ivx / CUBE >= 0 && env->ivy / CUBE >= 0 &&
    env->ivx / CUBE < env->mapx && env->ivy / CUBE < env->mapy)
    {
        if (env->map[(int)env->ivy / 64][(int)env->ivx / 64] == '1')
        {
            ft_printf("MUR VERT EN X:%d Y:%d\n", env->ivx / CUBE, env->ivy / CUBE);
            ft_printf("LASTihx:%d ihy:%d\n", env->ivx, env->ivy);
            return (1);
        }
        ft_printf("PAS MUR VERT EN X:%d Y:%d\n", env->ivx / CUBE, env->ivy / CUBE);
        env->ivx += env->xa;
        env->ivy += env->ya;
    }
    return (0);
}
