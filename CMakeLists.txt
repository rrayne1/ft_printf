cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 99)
include_directories(.)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
add_executable(ft_printf
				ft_printf.c
				libft/ft_strlen.c
				libft/ft_bzero.c
				libft/ft_isdigit.c
				libft/ft_atoi.c
				libft/ft_strcat.c
				libft/ft_strnew.c
				libft/ft_getlen.c
				libft/ft_strchr.c
				libft/ft_putstr.c
				libft/ft_putchar.c
				libft/ft_strrchr.c
				libft/libft.h ft_printf.h
				check.c
				types.c
				utils.c
				numbers.c floats.c)