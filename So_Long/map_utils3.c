/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:52:26 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/09 19:23:43 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_objects_conditions_check(t_array *map, t_array size)
{
	size_t	i = 0;

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
