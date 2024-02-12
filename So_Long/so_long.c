/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/12 15:53:34 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if (!check_file_extention(av[1]))
			return (0);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Unable to read the map file. please check the map file!");
			return (0);
		}
	}
	else
	{
		ft_printf("Input 2 arguments\n");
		return (0);
	}
}
