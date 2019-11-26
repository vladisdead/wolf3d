/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/11/25 16:38:15 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int worldMap[mapWidth][mapHeight]=
        {
                {1,1,1,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,5,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,1,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,1}
        };



void		wolf3d_destroy_graphics(t_wolf *wolf)
{
    //SDL_DestroyTexture(wolf->skybox);
    SDL_DestroyTexture(wolf->texture);
    wolf->skybox = NULL;
    wolf->texture = NULL;
    SDL_DestroyRenderer(wolf->renderer);
    SDL_DestroyWindow(wolf->pwindow);
    wolf->pwindow = NULL;
    wolf->renderer = NULL;
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
    if(!(sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ABGR8888,
            SDL_TEXTUREACCESS_STREAMING, WINDW_W, WINDW_H)))
        exit(44);
    if (!(sdl.surf = SDL_CreateRGBSurface(0, WINDW_W, WINDW_H, 32, 0,0,0,0)))
        exit(55);

    if (!(sdl.brick = SDL_LoadBMP("../brick.bmp")))
        exit(66);

    return (sdl);
}

unsigned char    get_pixel(SDL_Surface *surf, int x, int y)
{
    unsigned char  *pixels = (Uint32 *)surf->pixels;
    return (pixels[(y * surf->w) + x]);
}

void    sdl_pixel(t_wolf *wolf, int x, int y, t_color_sdl color)
{
    Uint32 *pixels;
    int width;

    pixels = (Uint32 *)wolf->brick->pixels;
    width = wolf->surf->w;
    if (x < 0 && x >= wolf->surf->w)
        return ;
    if (y < 0 && y >= wolf->surf->h)
        return ;

    pixels[4 *(y * width + x)] = 0x123123;

}

void    draw_img(SDL_Surface *img, int x, int y, int w, int h, int x2, int y2, t_wolf *wolf)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;

    SDL_Rect dest2;

    dest2.x = x2;
    dest2.y = y2;
    dest2.w = w;
    dest2.h = h;
    SDL_BlitSurface(img, &dest2, wolf->surf, &dest);

}

void    update(t_wolf *wolf)
{
    SDL_Rect dstrect;

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = wolf->surf->w;
    dstrect.h = wolf->surf->h;

    SDL_Texture *text = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);
    SDL_Texture *t = SDL_CreateTextureFromSurface(wolf->renderer, wolf->brick);
    SDL_RenderCopy(wolf->renderer, text, NULL, &dstrect);
    SDL_DestroyTexture(text);

    SDL_RenderPresent(wolf->renderer);
    SDL_FillRect(wolf->surf, NULL, 0x858585);
}

void    key_hook(SDL_Event *ev, t_wolf *wolf)
{
    if (ev->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        wolf->quit = 1;

}

void    event(SDL_Event *ev, t_wolf *wolf)
{
    if (ev->type == SDL_KEYDOWN)
        key_hook(ev, wolf);
    if (ev->type == SDL_QUIT)
        wolf->quit = 1;
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

static void	wolf3d_key_up(const unsigned char *keystate, t_wolf *wolf)
{
    if (worldMap[(int)(wolf->raycaster.posx + wolf->raycaster.dirx * wolf->raycaster.ms)][(int)wolf->raycaster.posy] == 0)
        wolf->raycaster.posx += wolf->raycaster.dirx * wolf->raycaster.ms;
    if (worldMap[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy + wolf->raycaster.diry * wolf->raycaster.ms)] == 0)
        wolf->raycaster.posy += wolf->raycaster.diry * wolf->raycaster.ms;
}

static void	wolf3d_key_down(const unsigned char *keystate, t_wolf *wolf)
{
    if (worldMap[(int)(wolf->raycaster.posx - wolf->raycaster.dirx * wolf->raycaster.ms)][(int)wolf->raycaster.posy] == 0)
        wolf->raycaster.posx -= wolf->raycaster.dirx * wolf->raycaster.ms;
    if (worldMap[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy - wolf->raycaster.diry * wolf->raycaster.ms)] == 0)
        wolf->raycaster.posy -= wolf->raycaster.diry * wolf->raycaster.ms;
}

