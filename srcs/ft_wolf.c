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
     printf("%d\n", keycode);
     if (keycode == 124 || keycode == 2)
     {
        fill(env);
         double olddirx = env->dirx;
         env->dirx = env->dirx * cos(-env->rotspeed) - env->diry * sin(-env->rotspeed);
         env->diry = olddirx * sin(-env->rotspeed) + env->diry * cos(-env->rotspeed);
         double oldplanex = env->planex;
         env->planex = env->planex * cos(-env->rotspeed) - env->planey * sin(-env->rotspeed);
         env->planey = oldplanex * sin(-env->rotspeed) + env->planey * cos(-env->rotspeed);
        draw(env);
     }
      if (keycode == 123 || keycode == 0)
     {
          fill(env);
         double olddirx = env->dirx;
         env->dirx = env->dirx * cos(env->rotspeed) - env->diry * sin(env->rotspeed);
         env->diry = olddirx * sin(env->rotspeed) + env->diry * cos(env->rotspeed);
         double oldplanex = env->planex;
         env->planex = env->planex * cos(env->rotspeed) - env->planey * sin(env->rotspeed);
         env->planey = oldplanex * sin(env->rotspeed) + env->planey * cos(env->rotspeed);
        draw(env);
     }
     if (keycode == 126 || keycode == 13)
     {
        fill(env);
        if (env->map[(int)(env->playerx + env->dirx * env->movespeed)][(int)env->playery] == '0' &&
            env->map[(int)(env->playerx)][(int)(env->playery + env->diry * env->movespeed)] == '0')
        {
            env->playerx += env->dirx * env->movespeed;
            env->playery += env->diry * env->movespeed;
        }
        draw(env);
     }
     if (keycode == 125 || keycode == 1)
     {
        fill(env);
        printf("x:%c y:%c\n",env->map[(int)(env->playerx - env->dirx * env->movespeed)][(int)env->playery],
        env->map[(int)(env->playerx)][(int)(env->playery - env->diry * env->movespeed)]);
        if (env->map[(int)(env->playerx - env->dirx * env->movespeed)][(int)env->playery] == '0' &&
            env->map[(int)(env->playerx)][(int)(env->playery - env->diry * env->movespeed)] == '0')
        {
            printf("calc:%f x:%f\n",env->dirx * env->movespeed, env->playerx);
            env->playerx -= env->dirx * env->movespeed;
            env->playery -= env->diry * env->movespeed;
        }
        draw(env);
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
    draw(env);
    mlx_key_hook(env->win, keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), cross, env);
	mlx_loop(env->mlx);
}
