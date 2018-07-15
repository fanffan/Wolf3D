/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanf <fanf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:14:38 by fanf              #+#    #+#             */
/*   Updated: 2018/07/14 23:58:22 by fanf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double     deg_to_rad(int deg)
{
    return (M_PI * deg / 180);
}

double     rad_to_deg(double rad)
{
    return (rad * 180 / M_PI);
}