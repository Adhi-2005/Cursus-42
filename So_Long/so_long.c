/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/11 23:30:41 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	int	hey;
	if (ac == 2)
	{
		if (check_file_extention(av[1]))
		{
			t_array area = dimention_check(av[1]);
			t_array *map = create_array_for_map(av[1], area);
			// (void)map;
			// t_array *map_array = &map;
			// while (*map_array)
			// {
			// 	ft_printf("%s\n", *map_array);
			// 	map_array++;
			// }	
			hey = check_for_game_objects(map, area);
			if (check_map_wall(map, area) == 0)
			{
				ft_printf("%s\n", "Border of the map is not valid.. please check and correct it..");
				return (0);
			}
			hey = check_other_object_conditions(map, area);
			is_valid_path(map);
		}
	}
	else
	{
		ft_printf("Input 2 arguments\n");
		return (0);
	}
}
