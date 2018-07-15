/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:03:05 by fanf              #+#    #+#             */
/*   Updated: 2018/07/14 23:38:46 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     ft_dist(t_wolf *env, int x, int y)
{
    // int x1;
    // int px1;
    // int y1;
    // int py1;
    // int sq;

    // x1 = env->playerx - x;
    // px1 = pow(x1, 2);
    // y1 = env->playery - y;
    // py1 = pow(x1, 2);
    // sq = sqrt(pow(env->playerx - x, 2) + pow(env->playery - y, 2));
    // printf("%d %d %d %d %d", x1, px1, y1, py1, sq);
    return (sqrt(pow(env->playerx - x, 2) + pow(env->playery - y, 2)));
}