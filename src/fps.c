#include "wolf3d.h"

void fps_limit(t_wolf *wolf, Uint32 framelimit)
{
    Uint32 ticks;

    int max;
    ticks = SDL_GetTicks();
    max = (1000 / 70);
    if (framelimit < ticks)
        return ;
    if (framelimit > ticks + max)
        SDL_Delay(max);
    else
        SDL_Delay(framelimit - ticks);
}

void    fps_count(t_wolf *wolf)
{
    char *fps;

    if ((wolf->fpsupdate = SDL_GetTicks()) - wolf->fpscurrent >= 1000)
    {
        fps = malloc(sizeof(char*) * 2);
        wolf->fpscurrent = wolf->fpsupdate;
        fps = ft_itoa(wolf->fps);
        SDL_SetWindowTitle(wolf->pwindow, fps);
        free(fps);
        wolf->fps = 0;
    }
    ++wolf->fps;
}

void    fps(t_wolf *wolf)
{
    fps_limit(wolf, wolf->framelimit);
    wolf->framelimit = SDL_GetTicks() + (1000 / 70);
    fps_count(wolf);
}
