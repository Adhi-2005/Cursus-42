/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:59 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/03 18:24:44 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(const char *s)
{
	size_t	i;
	size_t	len;
	char	**spl_str;

	if (!s)
		return (0);
	spl_str = malloc(sizeof(char *) * (word_count(s, '\n') + 1));
	if (!spl_str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != '\n')
		{
			len = 0;
			while (*s && *s != '\n' && ++len)
				s++;
			spl_str[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	spl_str[i] = NULL;
	return (spl_str);
}

t_array	dimention_check(char *str)
{
	t_array		area;
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
