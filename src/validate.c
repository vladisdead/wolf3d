/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:57:44 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/07 14:05:23 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//////проверяет что есть хоть один ноль внутри стен
void 	find_zeroes(t_wmap *map)
{
	int x;
	int y;
	int zeroes;

	y = 1;
	zeroes = 0;
	while (y < map->mapHeight - 1)
	{
		x = 1;
		while (x < map->mapWidth - 1)
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

static int 	find_hor_wall(int *w_line, int max_length)
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

static	int find_ver_wall(t_wmap *map, int x)
{
	int y;

	y = 0;
	while (y < map->mapHeight)
	{
		if (map->map[y][x] != 1)
			return (-1);
		y++;
	}
	return (0);
}
///////чекает стены по сторонам статик функциями выше
int 	find_walls(t_wmap *map)
{
	if (find_hor_wall(map->map[0], map->mapWidth) == -1 ||
	find_hor_wall(map->map[map->mapHeight - 1], map->mapWidth) == -1 ||
	find_ver_wall(map, 0) == -1 || find_ver_wall(map, map->mapWidth - 1) == -1)
	{
		map->fixable = 1;
		return (-1);
	}
	return (0);
}

//////находит 9 = позиция игрока, записывает ее в структуру, ретерн -1 при невалидном вводе или ее отсутствии, не ищет в наружных стенах
int 	find_player(t_wmap *map)
{
	int x;
	int y;
	int pos;

	y = 1;
	pos = 0;
	while (y < map->mapHeight - 1)
	{
		x = 1;
		while (x < map->mapWidth - 1)
		{
			if (map->map[y][x] == 9)
			{
				map->map[y][x] = 0;
				map->startX = x;
				map->startY = y;
				pos++;
			}
			x++;
		}
		y++;
	}
	return ((pos == 1) ? 0 : -1);
}