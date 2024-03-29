/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:52:26 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/27 05:24:18 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall(t_array *map, t_array size)
{
	size_t	i;

	i = 0;
	while (i < size.length)
	{
		if (map->map[0][i] != '1' || map->map[size.breadth - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < size.breadth)
	{
		if (map->map[i][0] != '1' || map->map[i][size.length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	objects_check_with_numbers(int player, int collectibles, int exit)
{
	if (player != 1 || collectibles < 1 || exit != 1)
	{
		perror("(ERROR) Input the objects correctly....!");
		return (0);
	}
	return (1);
}

int	check_other_object_conditions(t_array *map_array, t_array size)
{
	static int	player;
	static int	collectibles;
	static int	exit;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size.breadth)
	{
		j = 0;
		while (j < size.length)
		{
			if (map_array->map[i][j] == 'P')
				player++;
			else if (map_array->map[i][j] == 'C')
				collectibles++;
			else if (map_array->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (objects_check_with_numbers(player, collectibles, exit) == 0)
		return (0);
	return (1);
}

void	get_player_position(t_array *game)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < game->breadth)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

// void	get_number_of_collectibles(t_array *map_array, t_array dimensions)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	collectible;

// 	collectible = 0;
// 	j = 0;
// 	i = 0;
// 	while (i < dimensions.breadth)
// 	{
// 		j = 0;
// 		while (j < dimensions.length)
// 		{
// 			if (map_array->map[i][j] == 'C')
// 				collectible++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	map_array->num_of_collectibles = collectible;
// }
