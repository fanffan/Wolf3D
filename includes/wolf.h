/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:55:22 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/27 17:32:22 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#define WIDTH 900
#define HEIGHT 700
#define CUBE 64
#define FOV 60
#define DISTPLAY 277

#include "../libft/srclib/libft.h"
#include <fcntl.h>
# include "../minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
/*
** Mlx.h pour linux
** # include "../minilibx_linux/mlx.h"
*/

typedef struct      s_map
{
    char            **map;
    int             x;
    int             y;
}                   t_map;

typedef struct      s_player
{
    double          x;
    double          y;
    double          planex;
    double          planey;
    double          dirx;
    double          diry;
    double          movespeed;
    double          rotspeed;
}                   t_player;

typedef struct      s_wolf
{
    void            *mlx;
    void            *win;
    void			*img;
    int	            *data;
    int             fd;
    t_map           *map;
    t_player        *player;
    int             color;
}                   t_wolf;

int     parse(t_wolf *env, t_map * map, t_player *player);
void        wolf(t_wolf *env);
void        draw(t_wolf *env, t_map * map, t_player *player);
double     deg_to_rad(double deg);
double     rad_to_deg(double rad);

#endif
