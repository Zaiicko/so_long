/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/18 00:24:35 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*void	check_wall(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;

}*/

void	check_if_valid_char(t_data *data)
{
	size_t y;
	size_t x;
	
	y = 0;
	while (y < (size_t)data->map.height)
	{
		x = 0;
		while (x < (size_t)data->map.width)
		{
			if (!ft_strchr(VALID_CHARS, data->map.map_data[y][x]) || ft_strlen(data->map.map_data[y]) == 0)
				error_msg("The map have wrong char in it");
			x++;
		}
		y++;
	}
}


void	check_map(t_data *data)
{
	check_if_valid_char(data);
}
