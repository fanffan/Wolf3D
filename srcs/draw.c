/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 11:10:18 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/02 11:16:14 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_wall(t_wolf *env, int j, t_world *world)
{
	int d;
	int texy;

	while (world->drawstart < world->drawend)
	{
		d = world->drawstart * 256 - HEIGHT * 128 + world->hwall * 128;
		texy = ((d * world->texheight) / world->hwall) / 256;
		if (world->texheight * texy + world->texx < world->texheight *
		world->texwidth)
			env->data[world->drawstart * WIDTH + j] =
			world->imc[world->texheight * texy + world->texx];
		world->drawstart++;
	}
}

void	draw(t_wolf *env, int j, t_world *world)
{
	int i;

	i = 0;
	while (i < world->drawstart)
	{
		if (i * env->sky.width + j < 1192 * 670)
			env->data[i * WIDTH + j] = env->sky.imc[i * env->sky.width + j];
		i++;
	}
	draw_wall(env, j, world);
	while (world->drawend < HEIGHT)
	{
		env->data[world->drawend * WIDTH + j] = 0xB29A9A;
		world->drawend++;
	}
}
