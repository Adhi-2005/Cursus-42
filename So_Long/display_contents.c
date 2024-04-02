/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:50:40 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/31 21:35:08 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_array *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, game->img_width * j,
			game->img_height * i);
	if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			game->img_width * j, game->img_height * i);
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectibles, game->img_width * j,
			game->img_height * i);
	else if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		mlx_put_image_to_window(game->mlx, game->win, game->pac_man_left,
			game->img_width * j, game->img_height * i);
	}
}

int	img_put(t_array *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_background, game->img_width * j,
				game->img_height * i);
			put_image_to_window(game, i, j);
		}
		i++;
	}
	return (0);
}

// void	load_images(t_array *game_map)
// {
// 	game_map->img_width = 128;
// 	game_map->img_height = 128;
// 	// load_pac_man_images(game_map);
// 	load_other_images(game_map);
// 	img_put(game_map);
// 	game_map->player_y = 0;
// 	game_map->player_x = 0;
// 	if (game_map->wall == NULL)
// 	{
// 		ft_printf("Error: Could not load wall image\n");
// 		exit(0);
// 	}
// }

void	load_images(t_array *game_map)
{
	game_map->img_width = 128;
	game_map->img_height = 128;
	game_map->pac_man_left = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan(left)_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->collectibles = mlx_xpm_file_to_image(game_map->mlx,
			"images/collectible_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->wall = mlx_xpm_file_to_image(game_map->mlx,
			"images/Wall_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->img_background = mlx_xpm_file_to_image(game_map->mlx,
			"images/Background_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->img_exit = mlx_xpm_file_to_image(game_map->mlx,
			"images/exit_image.xpm", &game_map->img_width,
			&game_map->img_height);
	img_put(game_map);
	game_map->player_y = 0;
	game_map->player_x = 0;
	if (game_map->wall == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
}

void	main_window(t_array *game_map)
{
	game_map->mlx = mlx_init();
	game_map->win = mlx_new_window(game_map->mlx, game_map->length * 128,
			game_map->breadth * 128, "PAC MAN verson:Infinity");
	load_images(game_map);
	mlx_hook(game_map->win, 2, 1L << 0, game_hook, game_map);
	mlx_hook(game_map->win, 17, 1L << 0, finish, &game_map);
	mlx_loop(game_map->mlx);
	return ;
}
