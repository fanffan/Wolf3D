/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoismaury <francoismaury@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:55:22 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/29 20:19:48 by francoismau      ###   ########.fr       */
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
    int             mapx;
    int             mapy;
}                   t_map;

typedef struct		s_img
{
	void			*im;
	int			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_img;

typedef struct      s_player
{
    double          x;
    double          y;
    double          camerax;
    double          raydirx;
    double          raydiry;
    double          planex;
    double          planey;
    double          dirx;
    double          diry;
    double          sidedistx;
    double          sidedisty;
    double          deltadistx;
    double          deltadisty;
    double          perpwalldist;
    int             hwall;
    int             stepx;
    int             stepy;
    int             side;
    int             color1;
    int             color2;
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
    int drawstart;
        int drawend;
        void        *t_wl;
        t_img       sky;

}                   t_wolf;

int         parse(t_wolf *env, t_map * map, t_player *player);
void        wolf(t_wolf *env);
void        dda_algo(t_wolf *env, t_player *player, t_map *map);
double      deg_to_rad(double deg);
double      rad_to_deg(double rad);

#endif
