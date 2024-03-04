/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:52:26 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/03 18:25:15 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	game_objects_conditions_check(t_array map)
// {
// 	char	**temp = map.map;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (temp[i])
// 	{
// 		j = 0;
// 		while (temp[i][j])
// 		{
			
// 		}
// 	}
// 	return(1);
// }

// int game_objects_conditions_check(t_array map, t_measurements size)
// {
//     char **temp = map.map;
//     int i, j;

// 	int	length = size.length;
// 	int	breadth = size.breadth;
//     // Check the top and bottom boundaries
//     j = breadth - 1;
//     while (j < breadth) {
//         if (temp[0][j] != '1' || temp[length - 1][j] != '1') {
//             return 0;  // Return 0 if any condition fails
//         }
//         j++;
//     }

//     // Check the left and right boundaries
//     i = 0;
//     while (i < length) {
//         if (temp[i][0] != '1' || temp[i][breadth - 1] != '1') {
//             return 0;  // Return 0 if any condition fails
//         }
//         i++;
//     }

//     // If all conditions are met, return 1
//     return 1; 
// }



// int game_objects_conditions_check(t_array map, t_measurements size)
// {
// 	char	**temp = map.map;
// 	int	i; 
// 	int	j;
// 	int	length = size.length;
// 	int breadth = size.breadth;

// 	j = 0;
// 	while (breadth >= j)
// 	{
// 		if (temp[0][j] != '1')
// 		{
// 			printf("%s\n", "Give a valid map...!");
// 			printf("%s\n", "Give valid boundaries...!");
// 			return 0;
// 		}
// 		if (temp[breadth][j] != '1')
// 		{
// 			printf("%s\n", "Give a valid map...!");
// 			printf("%s\n", "Give valid boundaries...!");
// 			return (0);
// 		}
// 		j++;;
// 	}
// 	i = 0;
// 	while (i <= length) 
// 	{
// 		if (temp[i][0] != '1' || temp[i][breadth] != '1')
// 		{
// 			printf("%s\n", "Give a valid map...!");
// 			printf("%s\n", "Give valid boundaries...!");
// 			return 0;
// 		}
// 		i++;
// 	}
// 	return 1;
// }


// int game_objects_conditions_check(t_array map, t_measurements size)
// {
//     char **temp = map.map;
//     int i, j;
//     int length = size.length;
//     int breadth = size.breadth;

//     j = 0;
//     while (j < breadth)
//     {
//         if (temp[0][j] != '1')
//         {
//             printf("%s\n", "Give a valid map...!");
//             printf("%s\n", "Give valid boundaries...!");
//             return 0;
//         }
//         if (temp[length - 1][j] != '1')  // Fix: Use length - 1 here
//         {
//             printf("%s\n", "Give a valid map...!");
//             printf("%s\n", "Give valid boundaries...!");
//             return 0;
//         }
//         j++;
//     }

//     i = 0;
//     while (i < length)
//     {
//         if (temp[i][0] != '1' || temp[i][breadth - 1] != '1')  // Fix: Use breadth - 1 here
//         {
//             printf("%s\n", "Give a valid map...!");
//             printf("%s\n", "Give valid boundaries...!");
//             return 0;
//         }
//         i++;
//     } `		

//     return 1;
// }

// int	game_objects_conditions_check(t_array map, t_measurements size)
// {
//     char **temp = map.map;
//     int i, j;
//     int length = size.length;
//     int breadth = size.breadth;

//     // Check the top and bottom boundaries
//     j = 0;
//     while (j < breadth)
//     {
//         if (temp[0][j] != '1' || temp[length - 1][j] != '1')
//         {
//             printf("Give a valid map...!\n");
//             printf("Give valid boundaries...!\n");
//             return 0;
//         }
//         j++;
//     }

//     // Check the left and right boundaries
//     i = 0;
//     while (i < length)
//     {
//         if (temp[i][0] != '1' || temp[i][breadth - 1] != '1')
//         {
//             printf("Give a valid map...!\n");
//             printf("Give valid boundaries...!\n");
//             return 0;
//         }
//         i++;
//     }

//     return 1;
// }


int	game_objects_conditions_check(t_array *map, t_array size)
{
	size_t	i = 0;

	while (i < size.length)
	{
		if (map->map[i][0] != '1' || map->map[i][size.breadth - 1] != '1')
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

// int is_valid_map_wall(t_game *map_array, t_game dimensions)
// {
// 	size_t i = 0;

// 	while (i < dimensions.length)
// 	{
// 		if(map_array->map_array[0][i] != '1' || map_array->map_array[dimensions.breadth - 1][i] != '1')
// 			return 0;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < dimensions.breadth)
// 	{
// 		if(map_array->map_array[i][0] != '1' || map_array->map_array[i][dimensions.length - 1] != '1')
// 			return 0;
// 		i++;
// 	}
// 	return 1;
// }