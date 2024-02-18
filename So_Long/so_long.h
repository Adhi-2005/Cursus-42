/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:04 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/18 17:18:11 by adshafee         ###   ########.fr       */
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

typedef struct s_list
{
	int	length;
	int	breadth;
	int	fd;
}	t_array;

// typedef struct u_list
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		valid;
// 	char	current_char;
// } t_check_for_game_objects;

// map_utils.c

int		check_file_extention(char *str);
int		dimention_check(char *str);
char	**create_array_for_map(char *str);
bool	check_for_game_objects(char	**str);

// map_utils2.c

size_t	word_count(const char *s, char c);
char	**ft_split(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif