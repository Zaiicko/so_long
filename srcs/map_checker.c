/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/19 02:39:59 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_if_finishable(t_data *data)
{
	char	**map;

	map = tab_dup(data->map.map_data, data->map.height);
	if (!map)
		error_msg("Map copy failed");
	back_tracking(map, data->map.y_player, data->map.x_player);
	check_after_back(data, map);
	ft_free_tab(map);
}

void	check_wall(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < data->map.width)
	{
		if (data->map.map_data[0][x] != '1')
		{
			error_msg("The map need to be surrounded by walls");
		}
		else if (data->map.map_data[data->map.height - 1][x] != '1')
			error_msg("The map need to be surrounded by walls");
		x++;
	}
	while (y < data->map.height)
	{
		if (data->map.map_data[y][0] != '1')
			error_msg("The map need to be surrounded by walls");
		else if (data->map.map_data[y][data->map.width - 1] != '1')
			error_msg("The map need to be surrounded by walls");
		y++;
	}
}

void	check_if_valid_char(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		error_msg("Empty line in ber file");
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			error_msg("Wrong char in the ber file");
		i++;
	}
}

void	check_gameobjects(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->map.p_count = 0;
	data->map.e_count = 0;
	data->map.c_count = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.map_data[y][x])
		{
			if (data->map.map_data[y][x] == 'P')
			{
				data->map.p_count++;
				data->map.y_player = y;
				data->map.x_player = x;

			}
			else if (data->map.map_data[y][x] == 'E')
				data->map.e_count++;
			else if (data->map.map_data[y][x] == 'C')
				data->map.c_count++;
			x++;
		}
		y++;
	}
	if (data->map.p_count != 1 || data->map.e_count
		!= 1 || data->map.c_count < 1)
		error_msg("The map have not enough or too much gameobjects");
}

void	check_lines_width(t_data *data)
{
	int	width;
	int	i;
	int	tmp;

	i = 0;
	width = ft_strlen(data->map.map_data[0]);
	while (i < data->map.height)
	{
		tmp = ft_strlen(data->map.map_data[i]);
		if (tmp != width)
			error_msg("Lines width are not uniform");
		i++;
	}
	data->map.width = ft_strlen(data->map.map_data[0]);
}
