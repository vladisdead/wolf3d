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
# include "SDL2/SDL.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		ev;
	SDL_Surface		*screen_surface;
	SDL_Surface		*anime;
	SDL_Rect		r;
	int				q;
	t_point			point;
}					t_sdl;

typedef struct      s_wolf
{
    t_sdl           sdl;

}                   t_wolf;

void				quit(t_wolf *wolf);
t_sdl				sdl_init(void);
void                sdl_loop(t_wolf *wolf);
void                eventintg(t_wolf *wolf, SDL_Event event);
void                hook_keydown(t_wolf *sdl, SDL_Event event);
void                sdl_clean(t_wolf *wolf);


#endif
