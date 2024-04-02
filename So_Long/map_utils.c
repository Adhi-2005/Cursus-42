/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/02 17:14:58 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("(ERROR) Invalid characters in Map....!");
		return (0);
	}
	return (1);
}

int	check_for_game_objects(t_array *map_array, t_array size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
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

t_array	*create_array_for_map(char *str, t_array *area)
{
	char	*buffer;
	int		fd;
	size_t	field;
	size_t	read_bytes;
	t_array	*map_array;

	map_array = malloc(sizeof(t_array) * 1024);
	images_init(&map_array);
	buffer = malloc((area->length * area->breadth) + area->breadth);
	fd = open(str, O_RDONLY);
	field = (area->length * area->breadth) + area->breadth;
	read_bytes = read(fd, buffer, field);
	buffer[read_bytes] = '\0';
	map_array->map = ft_split(buffer);
	free(buffer);
	return (map_array);
}

void	display_error(char *line, int fd)
{
	ft_printf("(ERROR) Map not valid");
	free(line);
	close(fd);
	exit(1);
}

t_array	*dimention_check(char *str)
{
	t_array				*area;
	char				*line;
	int					fd;
	size_t				expected_length;

	area = malloc(sizeof(t_array));
	area->length = 0;
	area->breadth = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("(ERROR) Unable to open the file...!");
	line = get_next_line(fd);
	while (line)
	{
		area->length = ft_strlen(line);
		if (area->breadth == 0)
			expected_length = area->length;
		else if (expected_length != area->length)
			display_error(line, fd);
		area->breadth++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (area);
}
