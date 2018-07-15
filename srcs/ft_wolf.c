/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:34:49 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/16 00:23:28 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_cross(void)
{
	exit(0);
	return (0);
}

void            ft_fill(t_wolf *env)
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
 int			ft_key board(int keycode, t_wolf *env)
 {
     (void)env;
     printf("%d\n", keycode);
     if (keycode == 65363)
     {
        mlx_clear_window(env->mlx, env->win);
         if (env->ray == 360)
            env->ray = 0;
        env->ray += 5; 
        ft_draw(env);
     }
      if (keycode == 65361)
     {
         ft_fill(env);
        // mlx_clear_window(env->mlx, env->win);
          if (env->ray == 0)
             env->ray = 360;
         env->ray -= 5; 
         ft_draw(env);
     }
// 	if (keycode == 53)
// 		ft_cross();
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
// 		ft_draw(env);
// 	}
 	return (0);
 }

void    ft_wolf(t_wolf *env)
{
    int size_l;
	int	bpp;
    int	endian;

    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3d");
    env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
    env->data = (int*)mlx_get_data_addr(env->img, &bpp, &size_l, &endian);
    ft_draw(env);
    mlx_key_hook(env->win, ft_keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), ft_cross, env);
	mlx_loop(env->mlx);
}
