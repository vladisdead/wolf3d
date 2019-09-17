/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:11:30 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/17 09:38:37 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "SDL.h"
# include "libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_sdl
{
	SDL_DisplayMode	displaymode;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		ev;
	SDL_Surface		*screen_surface;
	SDL_Surface		*anime;
	SDL_Rect		r;
	int				q;
	t_point			point;
}					t_sdl;

void				quit(t_sdl *q);
t_sdl				*sdl_init(void);
void				load_texture(t_sdl *sdl);
#endif
