/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:03:12 by fmaury            #+#    #+#             */
/*   Updated: 2018/10/01 15:29:17 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		line_checker(t_map *map, int line_nb)
{
	int		i;
	char	*line;

	i = 0;
	line = map->map[line_nb];
	while (line[i])
	{
		if (line_nb == 0 && line[i] != '1')
			return (0);
		else if (line_nb == map->y - 1 && line[i] != '1')
			return (0);
		else if (line[i] != '1' && line[i] != '0' && line[i] != 'x')
			return (0);
		i++;
	}
	return (1);
}

int		checker(t_map *map)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (map->y < 2)
		return (0);
	while (map->map[i])
	{
		if (i == 0)
			len = ft_strlen(map->map[0]);
		if (len == 0 || ft_strlen(map->map[i]) != len || (map->map[i][0] != '1')
		|| (map->map[i][len - 1] != '1') || !line_checker(map, i))
			return (0);
		i++;
	}
	return (1);
}
