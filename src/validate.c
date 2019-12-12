/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:57:44 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/12 19:27:01 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			find_zeroes(t_wmap *map)
{
	int x;
	int y;
	int zeroes;

	y = 1;
	zeroes = 0;
	while (y < map->map_h - 1)
	{
		x = 1;
		while (x < map->map_w - 1)
		{
			if (map->map[y][x] == 0)
				zeroes++;
			x++;
		}
		y++;
	}
	if (!zeroes)
		print_error(4);
}

static int		find_hor_wall(int *w_line, int max_length)
{
	int x;

	x = 0;
	while (x < max_length)
	{
		if (w_line[x] != 1)
			return (-1);
		x++;
	}
	return (0);
}

static int		find_ver_wall(t_wmap *map, int x)
{
	int y;

	y = 0;
	while (y < map->map_h)
	{
		if (map->map[y][x] != 1)
			return (-1);
		y++;
	}
	return (0);
}

int				find_walls(t_wmap *map)
{
	if (find_hor_wall(map->map[0], map->map_w) == -1 ||
	find_hor_wall(map->map[map->map_h - 1], map->map_w) == -1 ||
	find_ver_wall(map, 0) == -1 || find_ver_wall(map, map->map_w - 1) == -1)
	{
		map->fixable = 1;
		return (-1);
	}
	return (0);
}

int				find_player(t_wmap *map)
{
	int x;
	int y;
	int pos;

	y = 1;
	pos = 0;
	while (y < map->map_h - 1)
	{
		x = 1;
		while (x < map->map_w - 1)
		{
			if (map->map[y][x] == 9)
			{
				map->map[y][x] = 0;
				map->start_x = x;
				map->start_y = y;
				pos++;
			}
			x++;
		}
		y++;
	}
	return ((pos == 1) ? 0 : -1);
}
