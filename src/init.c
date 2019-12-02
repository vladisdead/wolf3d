#include "wolf3d.h"

SDL_Surface		*load_texture(char *path, t_wolf *wolf)
{
    SDL_Surface		*stock;
    SDL_Surface		*surface;

    stock = SDL_LoadBMP(path);
    if (stock == NULL)
    {
        ft_putstr("Error while loading a texture file\n");
        exit(1);
    }
    surface = SDL_ConvertSurfaceFormat(stock, wolf->surf->format->format, 0);
    SDL_FreeSurface(stock);
    return (surface);
}

t_wolf      init_sdl(void)
{
    t_wolf sdl;


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        exit(11);
    if (!(sdl.pwindow = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED, WINDW_W, WINDW_H, SDL_WINDOW_SHOWN)))
        exit(22);
    if (!(sdl.renderer = SDL_CreateRenderer(sdl.pwindow, -1,0)))
        exit(33);
    if (!(sdl.surf = SDL_CreateRGBSurface(0, WINDW_W, WINDW_H, 32, 0, 0, 0, 0)))
        exit(55);
    if(!(sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ABGR8888,
            SDL_TEXTUREACCESS_STREAMING, WINDW_W, WINDW_H)))
        exit(44);

    return (sdl);
}

void    get_texture(t_wolf *wolf)
{
    if (!(wolf->brick = load_texture("../wall.bmp", wolf)))
        exit(66);
    if (!(wolf->floor = load_texture("../floor.bmp", wolf)))
        exit(77);
    if (!(wolf->ceil = load_texture("../ceil.bmp", wolf)))
        exit(88);
}

void    init_params_wolf(t_wolf *wolf)
{
    wolf->raycaster.posx = 5;
    wolf->raycaster.posy = 5;
    wolf->raycaster.dirx = -1;
    wolf->raycaster.diry = 0;
    wolf->raycaster.planex = 0;
    wolf->raycaster.planey = 0.66;
    wolf->raycaster.ms = 0.06;
    wolf->raycaster.rs = 0.05;
    wolf->raycaster.w_w = WINDW_W;
    wolf->raycaster.w_h = WINDW_H;
    wolf->quit = 1;
    wolf->framenum = 0;
}
