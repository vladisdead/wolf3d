/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:18:39 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/12 16:59:57 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_wmap		*init_map(char *arg)
{
	t_wmap *wolf_map;

	wolf_map = NULL;
	if (!(wolf_map = (t_wmap*)ft_memalloc(sizeof(t_wmap))))
		print_error(2);
	if (!count_data(arg, wolf_map))
	{
		wolf_map->map = interpret_buff(arg, wolf_map);
		ft_strcpy(wolf_map->name, arg);
		return (wolf_map);
	}
	free(wolf_map);
	print_error(4);
	return (NULL);
}

static int	count_digits(char *line)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			result++;
		while (line[i] && line[i] != ',')
			i++;
		if (line[i] == ',')
			i++;
	}
	return (result);
}

int			count_data(char *arg, t_wmap *wolf)
{
	int		fd;
	int		ret;
	int		x_check;
	char	*line;

	x_check = 0;
	ret = 1;
	fd = open(arg, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			close(fd);
			return (-1);
		}
		else if (ret == 1)
		{
			x_check = count_digits(line);
			if (wolf->mapW > 0 && !wolf->map_width_differs)
				wolf->map_width_differs = (wolf->mapW != x_check ? 1 : 0);
			wolf->mapW = (wolf->mapW < x_check ? x_check : wolf->mapW);
			wolf->mapH++;
			ft_strdel(&line);
		}
	}
	close(fd);
	if (wolf->mapW > 2 && wolf->mapH > 2)
		return (0);
	return (-1);
}

char		***get_buff(char *arg, t_wmap *wolf)
{
	int		fd;
	int		counter;
	char	*line;
	char	***buff;

	if (!(buff = (char***)ft_memalloc(sizeof(char**) * wolf->mapH)))
		print_error(2);
	counter = 0;
	fd = open(arg, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		buff[counter] = ft_strsplit(line, ',');
		free(line);
		counter++;
	}
	close(fd);
	return (buff);
}

int			**interpret_buff(char *arg, t_wmap *wolf)
{
	char	***buff;
	int		**result;
	int		counter_x;
	int		counter_y;

	counter_y = 0;
	if (!(buff = get_buff(arg, wolf)))
		print_error(2);
	if (!(result = (int**)ft_memalloc(sizeof(int*) * wolf->mapH)))
		print_error(2);
	while (counter_y < wolf->mapH && !(counter_x = 0))
	{
		if (!(result[counter_y] = ft_memalloc(sizeof(int) * wolf->mapW)))
			print_error(2);
		while (counter_x < wolf->mapW)
		{
			result[counter_y][counter_x] = ft_atoi(buff[counter_y][counter_x]);
			free(buff[counter_y][counter_x]);
			counter_x++;
		}
		free(buff[counter_y]);
		counter_y++;
	}
	free(buff);
	return (result);
}
