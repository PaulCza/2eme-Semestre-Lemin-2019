##
## EPITECH PROJECT, 2020
## lem-in
## File description:
## makefile
##

NAME	=	lem_in

SRC	=	src/main.c			\
		src/read_file.c			\
		src/first_display.c		\
		src/check_cmd.c			\
		src/check_nbr.c			\
		src/check_other_lines.c		\
		src/check_tunnel.c		\
		src/del_com.c			\
		src/found_pos_tunnel.c		\
		src/multi_cmp.c			\
		src/atoi_parsing.c		\
		src/check_tunnel_negative.c	\
		src/check_tunnel_rooms.c	\
		$(wildcard util/*.c)

OBJ	=	$(SRC:.c=.o)

CC	?=	gcc

CFLAGS	=	-Wextra -Wall

CPPFLAGS=	-I./include/

name	:	all

all	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

debug	:	CFLAGS += -g
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	name all debug clean fclean re
