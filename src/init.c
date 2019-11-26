#include "wolf3d.h"

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
    if(!(sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ABGR8888,
                                         SDL_TEXTUREACCESS_STREAMING, WINDW_W, WINDW_H)))
        exit(44);
    if (!(sdl.surf = SDL_CreateRGBSurface(0, WINDW_W, WINDW_H, 32, 0,0,0,0)))
        exit(55);
    if (!(sdl.brick = SDL_LoadBMP("../brick.bmp")))
        exit(66);

    return (sdl);
}


void    init_params_wolf(t_wolf *wolf)
{
    wolf->raycaster.posx = 2;
    wolf->raycaster.posy = 2;
    wolf->raycaster.dirx = -1;
    wolf->raycaster.diry = 0;
    wolf->raycaster.planex = 0;
    wolf->raycaster.planey = 0.5;
    wolf->raycaster.ms = 0.04;
    wolf->raycaster.rs = 0.03;
    wolf->raycaster.w_w = WINDW_W;
    wolf->raycaster.w_h = WINDW_H;
    wolf->quit = 1;
}
