/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:34:49 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/19 13:09:35 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			cross(void)
{
	exit(0);
	return (0);
}

void            fill(t_wolf *env)
{
    int i;

    i = 0;
    while (i < WIDTH * HEIGHT)
    {
        env->data[i] = 0;
        i++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
 int			keyboard(int keycode, t_wolf *env)
 {
     t_player *player;

     player = env->player;
     printf("%d\n", keycode);
     if (keycode == 124 || keycode == 2)
     {
        fill(env);
         double olddirx = player->dirx;
         player->dirx = player->dirx * cos(-player->rotspeed) - player->diry * sin(-player->rotspeed);
         player->diry = olddirx * sin(-player->rotspeed) + player->diry * cos(-player->rotspeed);
         double oldplanex = player->planex;
         player->planex = player->planex * cos(-player->rotspeed) - player->planey * sin(-player->rotspeed);
         player->planey = oldplanex * sin(-player->rotspeed) + player->planey * cos(-player->rotspeed);
    draw(env, env->map, player);
     }
      if (keycode == 123 || keycode == 0)
     {
          fill(env);
         double olddirx = player->dirx;
         player->dirx = player->dirx * cos(player->rotspeed) - player->diry * sin(player->rotspeed);
         player->diry = olddirx * sin(player->rotspeed) + player->diry * cos(player->rotspeed);
         double oldplanex = player->planex;
         player->planex = player->planex * cos(player->rotspeed) - player->planey * sin(player->rotspeed);
         player->planey = oldplanex * sin(player->rotspeed) + player->planey * cos(player->rotspeed);
    draw(env, env->map, player);
     }
     if (keycode == 126 || keycode == 13)
     {
        if (env->map->map[(int)(player->x + player->dirx * player->movespeed)][(int)player->y] != '1' &&
            env->map->map[(int)(player->x)][(int)(player->y + player->diry * player->movespeed)] != '1')
        {
            fill(env);
            player->x += player->dirx * player->movespeed;
            player->y += player->diry * player->movespeed;
    draw(env, env->map, player);
        }
     }
     if (keycode == 125 || keycode == 1)
     {
        if (env->map->map[(int)(player->x - player->dirx * player->movespeed)][(int)player->y] != '1' &&
            env->map->map[(int)(player->x)][(int)(player->y - player->diry * player->movespeed)] != '1')
        {
            fill(env);
            player->x -= player->dirx * player->movespeed;
            player->y -= player->diry * player->movespeed;
    draw(env, env->map, player);

        }
     }
 	if (keycode == 53)
 		cross();

 	return (0);
 }

void    wolf(t_wolf *env)
{
    int size_l;
	int	bpp;
    int	endian;

    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3d");
    env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
    env->data = (int*)mlx_get_data_addr(env->img, &bpp, &size_l, &endian);
    draw(env, env->map, env->player);
    //mlx_key_hook(env->win, keyboard, env);
    mlx_hook(env->win, 2, (1L << 0), keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), cross, env);
	mlx_loop(env->mlx);
}
