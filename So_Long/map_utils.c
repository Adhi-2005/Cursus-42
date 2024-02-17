/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/17 14:34:09 by adshafee         ###   ########.fr       */
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
char	*create_array_for_map(char *str)
{
	int		fd;
	char	**array;
	char	*buffer;
	t_array	area;

	buffer = malloc(sizeof(char) * (area.length*area.breadth)+ area.breadth);
	fd = open(str, O_RDONLY);
	read(fd, buffer, (area.length * area.breadth));
	// printf("Length = %d\nBreadth = %d\n", area.length, area.breadth);
	array = ft_split(buffer);
	while (*array)
	{
		printf("%s\n", *array);
		array++;
	}
	return (*array);
}

int	dimention_check(char *str)
{
	char		*line;
	int			fd;
	t_array		area;
	static int	expected_length;

	area.breadth = 0;
	area.length = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("(ERROR) Unable to open the file...!");
	while ((line = get_next_line(fd)))
	{
		area.length = ft_strlen(line);
		if(area.breadth == 0)
			expected_length = area.length;
		else if (expected_length != (area.length))
		{
			ft_printf("(ERROR) Map not valid");
			return (free(line), close(fd), exit(1), 0);
		}
		area.breadth++;
		free(line);
	}
	// printf("Length = %d\nBreadth = %d\n", area.length, area.breadth);
	return (1);
}
