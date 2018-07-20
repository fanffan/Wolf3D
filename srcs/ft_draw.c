/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:29:17 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/19 13:30:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    ray(t_wolf *env, int hwall, int j, int color)
{
    int i;

    i = 0;
    while (i >= 0 && i < HEIGHT * WIDTH && i < hwall / 2)
    {
        if ((HEIGHT / 2) * WIDTH + (i * WIDTH) + j <= WIDTH * HEIGHT)
        {
            env->data[(HEIGHT / 2) * WIDTH + (i * WIDTH) + j] = color;
            env->data[(HEIGHT / 2) * WIDTH - (i * WIDTH) + j] = color;
        }
        i++;
    }
}

void    wall(t_wolf *env, double dist, int i, int color)
{
    int hwall;

    hwall = (int)(CUBE * DISTPLAY / (dist * cos((double)(deg_to_rad(i * -0.1 + 30)))));
    ft_printf("wall: %d dist:%d\n", hwall, dist);
    ray(env, hwall, i, color);

}

void    draw(t_wolf *env)
{
    double disth;
    double distv;
    double angle_pad;
    int i;

    i = 0;
    angle_pad = (double)FOV / (double)WIDTH;
    env->angle_cast = env->ray - (FOV / 2);
    ft_printf("pad:%f ray:%f cast:%f\n", angle_pad, env->ray, env->angle_cast);
    while (i < WIDTH)
    {
        disth = 1000000000000000;
        distv = 1000000000000000;
        if (find_hori(env))
            disth = dist(env, env->ihx, env->ihy);
        if (find_vert(env))
            distv = dist(env, env->ivx, env->ivy);
        printf("disth:%f distv:%f\n", disth, distv);
        if (disth < distv)
            wall(env, disth, i, 0xFF0000);
        else
            wall(env, distv, i, 0x00FF00);
        printf("ANGLE_CAST:%f I:%d\n", env->angle_cast, i);

        env->angle_cast = fmod(env->angle_cast + angle_pad, 360.0);
        i++;
    }
    ft_printf("################################################################\n");
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
