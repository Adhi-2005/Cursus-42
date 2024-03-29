/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:04 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/27 17:33:57 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libftprintf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct b_list
{
	size_t	length;
	size_t	breadth;
	char	**map;
	int		player_y;
	int		player_x;
	bool	exit_found;
	bool	collectibles_found;
	int		num_of_collectibles;
	int		count;
	int		collect_n;
	void	*mlx;
	void	*win;
	int		player_position;
	char	*img_background;
	char	*img_wall;
	char	*img_exit;
	char	*img_collectible;
	char	*img_player;
	int		move_count;
	int		end_game;
	int		img_width;
	int		img_height;
	char	**dup_map;
	char	*pac_man_right;
	char	*pac_man_left;
	char	*pac_man_down;
	char	*pac_man_up;
	char	*collectibles;
	char	*wall;
}	t_array;

void	images_init(t_array **map);
void	parse_input_and_setup_game(int ac, char **av);

// map_utils.c

t_array	*dimention_check(char *str);
t_array	*create_array_for_map(char *str, t_array *area);
int		check_for_game_objects(t_array *map_array, t_array size);

// map_utils2.c

size_t	word_count(const char *s, char c);
char	**ft_split(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);

// map_utils3.c

int		check_map_wall(t_array *map, t_array size);
int		check_other_object_conditions(t_array *map_array, t_array size);
int		check_other_object_conditions(t_array *map_array, t_array size);
// void	get_player_position(t_array *game, char character);

// dfs.c

bool	dfs(t_array *game, size_t x, size_t y, bool visited[][game->length]);

// display_contents.c

void	main_window(t_array *game);
int		img_put(t_array *game);
void	load_images(t_array *game_map);

// display_contents.c

void	load_pac_man_images(t_array *game_map);
void	load_other_images(t_array *game_map);

// controls.c

int		game_hook(int keycode, t_array *game);
void	ft_move_player(t_array *game, size_t a, size_t b);
void	get_number_of_collectibles(t_array *map_array, t_array dimensions);
int		finish(t_array *game);

// external_utils.c

int		check_file_extension(char *str);

#endif