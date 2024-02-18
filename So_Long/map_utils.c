/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/18 17:45:06 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_file_extention(char *str)
{
	char	*main_extention;
	int		i;
	int		j;

	i = 0;
	j = 4;
	main_extention = ".ber";
	while (str[i])
		i++;
	i--;
	j--;
	while (j >= 0)
	{
		if (str[i] != main_extention[j])
		{
			ft_printf("ERROR : Wrong file extention...!");
			return (0);
		}
		i--;
		j--;
	}
	return (1);
}

int	is_valid_game_object(char obj, char game_objects[])
{
	int	k;

	k = 0;
	while (k < 5)
	{
		if (obj == game_objects[k])
			return (1);
		k++;
	}
	return (0);
}

char	*assign_game_objects(void)
{
	char	*game_objects;

	game_objects = malloc(5 * sizeof(char));
	if (game_objects == NULL)
		return (NULL);
	game_objects[0] = 'P';
	game_objects[1] = 'C';
	game_objects[2] = 'E';
	game_objects[3] = '1';
	game_objects[4] = '0';
	return (game_objects);
}

bool	check_for_game_objects(char	**str)
{
	char	*game_objects;
	int		i;
	int		j;
	int		valid;

	game_objects = assign_game_objects();
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			valid = is_valid_game_object(str[i][j], game_objects);
			if (!valid)
			{
				ft_printf("(ERROR) Map not valid. ");
				ft_printf("Input the required objects in the map.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**create_array_for_map(char *str)
{
	char	**array;
	char	*buffer;
	t_array	area;

	buffer = malloc(sizeof(char) * (area.length * area.breadth) + area.breadth);
	area.fd = open(str, O_RDONLY);
	read(area.fd, buffer, (area.length * area.breadth));
	array = ft_split(buffer);
	// while (*array)
	// {
	// 	printf("%s\n", *array);
	// 	array++;
	// }
	return (array);
}
