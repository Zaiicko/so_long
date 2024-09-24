/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/24 04:40:55 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_if_finishable(t_data *data)
{
	char	**map;

	map = tab_dup(data->map.map_data, data->map.height);
	if (!map)
		error_msg_free_tab("Error\nMap copy failed\n", data->map.map_data);
	back_tracking(map, data->map.y_player, data->map.x_player);
	check_after_back(data, map);
	ft_free_tab(map);
}

void	check_wall(t_data *data)
{
	int		y;
	int		x;
	char	*error_msg;

	y = 0;
	x = 0;
	error_msg = "Error\nThe map meed to be surrounded by walls\n";
	while (x < data->map.width)
	{
		if (data->map.map_data[0][x] != '1')
			error_msg_free_tab(error_msg, data->map.map_data);
		else if (data->map.map_data[data->map.height - 1][x] != '1')
			error_msg_free_tab(error_msg, data->map.map_data);
		x++;
	}
	while (y < data->map.height)
	{
		if (data->map.map_data[y][0] != '1')
			error_msg_free_tab(error_msg, data->map.map_data);
		else if (data->map.map_data[y][data->map.width - 1] != '1')
			error_msg_free_tab(error_msg, data->map.map_data);
		y++;
	}
}

void	check_if_valid_char(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		error_msg("Error\nEmpty line in ber file\n");
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			error_msg("Error\nWrong char in the ber file\n");
		i++;
	}
}

void	check_gameobjects(t_data *data)
{
	int	y;

	y = 0;
	data->map.p_count = 0;
	data->map.e_count = 0;
	data->map.c_count = 0;
	while (y < data->map.height)
	{
		count_objects(data, y);
		y++;
	}
	if (data->map.p_count != 1 || data->map.e_count
		!= 1 || data->map.c_count < 1)
		error_msg_free_tab("Error\nWrong amount of gameobjects\n",
			data->map.map_data);
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
			error_msg_free_tab("Error\nLines width are not uniform\n",
				data->map.map_data);
		i++;
	}
	data->map.width = ft_strlen(data->map.map_data[0]);
}
