/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:50:19 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/06 18:02:34 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		fix_position(t_wmap *map)
{
	int	x;
	int y;

	y = 1;
	if (map->startX && map->startY)
		return (0);
	while (y < map->mapHeight)
	{
		x = 1;
		while (x < map->mapWidth)
		{
			if (map->map[y][x] == 0)
			{
				if (map->startX == 0 || map->startY == 0)
				{
					map->startY = y;
					map->startX = x;
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static int fix_line(int	*line, int max)
{
	int x;

	x = 0;
	while (x < max)
	{
		line[x] = 1;
		x++;
	}
	return (0);
}

static int fix_col(t_wmap *map, int x)
{
	int y;

	y = 0;
	while (y < map->mapHeight)
	{
		map->map[y][x] = 1;
		y++;
	}
	return (0);
}

int 	fix_walls(t_wmap *map)
{
	fix_line(map->map[0], map->mapWidth);
	fix_line(map->map[map->mapHeight], map->mapWidth);
	fix_col(map, 0);
	fix_col(map, map->mapWidth);
}