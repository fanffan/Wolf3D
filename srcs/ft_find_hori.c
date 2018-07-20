/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hori.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:28:48 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/19 13:24:13 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    nexth(t_wolf *env)
{
    double tmp;

    tmp = env->ihy;
    if (env->angle_cast > 0 && env->angle_cast < 180)
    {
        env->ihy = (int)(env->ihy / CUBE) * CUBE - 1;
        env->ya = -CUBE;
    }
    else
    {
        env->ihy = (int)(env->ihy / CUBE) * CUBE + CUBE;
        env->ya = CUBE;
    }
    env->ihx = env->ihx - (tmp - env->ihy) / tan(deg_to_rad(env->angle_cast));
    printf("PREM ihx:%f ihy:%f tanangl:%f\n", env->ihx, env->ihy, tan(deg_to_rad(env->angle_cast)));
}

void    find_fih(t_wolf *env)
{
    if (env->angle_cast > 0 && env->angle_cast < 180)
    {
        env->ihy = (int)(env->playery / CUBE) * CUBE - 1;
        env->ya = -CUBE;
    }
    else
    {
        env->ihy = (int)(env->playery / CUBE) * CUBE + CUBE;
        env->ya = CUBE;
    }
    env->ihx = env->playerx - (env->playery - env->ihy) / tan(deg_to_rad(env->angle_cast));
    printf("PREM ihx:%f ihy:%f tanangl:%f\n", env->ihx, env->ihy, tan(deg_to_rad(env->angle_cast)));
}

int    find_hori(t_wolf *env)
{

    find_fih(env);
    env->xa = CUBE / tan(deg_to_rad(env->angle_cast));
    printf("XA:%f\n",env->xa);
    printf("FIRST MUR HORI EN X:%f Y:%f\n", env->ihx / CUBE, env->ihy / CUBE);
    while ((int)env->ihx / CUBE >= 0 && (int)env->ihy / CUBE >= 0 &&
    (int)env->ihx / CUBE < env->mapx && env->ihy / CUBE < env->mapy)
    {
        if (env->map[(int)(env->ihy / CUBE)][(int)(env->ihx / CUBE)] == '1')
        {
            printf("MUR HORI EN X:%d Y:%d\n", (int)(env->ihx / CUBE), (int)(env->ihy / CUBE));
            printf("LASTihx:%f ihy:%f\n", env->ihx, env->ihy);
            return (1);
        }
       printf("PAS MUR HORI EN X:%f Y:%f\n", env->ihx, env->ihy);
        //env->ihx = env->ihx + env->xa;
        //env->ihy = env->ihy + env->ya;
        nexth(env);
    }
    return (0);
}
