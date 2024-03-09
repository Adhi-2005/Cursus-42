/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/09 19:21:32 by adshafee         ###   ########.fr       */
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
			if (game_objects_conditions_check(map, area) == 0)
			{
				ft_printf("%s\n", "Border of the map is not valid.. please check and correct it..");
				return (0);
			}
		}
	}
	else
	{
		ft_printf("Input 2 arguments\n");
		return (0);
	}
}