static void	wolf3d_key_left(t_wolf *wolf)
{
    wolf->raycaster.olddirx = wolf->raycaster.dirx;
    wolf->raycaster.dirx = wolf->raycaster.dirx * cos(wolf->raycaster.rs) - wolf->raycaster.diry * sin(wolf->raycaster.rs);
    wolf->raycaster.diry = wolf->raycaster.olddirx * sin(wolf->raycaster.rs) + wolf->raycaster.diry * cos (wolf->raycaster.rs);
    wolf->raycaster.oldplanex = wolf->raycaster.planex;
    wolf->raycaster.planex = wolf->raycaster.planex * cos(wolf->raycaster.rs) - wolf->raycaster.planey * sin(wolf->raycaster.rs);
    wolf->raycaster.planey = wolf->raycaster.oldplanex * sin(wolf->raycaster.rs) + wolf->raycaster.planey * cos(wolf->raycaster.rs);
}

static void	wolf3d_key_right(t_wolf *wolf)
{
    wolf->raycaster.olddirx = wolf->raycaster.dirx;
    wolf->raycaster.dirx = wolf->raycaster.dirx * cos(wolf->raycaster.rs * -1) - wolf->raycaster.diry * sin(wolf->raycaster.rs * -1);
    wolf->raycaster.diry = wolf->raycaster.olddirx * sin(wolf->raycaster.rs * -1) + wolf->raycaster.diry * cos(wolf->raycaster.rs * -1);
    wolf->raycaster.oldplanex = wolf->raycaster.planex;
    wolf->raycaster.planex = wolf->raycaster.planex * cos(wolf->raycaster.rs * -1) - wolf->raycaster.planey * sin(wolf->raycaster.rs * -1);
    wolf->raycaster.planey = wolf->raycaster.oldplanex * sin(wolf->raycaster.rs * -1) + wolf->raycaster.planey * cos(wolf->raycaster.rs * -1);
}

void		wolf3d_inputs(const unsigned char *keystate, t_wolf *wolf)
{
    if (keystate[SDL_SCANCODE_ESCAPE])
        wolf->quit = 0;
    if (keystate[SDL_SCANCODE_UP])
        wolf3d_key_up(keystate, wolf);
    if (keystate[SDL_SCANCODE_DOWN])
        wolf3d_key_down(keystate, wolf);
    if (keystate[SDL_SCANCODE_RIGHT])
        wolf3d_key_right(wolf);
    if (keystate[SDL_SCANCODE_LEFT])
        wolf3d_key_left(wolf);
    raycast(wolf);
}


void    draw_wall(int x, int start, int end, t_wolf *wolf)
{
    while (++start < end)
        sdl_pixel(wolf, x, start, wolf->raycaster.color);
}

void    draw_sight(t_wolf *wolf)
{
    int x;
    int y;

    wolf->raycaster.sight = (t_color_sdl){0, 0, 0, 0};
    x = 445;
    y = 445;
    while (x <= 455)
    {
        sdl_pixel(wolf, x, 450, wolf->raycaster.sight);
        x++;
    }
    while (y <= 455)
    {
        sdl_pixel(wolf, 450, y, wolf->raycaster.sight);
        y++;
    }

}

void    dda_init(t_wolf *wolf)
{
    if (wolf->raycaster.raydirx < 0)
    {
        wolf->raycaster.stepx = -1;
        wolf->raycaster.sidedistx = (wolf->raycaster.rayposx - (double)wolf->raycaster.mapx) * wolf->raycaster.deltadistx;
    }
    else
    {
        wolf->raycaster.stepx = 1;
        wolf->raycaster.sidedistx = ((double)wolf->raycaster.mapx + 1.0 - wolf->raycaster.rayposx) * wolf->raycaster.deltadistx;
    }
    if (wolf->raycaster.raydiry < 0)
    {
        wolf->raycaster.stepy = -1;
        wolf->raycaster.sidedisty = (wolf->raycaster.rayposy - (double)wolf->raycaster.mapy) * wolf->raycaster.deltadisty;
    }
    else
    {
        wolf->raycaster.stepy = 1;
        wolf->raycaster.sidedisty = ((double)wolf->raycaster.mapy + 1.0 - wolf->raycaster.rayposy) * wolf->raycaster.deltadisty;
    }
}

