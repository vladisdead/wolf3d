/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:43:55 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/17 09:54:35 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    sdl_clean(t_wolf *wolf)
{
    SDL_DestroyWindow(wolf->sdl.win);
    SDL_Quit();
}

void	quit(t_wolf *wolf)
{
	sdl_clean(wolf);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_wolf		    wolf;
    SDL_Event       event;
	wolf.sdl = sdl_init();
	wolf.sdl.q = 0;
	sdl_loop(&wolf);
	return (0);
}
