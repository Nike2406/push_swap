cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(./libft)
add_executable(push_swap src/push_swap.c push_swap.h)
target_link_libraries(push_swap libft)