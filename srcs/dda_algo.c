/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:43:09 by francoismau       #+#    #+#             */
/*   Updated: 2018/09/14 17:53:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray(t_wolf *env, int drawstart, int drawend, int j, t_world *world)
{
	int i;
	int d;
	int texy;

	i = 0;
	while (i < drawstart)
	{
		if (env->sky.imc[i * WIDTH + j])
			env->data[i * WIDTH + j] = env->sky.imc[(40 + i) * 1920 + j];
		i++;
	}
	while (drawstart < drawend)
	{
		d = drawstart * 256 - HEIGHT * 128 + world->hwall * 128;
		texy = ((d * world->texheight) / world->hwall) / 256;
		if (world->texheight * texy + world->texx < world->texheight * world->texwidth)
			env->data[drawstart * WIDTH + j] = world->imc[world->texheight * texy + world->texx];
		drawstart++;
	}
	i = drawend;
	while (i < HEIGHT)
	{
		d = i * 256 - HEIGHT * 128 + (HEIGHT - drawend) * 128;
		texy = ((d * env->floor.height) / (HEIGHT - drawend)) / 256;
		env->data[i * WIDTH + j] = 0xB29A9A;
		// if (env->floor.height * texy + world->texx < env->floor.height * env->floor.width)
		// env->data[i * WIDTH + j] = env->floor.imc[env->floor.height * texy + world->texx];
		i++;
	}
}

void	dist(t_player *player, t_world *world)
{
	if (world->side == 0)
		world->perpwalldist = (world->mapx - player->x + (1 - world->stepx) / 2) / world->raydirx;
	else
		world->perpwalldist = (world->mapy - player->y + (1 - world->stepy) / 2) / world->raydiry;
}

void	find_wall(t_player *player, t_map *map, t_world *world)
{
	while (map->map[world->mapx][world->mapy] != '1')
	{
		if (world->sidedistx < world->sidedisty)
		{
			world->sidedistx += world->deltadistx;
			world->mapx += world->stepx;
			world->side = 0;
			world->color = player->color1;
			world->imc = world->imc1;
			world->texwidth = world->texwidth1;
			world->texheight = world->texheight1;
		}
		else
		{
			world->sidedisty += world->deltadisty;
			world->mapy += world->stepy;
			world->side = 1;
			world->color = player->color2;
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
		find_wall(player, map, &world);
		dist(player, &world);
		wall(&world);
		texture(player, &world);
		ray(env, world.drawstart, world.drawend, i, &world);
		i++;
	}
}
