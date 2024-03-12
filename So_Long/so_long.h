 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:04 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/21 02:23:24 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libftprintf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

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
	bool	exit_found;
	bool	collectibles_found;
	int		player_y;
	int		player_x;
	int		num_of_collectibles;
	
}	t_array;

// map_utils.c

int					check_file_extention(char *str);
t_array				dimention_check(char *str);
t_array				*create_array_for_map(char *str, t_array area);
// bool				check_for_game_objects(t_array *str);
int					check_for_game_objects(t_array *map_array, t_array size);

// map_utils2.c

size_t	word_count(const char *s, char c);
char	**ft_split(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);

// map_utils3.c

int	check_map_wall(t_array *map, t_array size);
int	check_other_object_conditions(t_array *map_array, t_array size);

// dfs.c
bool	dfs(t_array *game, size_t x, size_t y, bool visited[][game->length]);
void	*ft_memset(void *b, int c, size_t len);
bool	is_valid_path(t_array *game);

#endif