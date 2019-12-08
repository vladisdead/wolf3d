/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:18:39 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/06 16:04:50 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
////////////////ИННИТ МАП маллочит память размером t_wmap и запускает функции получения
t_wmap *init_map(char *arg)
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
//////////считает количество чисел, разделенных запятой, в строке
static int count_digits(char *line)
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
		while(line[i] && line[i] != ',')
			i++;
		if (line[i] == ',')
			i++;
	}
	return (result);
}

int count_data(char *arg, t_wmap *wolf)
{
	int fd;
	int ret;
	int x_check;
	char *line;

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
			x_check = count_digits(line);////считает числа
			if (wolf->mapWidth > 0 && !wolf->map_width_differs)
				wolf->map_width_differs = (wolf->mapWidth != x_check ? 1 : 0);////////указывает на различную длину строк
			wolf->mapWidth = (wolf->mapWidth < x_check ? x_check : wolf->mapWidth);//////определяет ширину карты исходя из самой длинной строки.

			wolf->mapHeight++;////////определяет высоту карты по количеству строк
			ft_strdel(&line);
		}
	}
	close(fd);
	if (wolf->mapWidth > 2 && wolf->mapHeight > 2)
		return (0);//////all good
	return (-1);//////data is incorrect
}
//////////вытаскивает карту в такстовом виде
char ***get_buff(char *arg, t_wmap *wolf)
{
	int fd;
	int counter;
	char *line;
	char ***buff;

	if (!(buff = (char***)ft_memalloc(sizeof(char**) * wolf->mapHeight)))
		print_error(2);///////////БЛЯДЬ ЧО ЭТО ПОЧЕМУ РАБОТАЕТ ТО ВДРУГ Э ИЛИ НЕ РАБОТАЕТ Я ЧОТ НЕ ЕБУ
	counter = 0;
	fd = open(arg, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		buff[counter] = ft_strsplit(line, ',');////////ЗАМЕНИ НА ПРОБЕЛЫ
		free(line);
		counter++;
	}
	close(fd);
	return (buff);
}
/////////переводит текстовую карту в инты
int **interpret_buff(char *arg, t_wmap *wolf)
{
	char ***buff;
	int **result;
	int counter_x;
	int counter_y;
	counter_y = 0;
	if (!(buff = get_buff(arg, wolf)))
		print_error(2);
	result = (int**)ft_memalloc(sizeof(int*) * wolf->mapHeight);
	if (!result)
		print_error(2);
	while (counter_y < wolf->mapHeight)
	{
		counter_x = 0;
		result[counter_y] = ft_memalloc(sizeof(int) * wolf->mapWidth);
		if (!result[counter_y])
			print_error(2);
		while (counter_x < wolf->mapWidth)
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