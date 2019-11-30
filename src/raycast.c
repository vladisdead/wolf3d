#include "wolf3d.h"

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
        if (wolf->map->map[wolf->raycaster.mapx][wolf->raycaster.mapy] > 0)
            wolf->raycaster.hit = 1;
    }
}

void   init_ray(t_wolf *wolf, int x)
{
    wolf->raycaster.camerax = 2 * x / (double)WINDW_H - 1.0;
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
    {
        wolf->raycaster.perpwalldist = fabs(
                (wolf->raycaster.mapx - wolf->raycaster.rayposx + (1.0 - wolf->raycaster.stepx) / 2) /
                wolf->raycaster.raydirx);
        wolf->raycaster.drawwall = fabs(
                (wolf->raycaster.mapx - 0.3 - wolf->raycaster.rayposx + (1.0 - wolf->raycaster.stepx) / 2) /
                wolf->raycaster.raydirx);
    }
    else
    {
        wolf->raycaster.perpwalldist = fabs(
                (wolf->raycaster.mapy - wolf->raycaster.rayposy + (1.0 - wolf->raycaster.stepy) / 2) /
                wolf->raycaster.raydiry);
        wolf->raycaster.drawwall = fabs(
                (wolf->raycaster.mapy - 0.3 -wolf->raycaster.rayposy + (1.0 - wolf->raycaster.stepy) / 2) /
                wolf->raycaster.raydiry);
    }
}

void   raycast(t_wolf *wolf)
{
    wolf->raycaster.x = -1;
    while (++wolf->raycaster.x < WINDW_W)
    {
        double wall;

        init_ray(wolf, wolf->raycaster.x);

        wolf->raycaster.lineheight = abs((int)(WINDW_H / wolf->raycaster.perpwalldist));
        wolf->raycaster.drawstart =  ((-wolf->raycaster.lineheight)) / 2 + WINDW_H / 2;
        if (wolf->raycaster.drawstart < 0)
            wolf->raycaster.drawstart = 0;
        wolf->raycaster.drawend = wolf->raycaster.lineheight / 2 + WINDW_H / 2;
        if (wolf->raycaster.drawend >= WINDW_H)
            wolf->raycaster.drawend = WINDW_H - 1;
        draw_wall(wolf->raycaster.x, wolf->raycaster.drawstart - 1, wolf->raycaster.drawend, wolf);
        draw_sight(wolf);
    }
}