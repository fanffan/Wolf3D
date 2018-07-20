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
     (void)env;
     printf("%d\n", keycode);
     if (keycode == 124)
     {
                  fill(env);

        //mlx_clear_window(env->mlx, env->win);
         if (env->ray == 360)
            env->ray = 0;
        env->ray += 5;
        draw(env);
     }
      if (keycode == 123)
     {
         fill(env);
        // mlx_clear_window(env->mlx, env->win);
          if (env->ray == 0)
             env->ray = 360;
         env->ray -= 5;
         draw(env);
     }
     if (keycode == 125)
     {
        if (env->playerx + (int)(5 * cos(deg_to_rad(env->ray))) > 0
         && env->playery + (int)(5 * sin(deg_to_rad(env->ray))) > 0
         && (env->playerx + (int)(5 * cos(deg_to_rad(env->ray)))) / 64 >= 0
         && (env->playery + (int)(5 * sin(deg_to_rad(env->ray)))) / 64 >= 0
         && (env->playerx + (int)(5 * cos(deg_to_rad(env->ray)))) / 64 < env->mapx
         && (env->playery + (int)(5 * sin(deg_to_rad(env->ray)))) / 64 < env->mapy)
        {
            fill(env);
            env->playerx += (int)(5 * cos(deg_to_rad(env->ray)));
            env->playery += (int)(5 * sin(deg_to_rad(env->ray)));
            draw(env);
        }
     }
     if (keycode == 126)
     {
         if (env->playerx + (int)(5 * cos(deg_to_rad(env->ray))) > 0
         && env->playery + (int)(5 * sin(deg_to_rad(env->ray))) > 0
         && (env->playerx + (int)(5 * cos(deg_to_rad(env->ray)))) / 64 >= 0
         && (env->playery + (int)(5 * sin(deg_to_rad(env->ray)))) / 64 >= 0
         && (env->playerx + (int)(5 * cos(deg_to_rad(env->ray)))) / 64 < env->mapx
         && (env->playery + (int)(5 * sin(deg_to_rad(env->ray)))) / 64 < env->mapy)
        {
            fill(env);
            // mlx_clear_window(env->mlx, env->win);
            env->playerx -= (int)(5 * cos(deg_to_rad(env->ray)));
            env->playery -= (int)(5 * sin(deg_to_rad(env->ray)));
            draw(env);
        }
     }
 	if (keycode == 53)
 		cross();
//         if ((keycode >= 123 && keycode <= 126) || keycode == 15)
// 	{
// 		mlx_clear_window(env->mlx, env->win);
// 		if (keycode == 123)
// 			env->decx -= 10;
// 		if (keycode == 126)
// 			env->decy -= 10;
// 		if (keycode == 124)
// 			env->decx += 10;
// 		if (keycode == 125)
// 			env->decy += 10;
// 		if (keycode == 15)
// 			env->check = 0;
// 		draw(env);
// 	}
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
    //draw(env);
    mlx_key_hook(env->win, keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), cross, env);
	mlx_loop(env->mlx);
}
