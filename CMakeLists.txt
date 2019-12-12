cmake_minimum_required(VERSION 3.14)
project(wolf C)
set(CMAKE_C_STANDARD 11)
link_directories(
        SDL2/
        libft)
include_directories(
        SDL2/SDL2.framework/Headers
        includes
        libft)
add_executable(wolf
        src/drawer.c
        src/init.c
        src/keyhook.c
        src/keyhook_utils.c
        src/main.c
        src/raycast.c
        src/read_map.c
        src/fps.c
        src/validate.c
        src/fix_map.c
        src/run_map.c)
target_link_libraries(wolf
        "ft"
        "-F ${PROJECT_SOURCE_DIR}/SDL2 -framework SDL2"
        )