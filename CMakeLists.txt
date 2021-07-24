cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(./libft)
add_executable(push_swap src/push_swap.c push_swap.h
        src/lst_functions.c
        src/movements1.c
        src/movements2.c
        src/movements3.c
        src/utils.c
        src/compares.c
        )
target_link_libraries(push_swap libft)