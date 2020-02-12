cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(4febgnl)
include_directories(libft)
include_directories(minilibx_macos)

add_executable(fdf
        draw.c
        fdf.c
        fdf.h
        main.c
        read_file.c draw2.c)

target_link_libraries(fdf
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a "-framework OpenGL" "-framework AppKit")