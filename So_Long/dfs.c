/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:49:00 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/02 17:07:03 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	dfs(t_array *game, size_t x, size_t y, bool visited[][game->length])
{
	if (x < 0 || x >= game->breadth || y < 0 || y >= game->length
		|| game->map[x][y] == '1' || visited[x][y])
		return (false);
	visited[x][y] = true;
	if (game->map[x][y] == 'E')
		game->exit_found = true;
	else if (game->map[x][y] == 'C')
		game->collectibles_found++;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
	return (true);
}

// bool	is_valid_path(t_array *game)
// {
// 	bool	**visited;

// 	visited = malloc(sizeof(bool *) * (game->breadth + game->length));
// 	ft_memset(visited, false, sizeof(visited));
// 	game->exit_found = false;
// 	game->collectibles_found = 0;
// 	dfs(game, game->player_x, game->player_y, visited);
// 	return (game->exit_found
// 		&& (game->collectibles_found == game->num_of_collectibles));
// }


bool is_valid_path(t_array *game) {
    bool visited[game->breadth][game->length]; // Declare visited array
    
    // Initialize visited array to false
    for (size_t i = 0; i < game->breadth; i++) {
        for (size_t j = 0; j < game->length; j++) {
            visited[i][j] = false;
        }
    }
    
    // Call dfs from the player's initial position
    return dfs(game, game->player_x, game->player_y, visited);
}

// bool is_valid_path(t_array *game)
// {
//     // Allocate memory for the 2D visited array
//     bool (*visited)[game->length] = malloc(sizeof(bool[game->breadth][game->length]));
    
//     // Check if memory allocation was successful
//     if (visited == NULL) {
//         // Handle memory allocation failure
//         return false;
//     }
    
//     // Initialize all elements of visited array to false
//     for (size_t i = 0; i < game->breadth; ++i) {
//         for (size_t j = 0; j < game->length; ++j) {
//             visited[i][j] = false;
//         }
//     }
    
//     game->exit_found = false;
//     game->collectibles_found = 0;
//     dfs(game, game->player_x, game->player_y, visited);
    
//     // Free the memory allocated for visited array
//     free(visited);
    
//     return (game->exit_found && (game->collectibles_found == game->num_of_collectibles));
// }