/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:50:19 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/13 14:30:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			fix_position(t_wmap *map)
{
	int	x;
	int y;

	y = 1;
	if (map->start_x && map->start_y)
		return (0);
	while (y < map->map_h)
	{
		x = 1;
		while (x < map->map_w)
		{
			if (map->map[y][x] == 0)
			{
				if (map->start_x == 0 || map->start_y == 0)
				{
					map->start_y = y;
					map->start_x = x;
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static int	fix_line(int *line, int max)
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

static int	fix_col(t_wmap *map, int x)
{
	int y;

	y = 0;
	while (y < map->map_h)
	{
		map->map[y][x] = 1;
		y++;
	}
	return (0);
}

int			fix_walls(t_wmap *map)
{
	fix_line(map->map[0], map->map_w);
	fix_line(map->map[map->map_h - 1], map->map_w);
	fix_col(map, 0);
	fix_col(map, map->map_w);
	return (0);
}

void		check_length(int x_check, int length, int fd)
{
	if (x_check == -1)
	{
		close(fd);
		print_error(2);
	}
	else if (length != -1 && x_check != length)
	{
		close(fd);
		print_error(5);
	}
}
