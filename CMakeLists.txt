cmake_minimum_required(VERSION 3.14)
project(fdf_new C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FRA)

include_directories(inc)
include_directories(libft)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(fdf_new
        inc/fdf.h
        src/main.c
        src/read_map.c
        src/draw.c
        src/loop.c
        src/edit_coordinates.c
        src/menu.c
        src/draw_full.c
        libft/get_next_line.c)

target_link_libraries(fdf_new /Users/smight/Desktop/fdf_new/libft/libft.a)
target_link_libraries(fdf_new /Users/smight/Desktop/fdf_new/libft/libftprintf.a)
target_link_libraries(fdf_new "libmlx.a")
target_link_libraries(fdf_new "-framework AppKit")
target_link_libraries(fdf_new "-framework OpenGL")
