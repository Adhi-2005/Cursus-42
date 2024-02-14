# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:18:44 by adshafee          #+#    #+#              #
#    Updated: 2024/02/13 19:55:56 by adshafee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
FT_PRINTF = ./libftprintf/libftprintf
GNL = ./get_next_line/get_next_line
RM = rm -rf
SRC = so_long.c map_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libftprintf/
	@make -C ./get_next_line/
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(GNL) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libftprintf/
	@make clean -C ./get_next_line/
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libftprintf/
	@make fclean -C ./get_next_line/
	$(RM) $(NAME)

re: fclean all