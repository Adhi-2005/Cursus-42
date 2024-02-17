/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:59 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/17 13:11:18 by adshafee         ###   ########.fr       */
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
