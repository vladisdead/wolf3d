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
# define WINDW_W 800
# define WINDW_H 800
//#define mapWidth 24
//#define mapHeight 24
#define TEXT_W 64
#define TEXT_H 64

typedef struct          s_color_sdl
{
    unsigned char       r;
    unsigned char       g;
    unsigned char       b;
    unsigned char       a;
}                       t_color_sdl;

typedef struct		    s_wolf_raycaster
{
    double			    planex;
    double			    planey;
    double			    camerax;
    double			    rayposx;
    double			    rayposy;
    int                 x;
    int                 y;
    double			    raydirx;
    double			    raydiry;
    int				    mapx;
    int				    mapy;
    double			    sidedistx;
    double			    sidedisty;
    double			    deltadistx;
    double			    deltadisty;
    double			    perpwalldist;
    int				    stepx;
    int				    stepy;
    int				    hit;
    int				    side;
    int				    lineheight;
    int				    drawstart;
    int				    drawend;
    double              posx;
    double              posy;
    double              dirx;
    double              drawwall;
    double              wallx;
    double              diry;
    double              time;
    double              oldtime;
    double              ms;
    double              rs;
    double              move_up;
    double              move_down;
    double              move_left;
    double              move_right;
    double              olddirx;
    double              olddiry;
    double              oldplanex;
    double              w_h;
    double              w_w;
    double              oldplaney;
    double              floorxwall;
    double              floorywall;
    double              distwall;
    double              distplayer;
    double              currentdist;
    double              weight;
    double              currentfloory;
    double              currentfloorx;
    int                 floortexx;
    int                 floortexy;
    t_color_sdl         color;
    t_color_sdl         sight;
}					    t_wolf_raycaster;

typedef struct		    s_wolf_m3d
{
    int			        **map;
    char			    name[1024];
	int				    mapW;
	int 			    mapH;
	double 				startX;
	double 				startY;
	int 				fixable;
	int 				tofix;
	int 				map_width_differs;
	int 				walls;
	int 				pos;
}					    t_wmap;

typedef struct		    s_wolf
{
    SDL_Window		    *pwindow;
    SDL_Renderer	    *renderer;
    int				    frame;
    t_wmap			    *map;
    t_wolf_raycaster    raycaster;
    SDL_Texture		    *texture;
    SDL_Surface         *surf;
    SDL_Surface         *brick;
    SDL_Surface         *floor;
    SDL_Surface         *ceil;
    Uint32		        framenum;
    Uint32              framelimit;
    int                 fpsupdate;
    int                 fpscurrent;
    int                 fps;
    char			    quit;
    int				    mousex;
    int				    mousey;
    int                 texx;
    int                 texy;
    int                 d;
}					    t_wolf;

typedef struct          s_point
{
    int                 x;
    int                 y;
    int                 z;
    int                 color;
}                       t_point;

typedef struct			s_line
{
    t_point				start;
    t_point				end;
    t_point				point;
    t_point				delta;
    int					steep;
    int					error;
    int					ystep;
}                       t_line;
    /*keyhook*/
void                    raycast(t_wolf *wolf);
static void	            wolf3d_key_up(const unsigned char *keystate, t_wolf *wolf);
static void	            wolf3d_key_down(const unsigned char *keystate, t_wolf *wolf);
static void	            wolf3d_key_left(t_wolf *wolf);
static void	            wolf3d_key_right(t_wolf *wolf);
void		            wolf3d_inputs(const unsigned char *keystate, t_wolf *wolf);
void                    key_hook(SDL_Event *ev, t_wolf *wolf);
void                    event(SDL_Event *ev, t_wolf *wolf);
    /*read map*/
t_wmap                  *init_map(char *arg);
static int              count_digits(char *line);
int                     count_data(char *arg, t_wmap *wolf);
char                    ***get_buff(char *arg, t_wmap *wolf);
int                     **interpret_buff(char *arg, t_wmap *wolf);
void					print_error(int code);
t_wmap					*run_map(int argc, char **argv);


	/*validate && fix*/
int 					find_walls(t_wmap *map);
int 					find_player(t_wmap *map);
void					find_zeroes(t_wmap *map);
int						fix_position(t_wmap *map);
int 					fix_walls(t_wmap *map);

    /*raycast*/
void                    dda_init(t_wolf *wolf);
void                    dda(t_wolf *wolf);
void                    init_ray(t_wolf *wolf, int x);
void                    raycast(t_wolf *wolf);
    /*main*/
void		            wolf3d_destroy_graphics(t_wolf *wolf);
void                    loop_hook(t_wolf *wolf);
    /*drawer*/
void                    sdl_pixel(t_wolf *wolf, int x, int y, uint32_t *color);
void                    draw_wall(int x, int start, int end, t_wolf *wolf);
void                    draw_sight(t_wolf *wolf);
void                    update(t_wolf *wolf);
    /*init*/
t_wolf                  init_sdl(void);
void                    init_params_wolf(t_wolf *wolf);
SDL_Surface		        *load_texture(char *path, t_wolf *wolf);
void                    get_texture(t_wolf *wolf);
static void fps_limit(t_wolf *wolf,  Uint32 framelimit);
void    fps(t_wolf *wolf);
void    fps_count(t_wolf *wolf);

#endif
