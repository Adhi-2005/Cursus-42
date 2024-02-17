/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/17 12:18:20 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!check_file_extention(av[1]))
			return (0);
		if (dimention_check(av[1]) == 1)
			create_array_for_map(av[1]);
	}
	else
	{
		ft_printf("Input 2 arguments\n");
		return (0);
	}
}