void    dda(t_wolf *wolf)
{
    wolf->raycaster.hit = 0;
    while (wolf->raycaster.hit == 0)
    {
        if (wolf->raycaster.sidedistx < wolf->raycaster.sidedisty)
        {
            wolf->raycaster.sidedistx += wolf->raycaster.deltadistx;
            wolf->raycaster.mapx += wolf->raycaster.stepx;
            wolf->raycaster.side = 0;
        }
        else
        {
            wolf->raycaster.sidedisty += wolf->raycaster.deltadisty;
            wolf->raycaster.mapy += wolf->raycaster.stepy;
            wolf->raycaster.side = 1;
        }
        if (worldMap[wolf->raycaster.mapx][wolf->raycaster.mapy] > 0)
            wolf->raycaster.hit = 1;
    }
}

void   init_ray(t_wolf *wolf, int x)
{
    wolf->raycaster.camerax = 2 * x / (double)WINDW_H - 1;
    wolf->raycaster.rayposx = wolf->raycaster.posx;
    wolf->raycaster.rayposy = wolf->raycaster.posy;
    wolf->raycaster.raydirx = wolf->raycaster.dirx + wolf->raycaster.planex * wolf->raycaster.camerax;
    wolf->raycaster.raydiry = wolf->raycaster.diry + wolf->raycaster.planey * wolf->raycaster.camerax;
    wolf->raycaster.mapx = (int)wolf->raycaster.rayposx;
    wolf->raycaster.mapy = (int)wolf->raycaster.rayposy;
    wolf->raycaster.deltadistx = sqrt(1 +(wolf->raycaster.raydiry * wolf->raycaster.raydiry)
                                         / (wolf->raycaster.raydirx * wolf->raycaster.raydirx));
    wolf->raycaster.deltadisty = sqrt(1 +(wolf->raycaster.raydirx * wolf->raycaster.raydirx)
                                         / (wolf->raycaster.raydiry * wolf->raycaster.raydiry));
    dda_init(wolf);
    dda(wolf);
    if (wolf->raycaster.side == 0)
        wolf->raycaster.perpwalldist = fabs((wolf->raycaster.mapx - wolf->raycaster.rayposx + (1.0 - wolf->raycaster.stepx) / 2) / wolf->raycaster.raydirx);
    else
        wolf->raycaster.perpwalldist = fabs((wolf->raycaster.mapy - wolf->raycaster.rayposy + (1.0 - wolf->raycaster.stepy) / 2) / wolf->raycaster.raydiry);
}

void   raycast(t_wolf *wolf)
{
    wolf->raycaster.x = -1;
    while (++wolf->raycaster.x < WINDW_W)
    {
        init_ray(wolf, wolf->raycaster.x);
        if (wolf->raycaster.camerax <= 0.05)
            wolf->raycaster.camerax = 0.05;
        wolf->raycaster.lineheight = abs((int)(WINDW_H / wolf->raycaster.perpwalldist));
        wolf->raycaster.drawstart = (-1 * (wolf->raycaster.lineheight)) / 2 + WINDW_H / 2;
        if (wolf->raycaster.drawstart < 0)
            wolf->raycaster.drawstart = 0;
        wolf->raycaster.drawend = wolf->raycaster.lineheight / 2 + WINDW_H / 2;
        if (wolf->raycaster.drawend >= WINDW_H)
            wolf->raycaster.drawend = WINDW_H - 1;
        if (wolf->raycaster.side == 0)
        {
            if (wolf->raycaster.stepx < 0)
                wolf->raycaster.color = (t_color_sdl) {217, 141, 141, 1};
            else
                wolf->raycaster.color = (t_color_sdl) {166, 141, 217, 1};
        }
        else
        {
            if (wolf->raycaster.stepy > 0)
                wolf->raycaster.color = (t_color_sdl) {141, 217, 193, 1};
            else
                wolf->raycaster.color = (t_color_sdl) {197, 217, 141, 1};
        }
        draw_wall(wolf->raycaster.x, wolf->raycaster.drawstart - 1, wolf->raycaster.drawend, wolf);
        draw_sight(wolf);
    }
}



void    loop_hook(t_wolf *wolf)
{
    SDL_Event   ev;
    Uint8 *key;

    key = (Uint8 *)SDL_GetKeyboardState(NULL);
    while (wolf->quit != 0)
    {
        while(SDL_PollEvent(&ev))
            event(&ev, wolf);
        raycast(wolf);
        wolf3d_inputs(key, wolf);
        update(wolf);

    }
}

int main(int argc, char **argv)
{
    t_wolf sdl;


    sdl = init_sdl();
    init_params_wolf(&sdl);
    loop_hook(&sdl);
    wolf3d_destroy_graphics(&sdl);
    return 0;
}