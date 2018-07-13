/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:55:22 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/13 17:30:40 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#define WIDTH 600
#define HEIGHT 500
#define CUBE 64
#define FOV 60
#define PLANEW 320
#define PLANEH 200

#include "../Libft/srclib/libft.h"
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

/*
** Mlx.h pour linux
** # include "../utilitaire/minilibxnux/mlx.h"
*/

typedef struct      s_wolf
{
    void            *mlx;
    void            *win;
    int             fd;
    char            **map;
    int             mapx;
    int             mapy;
    double             ray;
    int             playerx;
    int             playery;
    int           fihx;
    int           fihy;
    int             ya;
    int           xa;
}                   t_wolf;

int ft_parse(t_wolf *env);
void    ft_wolf(t_wolf *env);
void    ft_draw(t_wolf *env);
void    ft_find_hori(t_wolf *env);

#endif
