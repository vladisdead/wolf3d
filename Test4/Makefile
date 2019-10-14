# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 16:25:58 by cmicha            #+#    #+#              #
#    Updated: 2019/10/14 10:49:47 by cmicha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

# src / obj files
SRC		= main.c \
		  sdl_init.c \
		  init.c \
		  map_init.c \
		  bresenham.c \
		  color.c \
		  reader.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror

# sdl2 library
SDL		= ./SDL2/
SDL2_LIB	= $(SDL)/lib
SDL2_INC	= -I ./SDL2
SDL2_LNK	= -L ./SDL2/lib -l SDL2-2.0.0

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(SDL2_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) -g $(SDL2_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(SDL2_LIB):
	make -C $(SDL)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SDL2_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all