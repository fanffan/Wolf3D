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

void     find_nextvi(t_wolf *env)
{
    double tmp;

    tmp = env->ivx;
    if (env->angle_cast > 90 && env->angle_cast <= 270)
        env->ivx = (int)(env->ivx / CUBE) * CUBE + 64;
    else
        env->ivx = (int)(env->ivx / CUBE) * CUBE - 1;
    env->ivy = env->ivy - (int)((tmp - env->ivx) * tan(deg_to_rad(env->angle_cast)));
}

void    find_fiv(t_wolf *env)
{
    if (env->angle_cast > 90 && env->angle_cast <= 270)
        env->ivx = (int)(env->playerx / CUBE) * CUBE + 64;
    else
        env->ivx = (int)(env->playerx / CUBE) * CUBE - 1;
    env->ivy = env->playery - (int)((env->playerx - env->ivx) * tan(deg_to_rad(env->angle_cast)));
}

int    find_vert(t_wolf *env)
{

    find_fiv(env);
    while (env->ivx / CUBE >= 0 && env->ivy / CUBE >= 0 &&
    env->ivx / CUBE < env->mapx && env->ivy / CUBE < env->mapy)
    {
        if (env->map[(int)(env->ivy / 64)][(int)(env->ivx / 64)] == '1')
        {
            printf("LASTivx:%f ivy:%f\n", env->ivx, env->ivy);
            return (1);
        }
        find_nextvi(env);
    }
    return (0);
}
