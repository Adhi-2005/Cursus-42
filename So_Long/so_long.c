/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/18 17:46:00 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	char	**map_array;

	if (ac == 2)
	{
		if (!check_file_extention(av[1]))
			return (0);
		if (dimention_check(av[1]) == 1)
		{
			map_array = create_array_for_map(av[1]);
			// while (*map_array)
			// {
			// 	ft_printf("%s\n", *map_array);
			// 	map_array++;
			// }
			check_for_game_objects(map_array);
		}
	}
	else
	{
		ft_printf("Input 2 arguments\n");
		return (0);
	}
}
