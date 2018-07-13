/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:34:49 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 15:28:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_cross(void)
{
	exit(0);
	return (0);
}

// int			ft_keyboard(int keycode, t_env *env)
// {
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
// 	return (0);
// }

void    ft_wolf(t_wolf *env)
{
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3d");
    ft_draw(env);
    //mlx_key_hook(env->win, ft_keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), ft_cross, env);
	mlx_loop(env->mlx);
}
