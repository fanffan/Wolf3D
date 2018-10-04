/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:34:49 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/04 10:34:14 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill(t_wolf *env)
{
	int i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		env->data[i] = 0;
		i++;
	}
}

void	free_struct(t_wolf *env)
{
	int i;

	i = 0;
	if (env->map->map)
	{
		while (env->map->map[i])
		{
			free(env->map->map[i]);
			i++;
		}
		free(env->map->map);
	}
}

int		cross(t_wolf *env)
{
	system("pkill afplay");
	free_struct(env);
	exit(0);
}

void	wolf(t_wolf *env)
{
	int size_l;
	int	bpp;
	int	endian;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3d");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = (int*)mlx_get_data_addr(env->img, &bpp, &size_l, &endian);
	multi_thread(env);
	mlx_hook(env->win, 2, (1L << 0), keyboard, env);
	mlx_hook(env->win, 17, (1L << 17), cross, env);
	mlx_loop(env->mlx);
}
