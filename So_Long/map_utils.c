/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/18 15:44:06 by adshafee         ###   ########.fr       */
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

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("Error: Invalid character in map\n");
		return (0);
	}
	return (1);
}

int	check_for_game_objects(t_array *map_array, t_array size)
{
	size_t	i = 0;
	size_t	j = 0;
	while (i < size.breadth)
	{
		j = 0;
		while (j < size.length)
		{
			if (!is_valid_character(map_array->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_array	*create_array_for_map(char *str, t_array area)
{
	char	*buffer;
	int		fd;
	size_t	read_bytes;

	t_array *map_array = malloc(sizeof(t_array)* 1024);
	images_init(&map_array);
	buffer = malloc(sizeof(char) * (area.length * area.breadth) + area.breadth);
	fd = open(str, O_RDONLY);
	read_bytes = read(fd, buffer, (area.length * area.breadth) + area.breadth);
	buffer[read_bytes] = '\0';
	map_array->map = ft_split(buffer);
	//char **tmp = map_array->map;
	//printf("%s\n", "The below map is printed from the function 'creat_array_for_map'.....");
	// while (*tmp)
	// {
	// 	printf("%s\n", *tmp);
	// 	tmp++;
	// }
	return (map_array);
}

t_array	dimention_check(char *str)
{
	t_array				area;
	char				*line;
	int					fd;
	size_t				expected_length;

	area.length = 0;
	area.breadth = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("(ERROR) Unable to open the file...!");
	while ((line = get_next_line(fd)))
	{
		area.length = ft_strlen(line);
		if (area.breadth == 0)
			expected_length = area.length;
		else if (expected_length != area.length)
		{
			ft_printf("(ERROR) Map not valid");
			free(line);
			close(fd);
			exit(1);
		}
		area.breadth++;
		free(line);
	}
	ft_printf("Length = %d\nBreadth = %d\n", area.length, area.breadth);
	close(fd);
	return (area);
}
