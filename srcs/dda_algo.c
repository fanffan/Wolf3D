/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:43:09 by francoismau       #+#    #+#             */
/*   Updated: 2018/10/02 18:07:51 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	dist(t_player *player, t_world *world)
{
	if (world->side == 0)
		world->perpwalldist = (world->mapx - player->x +
		(1 - world->stepx) / 2) / world->raydirx;
	else
		world->perpwalldist = (world->mapy - player->y +
		(1 - world->stepy) / 2) / world->raydiry;
}

void	find_wall(t_map *map, t_world *world)
{
	while (map->map[world->mapx][world->mapy] != '1')
	{
		if (world->sidedistx < world->sidedisty)
		{
			world->sidedistx += world->deltadistx;
			world->mapx += world->stepx;
			world->side = 0;
			world->imc = world->imc1;
			world->texwidth = world->texwidth1;
			world->texheight = world->texheight1;
		}
		else
		{
			world->sidedisty += world->deltadisty;
			world->mapy += world->stepy;
			world->side = 1;
			world->imc = world->imc2;
			world->texwidth = world->texwidth2;
			world->texheight = world->texheight2;
		}
	}
}

void	wall(t_world *world)
{
	world->hwall = (int)(HEIGHT / world->perpwalldist);
	world->drawstart = -world->hwall / 2 + HEIGHT / 2;
	if (world->drawstart < 0)
		world->drawstart = 0;
	world->drawend = world->hwall / 2 + HEIGHT / 2;
	if (world->drawend >= HEIGHT)
		world->drawend = HEIGHT - 1;
}

void	texture(t_player *player, t_world *world)
{
	if (world->side == 0)
		world->wallx = player->y + world->perpwalldist * world->raydiry;
	else
		world->wallx = player->x + world->perpwalldist * world->raydirx;
	world->wallx -= floor(world->wallx);
	world->texx = (int)(world->wallx * (double)world->texwidth);
	if (world->side == 0 && world->raydirx > 0)
		world->texx = world->texwidth - world->texx - 1;
	if (world->side == 1 && world->raydiry < 0)
		world->texx = world->texwidth - world->texx - 1;
}

void	dda_algo(t_wolf *env, int i, int width)
{
	t_player	*player;
	t_map		*map;
	t_world		world;

	player = env->player;
	map = env->map;
	ft_bzero(&world, sizeof(t_world));
	while (i < width)
	{
		initialize(i, player, &world, env);
		find_wall(map, &world);
		dist(player, &world);
		wall(&world);
		texture(player, &world);
		draw(env, i, &world);
		i++;
	}
}
