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

void    draw(t_wolf *env, t_map *map, t_player *player)
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
        raydirx = player->dirx + player->planex * camerax;
        raydiry = player->diry + player->planey * camerax;
        mapx = (int)player->x;
        mapy = (int)player->y;
        deltadistx = fabs(1 / raydirx);
        deltadisty = fabs(1 / raydiry);
        if  (raydirx < 0)
        {
            stepx = -1;
            sidedistx = (player->x - mapx) * deltadistx;
            color1 = 0xFF0000;
        }
        else
        {
            stepx = 1;
            sidedistx = (mapx + 1.0 - player->x) * deltadistx;
            color1 = 0xfce25a;
        }
        if (raydiry < 0)
        {
            stepy = -1;
            sidedisty = (player->y - mapy) * deltadisty;
            color2 = 0x00FF00;
        }
        else
        {
            stepy = 1;
            sidedisty = (mapy + 1.0 - player->y) * deltadisty;
            color2 = 0x0000FF;
        }
        while(map->map[mapx][mapy] != '1')
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
            perpwalldist = (mapx - player->x + (1 - stepx) / 2) / raydirx;
        else
            perpwalldist = (mapy - player->y + (1 - stepy) / 2) / raydiry;
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
