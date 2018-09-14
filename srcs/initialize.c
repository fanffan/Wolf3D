/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:19:06 by fmaury            #+#    #+#             */
/*   Updated: 2018/09/14 16:26:45 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_x(t_world *world, t_wolf *env, t_player *player)
{
	if (world->raydirx < 0)
	{
		world->stepx = -1;
		world->sidedistx = (player->x - world->mapx) * world->deltadistx;
		player->color1 = 0xFF0000;
		world->imc1 = env->wall1.imc;
		world->texwidth1 = env->wall1.width;
		world->texheight1 = env->wall1.height;
	}
	else
	{
		world->stepx = 1;
		world->sidedistx = (world->mapx + 1.0 - player->x) * world->deltadistx;
		player->color1 = 0xfce25a;
		world->imc1 = env->wall3.imc;
		world->texwidth1 = env->wall3.width;
		world->texheight1 = env->wall3.height;
	}
}

void	set_y(t_world *world, t_wolf *env, t_player *player)
{
	if (world->raydiry < 0)
	{
		world->stepy = -1;
		world->sidedisty = (player->y - world->mapy) * world->deltadisty;
		player->color2 = 0x00FF00;
		world->imc2 = env->wall4.imc;
		world->texwidth2 = env->wall4.width;
		world->texheight2 = env->wall4.height;
	}
	else
	{
		world->stepy = 1;
		world->sidedisty = (world->mapy + 1.0 - player->y) * world->deltadisty;
		player->color2 = 0x0000FF;
		world->imc2 = env->wall2.imc;
		world->texwidth2 = env->wall2.width;
		world->texheight2 = env->wall2.height;
	}
}

void	initialize(int i, t_player *player, t_world *world, t_wolf *env)
{
	double camerax;

	camerax = 2 * i / (double)WIDTH - 1;
	world->raydirx = player->dirx + player->planex * camerax;
	world->raydiry = player->diry + player->planey * camerax;
	world->mapx = (int)player->x;
	world->mapy = (int)player->y;
	world->deltadistx = fabs(1 / world->raydirx);
	world->deltadisty = fabs(1 / world->raydiry);
	set_x(world, env, player);
	set_y(world, env, player);
}
