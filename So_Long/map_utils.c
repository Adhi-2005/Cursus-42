/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/12 17:00:18 by adshafee         ###   ########.fr       */
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
			ft_printf("Wrong file extention...!");
			return (0);
		}
		i--;
		j--;
	}
	return (1);
}
