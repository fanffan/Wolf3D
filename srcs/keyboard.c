/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:12:51 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/02 18:42:55 by fmaury           ###   ########.fr       */
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

void	left(int keycode, t_wolf *env)
{
	t_player	*player;
	double		olddirx;
	double		oldplanex;

	player = env->player;
	olddirx = player->dirx;
	oldplanex = player->planex;
	if (keycode == 123 || keycode == 0)
	{
		fill(env);
		player->dirx = player->dirx * cos(player->rotspeed) - player->diry
		* sin(player->rotspeed);
		player->diry = olddirx * sin(player->rotspeed) + player->diry
		* cos(player->rotspeed);
		player->planex = player->planex * cos(player->rotspeed) - player->planey
		* sin(player->rotspeed);
		player->planey = oldplanex * sin(player->rotspeed) + player->planey
		* cos(player->rotspeed);
		multi_thread(env);
	}
}

void	right(int keycode, t_wolf *env)
{
	t_player	*player;
	double		olddirx;
	double		oldplanex;

	player = env->player;
	olddirx = player->dirx;
	oldplanex = player->planex;
	if (keycode == 124 || keycode == 2)
	{
		fill(env);
		player->dirx = player->dirx * cos(-player->rotspeed) - player->diry
		* sin(-player->rotspeed);
		player->diry = olddirx * sin(-player->rotspeed) + player->diry
		* cos(-player->rotspeed);
		player->planex = player->planex * cos(-player->rotspeed) -
		player->planey * sin(-player->rotspeed);
		player->planey = oldplanex * sin(-player->rotspeed) + player->planey
		* cos(-player->rotspeed);
		multi_thread(env);
	}
}

void	up_down(int keycode, t_wolf *env)
{
	t_player	*player;

	player = env->player;
	if (keycode == 126 || keycode == 13)
	{
		if ((env->map->map[(int)((player->x + player->dirx * player->movespeed))]\
			[(int)((player->y + player->diry * player->movespeed))] != '1') && \
			(env->map->map[(int)((player->x + player->dirx * player->movespeed) + player->dirx * \
			player->movespeed)][(int)((player->y + player->diry * player->movespeed) + player->diry * player->movespeed)] != '1') &&\
			(env->map->map[(int)(((player->x + player->dirx * player->movespeed) + player->dirx * \
			player->movespeed) + player->dirx * player->movespeed)][(int)(((player->y + player->diry * player->movespeed) +\
			player->diry * player->movespeed) + player->diry * player->movespeed)] != '1'))
		{
			fill(env);
			player->x += player->dirx * player->movespeed;
			player->y += player->diry * player->movespeed;
			multi_thread(env);
		}
	}
	if (keycode == 125 || keycode == 1)
	{
		if ((env->map->map[(int)((player->x - player->dirx * player->movespeed))]\
		[(int)((player->y - player->diry * player->movespeed))] != '1') &&\
		(env->map->map[(int)((player->x - player->dirx * player->movespeed) - player->dirx * player->movespeed)]\
		[(int)((player->y - player->diry * player->movespeed) - player->diry * player->movespeed)] != '1') &&\
		(env->map->map[(int)(((player->x - player->dirx * player->movespeed) - player->dirx * player->movespeed) - player->dirx * player->movespeed)]\
		[(int)(((player->y - player->diry * player->movespeed) - player->diry * player->movespeed) - player->diry * player->movespeed)] != '1'))
		{
			fill(env);
			player->x -= player->dirx * player->movespeed;
			player->y -= player->diry * player->movespeed;
			multi_thread(env);
		}
	}
}

int		keyboard(int keycode, t_wolf *env)
{
	printf("%d\n", keycode);
	left(keycode, env);
	right(keycode, env);
	up_down(keycode, env);
	if (keycode == 46)
	{
		if (env->sound)
		{
			system("pkill afplay");
			env->sound = 0;
		}
		else
		{
			system("killall afplay 2&>/dev/null >/dev/null\n afplay \
				./sound/sound.mp3&");
			env->sound = 1;
		}
	}
	if (keycode == 53)
	{
		system("pkill afplay");
		exit(0);
	}
	return (0);
}
