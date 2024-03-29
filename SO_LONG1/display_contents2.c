/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contents2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 05:13:59 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/27 05:16:25 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_pac_man_images(t_array *game_map)
{
	game_map->pac_man_right = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan(right)_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->pac_man_left = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan(left)_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->pac_man_up = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan_up_image.xpm",
			&game_map->img_width, &game_map->img_height);
	game_map->pac_man_down = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan_down_image.xpm",
			&game_map->img_width, &game_map->img_height);
}

void	load_other_images(t_array *game_map)
{
	game_map->collectibles = mlx_xpm_file_to_image(game_map->mlx,
			"images/collectible_image.xpm",
			&game_map->img_width, &game_map->img_height);
	game_map->wall = mlx_xpm_file_to_image(game_map->mlx,
			"images/Wall_image.xpm",
			&game_map->img_width, &game_map->img_height);
	game_map->img_background = mlx_xpm_file_to_image(game_map->mlx,
			"images/Background_image.xpm",
			&game_map->img_width, &game_map->img_height);
	game_map->img_exit = mlx_xpm_file_to_image(game_map->mlx,
			"images/exit_image.xpm",
			&game_map->img_width, &game_map->img_height);
}
