cmake_minimum_required(VERSION 3.14)
project(wolf3d C)

set(CMAKE_C_STANARD 1)
set(FLAGS "-O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}")
set(libft_inc
        libft/)
link_directories(libft/)
find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIR} includes/${CMAKE_CURRENT_BINARY_DIR} includes/${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Test3 srcs/main.c srcs/sdl_init.c srcs/sdl_loop.c srcs/keyhook.c)
target_link_libraries(Test3 ${SDL_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -llibft)