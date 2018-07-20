/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:03:05 by fanf              #+#    #+#             */
/*   Updated: 2018/07/19 13:50:43 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double     dist(t_wolf *env, double x, double y)
{
    //  double x1;
    //  double px1;
    //  double y1;
    //  double py1;
    //  double sq;

    //  x1 = env->playerx - x;
    //  px1 = pow(x1, 2);
    //  y1 = env->playery - y;
    //  py1 = pow(x1, 2);
    //  sq = sqrt(pow(env->playerx - x, 2) + pow(env->playery - y, 2));
    //  printf("%f %f %f %f %f", x1, px1, y1, py1, sq);
    return (sqrt(pow((double)env->playerx - x, 2) +
        pow((double)env->playery - y, 2)));
}
