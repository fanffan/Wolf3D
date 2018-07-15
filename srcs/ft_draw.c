/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:29:17 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/15 12:06:12 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    ray(t_wolf *env, int hwall, int j)
{
    int i;

    i = 0;
    while (i >= 0 && i <= HEIGHT * WIDTH && i < hwall / 2)
    {
        if ((HEIGHT / 2) * WIDTH + (i * WIDTH) + j <= WIDTH * HEIGHT)
        {
            env->data[(HEIGHT / 2) * WIDTH + (i * WIDTH) + j] = 0xFFFFFF;
            env->data[(HEIGHT / 2) * WIDTH - (i * WIDTH) + j] = 0xFFFFFF;
        }
        i++;
    }
}

void    wall(t_wolf *env, int dist, int i)
{
    int hwall;

    hwall = CUBE * DISTPLAY / dist;
    ft_printf("wall: %d dist:%d\n", hwall, dist);
    ray(env, hwall, i);
    
}

void    ft_draw(t_wolf *env)
{
    int disth;
    //int distv;
    double angle_pad;
    int i;

    i = 0;
    angle_pad = (double)FOV / (double)WIDTH; 
    env->angle_cast = env->ray - (FOV / 2);
    printf("pad:%f ray:%f cast:%f\n", angle_pad, env->ray, env->angle_cast);
    while (i < WIDTH)
    {
        if (!ft_find_hori(env))
            break;
        disth = ft_dist(env, env->ihx, env->ihy);
        //ft_find_vert(env);
        //distv = ft_dist(env, env->ivx, env->ivy);
        //ft_printf("h:%d v:%d\n", disth, distv);
        wall(env, disth, i);
        printf("ANGLE_CAST:%f I:%d\n", env->angle_cast, i);

        env->angle_cast += angle_pad;
        i++;
                        printf("UUIUIUIUIUIU\n");

    }
    printf("################################################################\n");
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
