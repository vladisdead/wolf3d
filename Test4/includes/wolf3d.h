/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:11:30 by cmicha            #+#    #+#             */
/*   Updated: 2019/10/14 11:09:57 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "SDL.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define HEIGHT 512
# define WIDTH 512
# define MAP_WIDTH 24
# define MAP_HEIGTH 24

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_line
{
	t_point			start;
	t_point			end;
	t_point			point;
	t_point			delta;
	int				steep;
	int				error;
	int				ystep;
}					t_line;

typedef struct		s_p
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
}					t_p;

typedef	struct		s_read
{
	int				fd;
	int				**grid;
	int				row;
	int				column;
	int				*z_in_grid;
	char			*nameof;
}					t_read;

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
	t_read			reader;
}					t_sdl;

void				quit(t_sdl *q);
t_sdl				sdl_init(void);
void				load_texture(t_sdl *sdl);
void				player_init(t_p player);
int					**init_map(void);
void				sdl_line(t_sdl sdl, t_point a, t_point b);
int					pack_color(int r, int g, int b, int a);
void				unpack_color(int color, unsigned int *r, unsigned int *g,
unsigned int *b);
void				drop_ppm_image(const char *filename, int *image,
						size_t w, size_t h);
int					helper_all_tab(t_read *parse, char *line);
int					alloc_tab(t_read *parse);
int					parser(t_read *parse);
void				get_z(t_read *wolf);
void				sdl_loop(t_sdl *sdl);

#endif
