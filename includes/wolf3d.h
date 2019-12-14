/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:27:01 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/13 20:08:17 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "../SDL2/SDL2.framework/Headers/SDL.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <dirent.h>
# define W_W 1200
# define W_H 800
# define T_W 64
# define T_H 64

typedef struct			s_wolf_raycaster
{
	double				planex;
	double				planey;
	double				camerax;
	double				rposx;
	double				rposy;
	int					x;
	int					y;
	double				rdx;
	double				rdy;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				ddistx;
	double				ddisty;
	double				pwd;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				posx;
	double				posy;
	double				dirx;
	double				drawwall;
	double				wallx;
	double				diry;
	double				time;
	double				oldtime;
	double				ms;
	double				rs;
	double				olddirx;
	double				olddiry;
	double				oldplanex;
	double				w_h;
	double				w_w;
	double				oldplaney;
	double				fxwall;
	double				fywall;
	double				dwall;
	double				dplayer;
	double				cdist;
	double				w;
	double				cfloory;
	double				cfloorx;
	int					ftexx;
	int					ftexy;
}						t_wolf_raycaster;

typedef struct			s_wolf_m3d
{
	int					**map;
	int					map_w;
	int					map_h;
	double				start_x;
	double				start_y;
	int					fixable;
	int					tofix;
	int					walls;
	int					pos;
}						t_wmap;

typedef struct			s_wolf
{
	SDL_Window			*pwindow;
	SDL_Renderer		*renderer;
	int					frame;
	t_wmap				*map;
	t_wolf_raycaster	ray;
	SDL_Texture			*texture;
	SDL_Surface			*surf;
	SDL_Surface			*brick;
	SDL_Surface			*floor;
	SDL_Surface			*ceil;
	Uint32				framenum;
	Uint32				framelimit;
	int					fpsupdate;
	int					fpscurrent;
	int					fps;
	char				quit;
	int					mousex;
	int					mousey;
	int					texx;
	int					texy;
	int					d;
	Uint8				*wav_buffer;
	SDL_AudioDeviceID	device_id;

}						t_wolf;

void					raycast(t_wolf *wolf);
void					wolf3d_key_up(t_wolf *wolf);
void					wolf3d_key_down(t_wolf *wolf);
void					wolf3d_key_left(t_wolf *wolf);
void					wolf3d_key_right(t_wolf *wolf);
void					wolf3d_inputs(const unsigned char *keystate,
		t_wolf *wolf);
void					key_hook(SDL_Event *ev, t_wolf *wolf);
void					event(SDL_Event *ev, t_wolf *wolf);
t_wmap					*init_map(char *arg);
int						count_data(char *arg, t_wmap *wolf);
char					***get_buff(char *arg, t_wmap *wolf);
int						**interpret_buff(char *arg, t_wmap *wolf);
void					print_error(int code);
t_wmap					*run_map(int argc, char **argv);
int						find_walls(t_wmap *map);
int						find_player(t_wmap *map);
void					find_zeroes(t_wmap *map);
int						fix_position(t_wmap *map);
int						fix_walls(t_wmap *map);
void					dda_init(t_wolf *wolf);
void					dda(t_wolf *wolf);
void					init_ray(t_wolf *wolf, int x);
void					raycast(t_wolf *wolf);
void					wolf3d_destroy_graphics(t_wolf *wolf);
void					loop_hook(t_wolf *wolf);
void					draw_wall(int x, int start, int end, t_wolf *wolf);
void					draw_sight(t_wolf *wolf);
void					update(t_wolf *wolf);
t_wolf					init_sdl(t_wmap *map);
void					init_params_wolf(t_wolf *wolf);
SDL_Surface				*load_texture(char *path, t_wolf *wolf);
void					get_texture(t_wolf *wolf);
void					fps_limit(Uint32 framelimit);
void					fps(t_wolf *wolf);
void					fps_count(t_wolf *wolf);
void					check_length(int x_check, int length, int fd);
void					floor_ceil(t_wolf *wolf);
int						init_music(t_wolf *wolf);

#endif
