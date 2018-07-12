/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:55:22 by fmaury            #+#    #+#             */
/*   Updated: 2018/07/12 18:32:04 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 600
#define HEIGHT 500
#define CUBE 64
#define FOV 60
#define PLANEW 320
#define PLANEH 200

typedef struct      s_wolf
{
    char **map;
}                   t_wolf;

int ft_parse(t_wolf *env);
