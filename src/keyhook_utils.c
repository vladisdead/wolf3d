#include "wolf3d.h"

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