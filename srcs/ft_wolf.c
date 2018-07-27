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
     double newposx;
     double newposy;
     printf("%d\n", keycode);
     if (keycode == 124)
     {
        fill(env);
        double rotspeed = 3;
         double olddirx = env->dirx;
         env->dirx = env->dirx * cos(-rotspeed) - env->diry * sin(-rotspeed);
         env->diry = olddirx * sin(-rotspeed) + env->diry * sin(-rotspeed);
         double oldplanex = env->planex;
         env->planex = env->planex * cos(-rotspeed) - env->planey * sin(-rotspeed);
         env->planey = oldplanex * sin(-rotspeed) + env->planey * cos(-rotspeed);
        draw(env);
     }
      if (keycode == 123)
     {
         fill(env);
          if (env->ray == 0)
             env->ray = 360;
         env->ray -= 5;
         draw(env);
     }
     if (keycode == 125)
     {
        fill(env);
        if (!env->map[(int)(env->playerx + env->dirx * env->movespeed)][(int)env->playery])
            env->playerx += env->dirx * env->movespeed;
        if (!env->map[(int)(env->playerx)][(int)(env->playery + env->diry * env->movespeed)])
            env->playery += env->diry * env->movespeed;
        draw(env);
     }
     if (keycode == 126)
     {
        newposx = env->playerx - (int)(10 * cos(deg_to_rad(env->ray)));
         newposy = env->playery - (int)(10 * sin(deg_to_rad(env->ray)));
        if ( newposx > 0 && newposy > 0
         && newposx / 64 >= 0
         && newposy / 64 >= 0
         && newposx / 64 < env->mapx
         && newposy / 64 < env->mapy)
        {
            fill(env);
            env->playerx = (int)newposx;
            env->playery = (int)newposy;
            draw(env);
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
    env->movespeed = 5;
    draw(env);
    mlx_key_hook(env->win, keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), cross, env);
	mlx_loop(env->mlx);
}
