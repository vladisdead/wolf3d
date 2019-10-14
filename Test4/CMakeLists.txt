cmake_minimum_required(VERSION 3.13)

project(wolf3d C)

set(CMAKE_C_STANDARD 11)
set(MY_CFLAGS "-O2")
set (libft_inc libft/)
set (SDL_inc SDL2/)

include_directories("includes")
include_directories("libft")
include_directories("SDL2")

link_directories(libft/ SDL2/lib/)

add_executable(wolf3d srcs/bresenham.c srcs/main.c srcs/reader.c srcs/sdl_init.c srcs/map_init.c srcs/color.c srcs/init)

target_link_libraries(wolf3d "SDL2" "ft")