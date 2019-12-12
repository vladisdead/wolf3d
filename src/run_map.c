/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:17:36 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/06 17:47:23 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_error(int code)
{
	if (code == 1)//////Код для USAGE
		ft_putstr ("Usage: Wolf3d + optional -f + map\n");
	else if (code == 2)/////invalid read
		ft_putstr_fd("Are you trying to SEGV me?\n", 2);
	else if (code == 3)//////invalid map but fixable
		ft_putstr_fd("Invalid map, try -f or make a right one\n", 2);
	else if (code == 4)//////uncool stuff
		ft_putstr_fd("This map is so wrong I won't even try to fix it, no sir\n", 2);
	exit(-1);

}

static void		validate_map(t_wmap *map)
{
	find_zeroes(map);
	map->walls = find_walls(map);
	map->pos = find_player(map);
	if (map->walls || map->pos)
		map->fixable = 1;
}

static void		fix_map(t_wmap *map)
{
	if (map->walls == -1)
		fix_walls(map);
	if (map->pos == -1)
		fix_position(map);
}

t_wmap	*run_map(int argc, char **argv)
{
	t_wmap	*map;

	if ((argc == 3 && !ft_strequ(argv[2], "-f")) || argc < 2 || argc > 3)
		print_error(1);
	map = init_map(argv[1]);
	if (argc == 3 && ft_strequ(argv[2], "-f"))
		map->tofix = 1;
	validate_map(map);
	if (map->tofix && map->fixable > 0)
		fix_map(map);
	else if (map->fixable == -1)
		print_error(4);
	else if (map->fixable > 0 && !map->tofix)
		print_error(3);
	return (map);
}