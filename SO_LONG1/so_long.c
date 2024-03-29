/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/27 17:34:14 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "mlx/mlx.h"

void	images_init2(t_array **map)
{
	(*map)->move_count = 0;
	(*map)->player_position = 0;
	(*map)->end_game = 0;
	(*map)->img_width = 0;
	(*map)->collect_n = 0;
	(*map)->img_height = 0;
	(*map)->pac_man_right = 0;
}

void	images_init(t_array **map)
{
	(*map)->map = NULL;
	(*map)->length = 0;
	(*map)->breadth = 0;
	(*map)->collectibles_found = 0;
	(*map)->num_of_collectibles = 0;
	(*map)->exit_found = 0;
	(*map)->player_x = 0;
	(*map)->player_y = 0;
	(*map)->count = 0;
	(*map)->mlx = NULL;
	(*map)->win = NULL;
	(*map)->img_background = NULL;
	(*map)->img_wall = NULL;
	(*map)->img_exit = NULL;
	(*map)->img_collectible = NULL;
	(*map)->img_player = NULL;
	images_init2(map);
}

void	setup_game_objects(t_array *game_map, t_array *area)
{
	if (check_map_wall(game_map, *area) == 0)
	{
		ft_printf("%s\n", "Border of the map is not valid.. ");
		return ;
	}
	if (!check_other_object_conditions(game_map, *area))
		return ;
	get_number_of_collectibles(game_map, *area);
	game_map->breadth = area->breadth;
	game_map->length = area->length;
	main_window(game_map);
}

void	parse_input_and_setup_game(int ac, char **av)
{
	t_array	*game_map;
	t_array	*area;

	game_map = NULL;
	if (ac != 2)
	{
		ft_printf("Input 2 arguments\n");
		return ;
	}
	if (!check_file_extension(av[1]))
		return ;
	area = dimention_check(av[1]);
	game_map = create_array_for_map(av[1], area);
	setup_game_objects(game_map, area);
}

int	main(int ac, char **av)
{
	parse_input_and_setup_game(ac, av);
	return (0);
}
