/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/09 19:12:50 by adshafee         ###   ########.fr       */
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

int is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("Error: Invalid character in map\n");
		return 0;
	}
	return 1;
}

int check_for_game_objects(t_array *map_array, t_array size)
{
	size_t i = 0;
	size_t j = 0;
	while (i < size.breadth)
	{
		j = 0;
		while (j < size.length)
		{
			if (!is_valid_character(map_array->map[i][j]))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

t_array	*create_array_for_map(char *str, t_array area)
{
	char	*buffer;
	int	fd;
	size_t	read_bytes;

	t_array *map_array = malloc(sizeof(t_array)* 1024);
	buffer = malloc(sizeof(char) * (area.length * area.breadth) + area.breadth);
	fd = open(str, O_RDONLY);
	read_bytes = read(fd, buffer, (area.length * area.breadth) + area.breadth);
	buffer[read_bytes] = '\0';
	map_array->map = ft_split(buffer);
	char **tmp = map_array->map;
	printf("%s\n", "The below map is printed from the function 'creat_array_for_map'.....");
	while (*tmp)
	{
		printf("%s\n", *tmp);
		tmp++;
	}
	return (map_array);
}
