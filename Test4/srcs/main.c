/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:43:55 by cmicha            #+#    #+#             */
/*   Updated: 2019/10/14 11:42:19 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	quit(t_sdl *q)
{
	SDL_DestroyRenderer(q->ren);
	SDL_DestroyWindow(q->win);
	SDL_Quit();
}

int		main(int argc, char **argv)
{
	t_sdl			sdl;
	t_p				player;

	sdl.reader.nameof = argv[1];
	sdl.reader.fd = open(argv[1], O_RDONLY);
	player_init(player);
	if (parser(&sdl.reader) == -1)
	{
		ft_putendl("Check map for errors!");
		return (0);
	}
	get_z(&sdl.reader);
	sdl = sdl_init();
	sdl_loop(&sdl);
	quit(&sdl);
	return (1);
}

