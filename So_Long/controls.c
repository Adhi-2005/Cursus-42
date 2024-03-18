/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:32:13 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/19 00:20:45 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_array *game, size_t a, size_t b)
{
	if (game->map[game->player_y + a][game->player_x + b] == 'E'
		&& game->num_of_collectibles == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->move_count++;
		ft_printf("YOU WON !!!\n");
		finish(game);
	}
	else if (game->map[game->player_y + a][game->player_x + b] == 'E'
		&& game->num_of_collectibles != 0)
		ft_printf("You need to collect all the collectibles before you exit\n");
	else if (game->map[game->player_y + a][game->player_x + b] == '1')
		ft_printf("You can't move into a wall\n");
	else if (game->map[game->player_y + a][game->player_x + b] == '0'
		|| game->map[game->player_y + a][game->player_x + b] == 'C')
	{
		if (game->map[game->player_y + a][game->player_x + b] == 'C')
			game->num_of_collectibles--;
		game->map[game->player_y + a][game->player_x + b] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_count++;
		ft_printf("Move count: %d\n", game->move_count);
		game->player_y += a;
		game->player_x += b;
	}
}

int	game_hook(int keycode, t_array *game)
{
	if (keycode == 13 || keycode == 126)
	{
		ft_move_player(game, -1, 0);
	}
	else if (keycode == 1 || keycode == 125)
	{
		ft_move_player(game, 1, 0);
	}
	else if (keycode == 0 || keycode == 123)
	{
		game->player_position = 1;
		ft_move_player(game, 0, -1);
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->player_position = 0;
		ft_move_player(game, 0, 1);
	}
	if (keycode == 53)
	{
		printf("Bye\n");
		finish(game);
	}
	img_put(game);
	return (0);
}

void	get_number_of_collectibles(t_array *map_array, t_array dimensions)
{
	size_t	i;
	size_t	j;
	size_t	collectible;

	collectible = 0;
	j = 0;
	i = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (map_array->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	map_array->num_of_collectibles = collectible;
}

int	finish(t_array *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	ft_printf("Bye\n");
	exit(0);
}
