#include <stdio.h>
#include "wolf3d.h"

int worldMap[mapWidth][mapHeight]=
        {
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
                {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
                {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
        };

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

int		readfile(char *file, char *buffer)
{
    int		fd;
    int		i;

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        perror(strerror(errno));
        return (-1);
    }
    i = 0;
    while ((read(fd, buffer + i, sizeof(buffer))) != 0)
        i += sizeof(buffer);
    buffer[i] = '\0';
    buffer[i + 1] = '\0';
    close(fd);
    return (0);
}


t_wmap		*wolf3d_map_create(void)
{
    t_wmap		*map;

    if (!(map = (t_wmap *)ft_memalloc(sizeof(t_wmap))))
        return (NULL);
    map->map = NULL;
    return (map);
}

int			wolf3d_map_copy(t_wmap *map, char *buffer)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (buffer[i] != '\0')
    {
        if (buffer[i] == '\n')
        {
            if (!(map->map[j] = (char *)ft_memalloc(sizeof(char) * (k + 1))))
                return (-1);
            strncpy(map->map[j], buffer + (i - k), k);
            map->map[j][k] = '\0';
            k = -1;
            j++;
        }
        i++;
        k++;
    }
    return (1);
}

int			wolf3d_init_map(t_wmap *map, char *buffer)
{
    int		i;
    int		n;

    i = 0;
    n = 0;
    if (!buffer || buffer[0] == 0)
        return (-1);
    if (!map)
        return (-1);
    while (buffer[i] != '\0')
    {
        if (buffer[i] == '\n')
            n++;
        i++;
    }
    if (!(map->map = (char **)ft_memalloc(sizeof(char *) * (n + 1))))
        return (-1);
    map->map[n] = NULL;
    wolf3d_map_copy(map, buffer);
    return (1);
}

void		wolf3d_map_destroy(t_wmap *map)
{
    int		i;

    i = 0;
    while (map->map[i])
    {
        free(map->map[i]);
        map->map[i] = NULL;
        i++;
    }
    free(map->map[i]);
    map->map[i] = NULL;
    free(map->map);
    map->map = NULL;
    free(map);
    map = NULL;
}

static int			wolf3d_load_skybox(t_wolf *wolf)
{
    SDL_Surface		*skybox_bmp;


    skybox_bmp = SDL_LoadBMP("../img/skybox.bmp");
    if (skybox_bmp == NULL)
        return (-1);
    printf("Texture loaded.\n");
    wolf->skybox = SDL_CreateTextureFromSurface(wolf->renderer, skybox_bmp);
    SDL_FreeSurface(skybox_bmp);

    return (1);
}

int					wolf3d_load_map(t_wolf *wolf, char *path)
{
    char			buffer[1024];

    if (path == NULL || !path[0])
        return (-1);
    ft_bzero(buffer, 1024);
    if (wolf->map && wolf->map->map != NULL)
    {
        wolf3d_map_destroy(wolf->map);
        wolf->map = wolf3d_map_create();
    }
    if (readfile(path, buffer) == -1)
    {
        ft_putstr_fd("Unable to read maps. Programme going to quit.\n", 2);
        return (-1);
    }
    if (wolf3d_init_map(wolf->map, buffer) == -1)
    {
        ft_putstr_fd(
                "Unable to load maps into memory. Programme going to quit\n", 2);
    }
    ft_bzero(wolf->map->name, 1000);
    ft_strcat(wolf->map->name, path);
    return (1);
}

int					wolf3d_loader(t_wolf *wolf)
{
    if (wolf3d_load_map(wolf, "../maps/intro.m3d") == -1)
        return (-1);
    if (wolf3d_load_skybox(wolf) == -1)
        return (-1);
    return (1);
}

static int			wolf3d_check_name(t_wolf *wolf, char *buffer,
                                        struct dirent *dp)
{
    ft_strcat(buffer, dp->d_name);
    if (ft_strcmp(buffer, wolf->map->name) != 0)
    {
        if (wolf3d_load_map(wolf, buffer))
            return (1);
    }
    return (0);
}

int					wolf3d_next_map(t_wolf *wolf)
{
    DIR				*dirp;
    struct dirent	*dp;
    char			buffer[100];

    wolf->player.x = 3;
    wolf->player.y = 3;
    if ((dirp = opendir("../maps")) == NULL)
        return (-1);
    while ((dp = readdir(dirp)) != NULL)
    {
        ft_bzero(buffer, 100);
        ft_strcat(buffer, "../maps/");
        if (dp->d_name[0] != '.')
        {
            if (wolf3d_check_name(wolf, buffer, dp))
            {
                closedir(dirp);
                return (1);
            }
        }
    }
    closedir(dirp);
    free(dp);
    free(dirp);
    return (1);
}

void		wolf3d_destroy_graphics(t_wolf *wolf)
{
    SDL_DestroyTexture(wolf->skybox);
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


    sdl.map = wolf3d_map_create();

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

    return (sdl);
}

void    sdl_pixel(t_wolf *wolf, int x, int y, t_color_sdl color)
{
    unsigned char *pixels;
    int width;

    pixels = (unsigned char*)wolf->surf->pixels;
    width = wolf->surf->w;
    if (x < 0 && x >= wolf->surf->w)
        return ;
    if (y < 0 && y >= wolf->surf->h)
        return ;

    pixels[4 * (y * width + x) + 0] = color.b;  //0 = BLUE
    pixels[4 * (y * width + x) + 1] = color.g;  //1 = GREEN
    pixels[4 * (y * width + x) + 2] = color.r;  //2 = RED
    pixels[4 * (y * width + x) + 3] = 1;

}

void    update(t_wolf *wolf)
{
    SDL_Rect dstrect;

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = wolf->surf->w;
    dstrect.h = wolf->surf->h;

    SDL_Texture *text = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);
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

void clean_up(t_wolf *sdl)
{
    SDL_DestroyTexture(sdl->texture);
    SDL_DestroyWindow(sdl->pwindow);
    SDL_Quit();
}

void    init_params_wolf(t_wolf *wolf)
{
    wolf->raycaster.posx = 13;
    wolf->raycaster.posy = 12;
    wolf->raycaster.dirx = -1;
    wolf->raycaster.diry = 0;
    wolf->raycaster.planex = 0;
    wolf->raycaster.planey = 0.5;
    wolf->raycaster.time = 0;
    wolf->raycaster.oldtime = 0;
    wolf->raycaster.ms = 0.04;
    wolf->raycaster.rs = 0.03;
    wolf->raycaster.move_down = 0;
    wolf->raycaster.move_left = 0;
    wolf->raycaster.move_right = 0;
    wolf->raycaster.move_up = 0;
    wolf->raycaster.w_w = WINDW_W;
    wolf->raycaster.w_h = WINDW_H;
    wolf->quit = 1;

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

void    loop_hook(t_wolf *wolf)
{
    SDL_Event   ev;
    Uint8 *key;

    key = NULL;
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
    SDL_Surface *anime;



    sdl = init_sdl();
    sdl.quit = 0;

    init_params_wolf(&sdl);
    loop_hook(&sdl);
    wolf3d_destroy_graphics(&sdl);
    return 0;
}