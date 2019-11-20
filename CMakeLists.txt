cmake_minimum_required(VERSION 3.14)
project(FUCK C)

set(CMAKE_C_STANARD 1)
set(FLAGS "-O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}")
set(libft_inc
        libft/)
link_directories(libft/)
link_directories(libgm/)
find_package(SDL2 REQUIRED)
include_directories(SDL2/ includes/ libft/ libgm/include)

add_executable(FUCK main.c)
target_link_libraries(FUCK ${SDL_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -llibft)