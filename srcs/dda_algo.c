/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoismaury <francoismaury@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:43:09 by francoismau       #+#    #+#             */
/*   Updated: 2018/07/29 20:53:18 by francoismau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    initialize(int i, t_player *player, t_map *map)
{
    player->camerax = 2 * i / (double)WIDTH - 1;
    player->raydirx = player->dirx + player->planex * player->camerax;
    player->raydiry = player->diry + player->planey * player->camerax;
    map->mapx = (int)player->x;
    map->mapy = (int)player->y;
    player->deltadistx = fabs(1 / player->raydirx);
    player->deltadisty = fabs(1 / player->raydiry);
    if  (player->raydirx < 0)
    {
        player->stepx = -1;
        player->sidedistx = (player->x - map->mapx) * player->deltadistx;
        player->color1 = 0xFF0000;
    }
    else
    {
        player->stepx = 1;
        player->sidedistx = (map->mapx + 1.0 - player->x) * player->deltadistx;
        player->color1 = 0xfce25a;
    }
    if (player->raydiry < 0)
    {
        player->stepy = -1;
        player->sidedisty = (player->y - map->mapy) * player->deltadisty;
        player->color2 = 0x00FF00;
    }
    else
    {
        player->stepy = 1;
        player->sidedisty = (map->mapy + 1.0 - player->y) * player->deltadisty;
        player->color2 = 0x0000FF;
    }
}

void    ray(t_wolf *env, int drawstart, int drawend, int j, int color,int *sky)
{
    int i;

    i = 0;
    (void)sky;
    while (i < drawstart)
    {
        if (sky[i * WIDTH + j])
            env->data[i * WIDTH  + j] = sky[(40 + i) * 1920 + j];
        i++;
    }
    while (drawstart < drawend)
    {
            env->data[drawstart * WIDTH + j] = color;
        drawstart++;
    }
    i = drawend;
        while (i < HEIGHT - 1)
    {
        env->data[i * WIDTH + j] = 0xB29A9A;
        i++;
    }
}

void    dist(t_player *player, t_map *map)
{
    if (player->side == 0)
        player->perpwalldist = (map->mapx - player->x + (1 - player->stepx) / 2) / player->raydirx;
    else
        player->perpwalldist = (map->mapy - player->y + (1 - player->stepy) / 2) / player->raydiry;
}

void    find_wall(t_wolf *env, t_player *player, t_map *map)
{
    while(map->map[map->mapx][map->mapy] != '1')
    {
        if (player->sidedistx < player->sidedisty)
        {
            player->sidedistx += player->deltadistx;
            map->mapx += player->stepx;
            player->side = 0;
            env->color = player->color1;

        }
        else
        {
            player->sidedisty += player->deltadisty;
            map->mapy += player->stepy;
            player->side = 1;
            env->color = player->color2;
        }
    }
}

void wall(t_wolf *env, t_player *player)
{
    player->hwall = (int)(HEIGHT / player->perpwalldist);
    env->drawstart = -player->hwall / 2 + HEIGHT / 2;
    if (env->drawstart < 0)
        env->drawstart = 0;
    env->drawend = player->hwall / 2 + HEIGHT / 2;
    if (env->drawend >= HEIGHT)
        env->drawend = HEIGHT - 1;
}
void dda_algo(t_wolf *env, t_player *player, t_map* map)
{
    int i;
    int w;
    int h;

    i = 0;
    w = 612;
    h = 408;
    env->sky.im = mlx_xpm_file_to_image(env->mlx, "/Users/francoismaury/Projets/wolflodev/textures/sky3.xpm", &w, &h);
	env->sky.imc = (int*)mlx_get_data_addr(env->sky.im, &env->sky.bpp, &env->sky.imlen, &env->sky.endi);
        // mlx_put_image_to_window(env->mlx, env->win, env->sky.im, 0, 0);

    while (i < WIDTH)
    {
        initialize(i, player, map);
        find_wall(env, player, map);
        dist(player, map);
        wall(env, player);
        ray(env, env->drawstart, env->drawend, i, env->color, env->sky.imc);
        i++;

    }
        mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);


}