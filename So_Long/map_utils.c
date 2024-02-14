/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/14 14:57:39 by adshafee         ###   ########.fr       */
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

void	dimention_check(char *str)
{
	int length = 0;
	int breadth = 0;
	char	*line;
	int		fd;
	int		line_size;
	int		expected_length = 0;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR : Unable to open the file...!");
	}
	while ((line = get_next_line(fd)))
	{
		line_size = ft_strlen(line);
		if(breadth == 0)
			expected_length = line_size;
		else if (expected_length != (line_size))
		{
			ft_printf("ERROR : map not valid");
			free(line);
			close(fd);
			exit(1);
		}
		if(line_size > length)
			length = line_size;
		breadth++;
		free(line);
	}
}
