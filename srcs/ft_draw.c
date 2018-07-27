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

void    ray(t_wolf *env, int drawstart, int drawend, int j, int color)
{
    int i;

    i = 0;
    env->data[drawstart * WIDTH  + j] = color;
    env->data[drawend * WIDTH  + j] = color;
    while (drawstart < drawend)
    {
            env->data[drawstart * WIDTH + j] = color;
        drawstart++;
    }
}

// void    wall(t_wolf *env, double dist, int i, int color)
// {
//     int hwall;

//     hwall = (int)(CUBE * DISTPLAY / (dist * cos((double)(deg_to_rad(i * -0.1 + 30)))));
//     ft_printf("wall: %d dist:%d\n", hwall, dist);
//     ray(env, hwall, i, color);

// }

void    draw(t_wolf *env)
{
    double camerax;
    double raydirx;
    double raydiry;
    int i;
    int mapx;
    int mapy;
    double sidedistx;
    double sidedisty;
    double deltadistx;
    double deltadisty;
    double perpwalldist;
    int hwall;
    int stepx;
    int stepy;
    int side;
    int color1;
    int color2;

    i = 0;


    while (i < WIDTH)
    {
        camerax = 2 * i / (double)WIDTH - 1;
        raydirx = env->dirx + env->planex * camerax;
        raydiry = env->diry + env->planey * camerax;
        mapx = (int)env->playerx;
        mapy = (int)env->playery;
        deltadistx = fabs(1 / raydirx);
        deltadisty = fabs(1 / raydiry);
        if  (raydirx < 0)
        {
            stepx = -1;
            sidedistx = (env->playerx - mapx) * deltadistx;
            color1 = 0xFF0000;
        }
        else
        {
            stepx = 1;
            sidedistx = (mapx + 1.0 - env->playerx) * deltadistx;
            color1 = 0x935347;
        }
        if (raydiry < 0)
        {
            stepy = -1;
            sidedisty = (env->playery - mapy) * deltadisty;
            color2 = 0x00FF00;
        }
        else
        {
            stepy = 1;
            sidedisty = (mapy + 1.0 - env->playery) * deltadisty;
            color2 = 0x0000FF;
        }
        while(env->map[mapx][mapy] != '1')
        {
            if (sidedistx < sidedisty)
            {
                sidedistx += deltadistx;
                mapx += stepx;
                side = 0;
                env->color = color1;

            }
            else
            {
                sidedisty += deltadisty;
                mapy += stepy;
                side = 1;
                env->color = color2;

            }
        //printf("wall x:%d y:%d\n", mapx, mapy);
        }

        if (side == 0)
            perpwalldist = (mapx - env->playerx + (1 - stepx) / 2) / raydirx;
        else
            perpwalldist = (mapy - env->playery + (1 - stepy) / 2) / raydiry;
        hwall = (int)(HEIGHT / perpwalldist);
        int drawstart = -hwall / 2 + HEIGHT / 2;
        if (drawstart < 0)
            drawstart = 0;
            int drawend = hwall / 2 + HEIGHT / 2;
            if (drawend >= HEIGHT)
                drawend = HEIGHT - 1;
        //printf("hwall:%d\n", hwall);
        ray(env, drawstart, drawend, i, env->color);
        //ft_printf("################################################################\n");

        i++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
