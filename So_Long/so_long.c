/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/04 20:41:16 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	images_init2(t_array *area)
{
	area->move_count = 0;
	area->player_position = 0;
	area->end_game = 0;
	area->img_width = 0;
	area->collect_n = 0;
	area->img_height = 0;
	area->pac_man_right = 0;
}

void	images_init(t_array *area)
{
	area->map = NULL;
	area->map_cpy = NULL;
	area->length = 0;
	area->breadth = 0;
	area->collectibles_got = 0;
	area->num_of_collectibles = 0;
	area->exit_found = 0;
	area->player_x = 0;
	area->player_y = 0;
	area->count = 0;
	area->is_valid_map = 0;
	area->mlx = NULL;
	area->win = NULL;
	area->img_background = NULL;
	area->img_wall = NULL;
	area->img_exit = NULL;
	area->img_collectible = NULL;
	area->img_player = NULL;
	images_init2(area);
}

static void	setup_game_objects(t_array *area)
{
	if (check_map_wall(area) == 0)
	{
		ft_printf("%s\n", "Border of the map is not valid.. ");
		return ;
	}
	if (!is_valid_path(area))
	{
		ft_printf("(ERROR) No valid Path....!!!");
		free(area->map);
		return ;
	}
	if (!check_other_object_conditions(area))
		return ;
	get_number_of_collectibles(area);
	area->breadth = area->breadth;
	area->length = area->length;
	main_window(area);
}

static void	parse_input_and_setup_game(char **av, t_array *area)
{
	int	i;

	i = 0;
	if (!check_file_extension(av[1]))
		return ;
	images_init(area);
	dimention_check(av[1], area);
	create_array_for_map(av[1], area);
	setup_game_objects(area);
	while (area->map[i])
	{
		free (area->map[i]);
		free (area->map_cpy);
		i++;
	}
	free(area->map);
	free(area->map_cpy);
}

int	main(int ac, char **av)
{
	t_array	area;

	if (ac != 2)
		return ((void)ft_printf("Input 2 arguments\n"), 0);
	parse_input_and_setup_game(av, &area);
	return (0);
}
