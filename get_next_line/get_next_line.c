/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhil <adhil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:05:52 by adhil             #+#    #+#             */
/*   Updated: 2023/12/19 12:27:34 by adhil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_remaining(int fd, char *remaining)
{
	int		read_bytes;
	char	*buffer;	
	char	*temp;

	// if (!remaining)
	// {
	// 	remaining = malloc(sizeof(char));
	// 	remaining[0] = 0;
	// }
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(remaining, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			if(read_bytes == 0)
				return (remaining);
			free(temp);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = remaining;
		remaining = ft_strjoin(remaining, buffer);
		free(temp);
	}
	free(buffer);
	return (remaining);
}

char	*assign_to_return_line(char *remaining)
{
	int		i;
	char	*line;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return(NULL);
	i = 0;
	while (remaining[i] != '\n' && remaining[i])
	{
		line[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
	{
		line[i] = remaining[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_stuffs_from_remaining(char *remaining)
{
	int		i;
	int		j;
	char	*new_remaining;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (!remaining)
	{
		free(remaining);
		return (NULL);
	}
	new_remaining = (char *)malloc(sizeof(char) * ft_strlen(remaining) - i + 1);
	if (!new_remaining)
		return (NULL);
	i++;
	j = 0;
	while (remaining[i])
		new_remaining[j++] = remaining[i++];
	new_remaining[j] = '\0';
	free(remaining);
	return (new_remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*return_line;
 
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (0);
	remaining = read_to_remaining(fd, remaining);
	if (!remaining)
		return (NULL);
	return_line = assign_to_return_line(remaining);
	remaining = clear_stuffs_from_remaining(remaining);
	return (return_line);
}

#include <stdio.h>

int main(void)
{
    int fd = open("testfile.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("Line: %s\n", line);
	while ((line = get_next_line(fd)))
	{
		printf("line: %s", line);
		free(line);
	}
	close(fd);
}


// // There is some errors in this program and I have to analyze it before it going to be pushed
// // Mainly it is not reading the stuffs in the second call....

// //check for the protection conditions also....
// // Protections should be raised correctly.
// // check whether we need extra function to free the memory.