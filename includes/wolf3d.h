/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:11:30 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/16 14:08:03 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "SDL.h"
# include "libft.h"

typedef struct	s_sdl
{
	SDL_DisplayMode	displaymode;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		ev;
	SDL_Surface		*screen_surface;
	int				q;
}				t_sdl;

int	quit(t_sdl q);

#endif
