# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:18:44 by adshafee          #+#    #+#              #
#    Updated: 2024/02/12 14:45:40 by adshafee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
FT_PRINTF = ./libftprintf/libftprintf.a
RM = rm -rf
SRC = so_long.c map_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libftprintf/
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libftprintf/
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libftprintf/
	$(RM) $(NAME)

re: fclean all
