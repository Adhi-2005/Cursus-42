/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:04 by adshafee          #+#    #+#             */
/*   Updated: 2024/02/13 19:49:46 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libftprintf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		check_file_extention(char *str);
void	dimention_check(char *str);

#endif