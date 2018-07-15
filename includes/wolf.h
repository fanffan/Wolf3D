/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:55:22 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/15 12:36:45 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#define WIDTH 600
#define HEIGHT 500
#define CUBE 64
#define FOV 60
#define DISTPLAY 277

#include "../libft/srclib/libft.h"
#include <fcntl.h>
# include "../minilibx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
/*
** Mlx.h pour linux
** # include "../minilibx_linux/mlx.h"
*/

typedef struct      s_wolf
{
    void            *mlx;
    void            *win;
    void			*img;
    int	            *data;
    int             fd;
    char            **map;
    int             mapx;
    int             mapy;
    double          ray;
    double          angle_cast;
    int             playerx;
    int             playery;
    int             ihx;
    int             ihy;
    int             ivx;
    int             ivy;
    int             ya;
    int             xa;
}                   t_wolf;

int ft_parse(t_wolf *env);
void    ft_wolf(t_wolf *env);
void    ft_draw(t_wolf *env);
int    ft_find_hori(t_wolf *env);
void    ft_find_vert(t_wolf *env);
int     ft_dist(t_wolf *env, int x, int y);
double     deg_to_rad(int deg);
double     rad_to_deg(double rad);

#endif
