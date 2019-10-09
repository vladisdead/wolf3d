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

void    sdl_clean(t_sdl *sdl)
{
    SDL_DestroyWindow(sdl->win);
    SDL_Quit();
}

void	quit(t_sdl *q)
{
	sdl_clean(q);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sdl			sdl;
    SDL_Event       event;
	sdl = sdl_init();
	sdl.q = 0;
	sdl_loop(&sdl);
	return (0);
}
