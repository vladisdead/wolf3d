#include "wolf3d.h"

void	wolf3d_key_up(const unsigned char *keystate, t_wolf *wolf)
{

    if ((wolf->map->map[(int)(wolf->raycaster.posx + wolf->raycaster.dirx * wolf->raycaster.ms)][(int)wolf->raycaster.posy]) == 0
    && (wolf->map->map[(int)(wolf->raycaster.posx + wolf->raycaster.dirx * wolf->raycaster.ms + 0.1)][(int)wolf->raycaster.posy] != 1)
    && (wolf->map->map[(int)(wolf->raycaster.posx + wolf->raycaster.dirx * wolf->raycaster.ms - 0.1)][(int)wolf->raycaster.posy] != 1))
    {
        wolf->raycaster.posx += wolf->raycaster.dirx * wolf->raycaster.ms;
    }
    if ((wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy + wolf->raycaster.diry * wolf->raycaster.ms)] == 0)
    && ((wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy + wolf->raycaster.diry * wolf->raycaster.ms + 0.1)] != 1))
    && (wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy + wolf->raycaster.diry * wolf->raycaster.ms - 0.1)] != 1))
    {
        wolf->raycaster.posy += wolf->raycaster.diry * wolf->raycaster.ms;
    }
}

void	wolf3d_key_down(const unsigned char *keystate, t_wolf *wolf)
{
    if ((wolf->map->map[(int)(wolf->raycaster.posx - wolf->raycaster.dirx * wolf->raycaster.ms)][(int)wolf->raycaster.posy] == 0)
    && (wolf->map->map[(int)(wolf->raycaster.posx - wolf->raycaster.dirx * wolf->raycaster.ms + 0.1)][(int)wolf->raycaster.posy] != 1)
    && (wolf->map->map[(int)(wolf->raycaster.posx - wolf->raycaster.dirx * wolf->raycaster.ms - 0.1)][(int)wolf->raycaster.posy] != 1))
        wolf->raycaster.posx -= wolf->raycaster.dirx * wolf->raycaster.ms;
    if ((wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy - wolf->raycaster.diry * wolf->raycaster.ms)] == 0)
    &&(wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy - wolf->raycaster.diry * wolf->raycaster.ms + 0.1)] != 1)
    &&(wolf->map->map[(int)wolf->raycaster.posx][(int)(wolf->raycaster.posy - wolf->raycaster.diry * wolf->raycaster.ms - 0.1)] != 1))
        wolf->raycaster.posy -= wolf->raycaster.diry * wolf->raycaster.ms;
}

void	wolf3d_key_left(t_wolf *wolf)
{
    wolf->raycaster.olddirx = wolf->raycaster.dirx;
    wolf->raycaster.dirx = wolf->raycaster.dirx * cos(wolf->raycaster.rs) - wolf->raycaster.diry * sin(wolf->raycaster.rs);
    wolf->raycaster.diry = wolf->raycaster.olddirx * sin(wolf->raycaster.rs) + wolf->raycaster.diry * cos (wolf->raycaster.rs);
    wolf->raycaster.oldplanex = wolf->raycaster.planex;
    wolf->raycaster.planex = wolf->raycaster.planex * cos(wolf->raycaster.rs) - wolf->raycaster.planey * sin(wolf->raycaster.rs);
    wolf->raycaster.planey = wolf->raycaster.oldplanex * sin(wolf->raycaster.rs) + wolf->raycaster.planey * cos(wolf->raycaster.rs);
}

void	wolf3d_key_right(t_wolf *wolf)
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
