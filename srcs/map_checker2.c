/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:49:17 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/24 04:41:49 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	back_tracking(char **map, int y, int x)
{
	map[y][x] = 'G';
	if (map[y + 1][x] != 'G' && map[y + 1][x] != '1')
		back_tracking(map, y + 1, x);
	if (map[y - 1][x] != 'G' && map[y - 1][x] != '1')
		back_tracking(map, y - 1, x);
	if (map[y][x + 1] != 'G' && map[y][x + 1] != '1')
		back_tracking(map, y, x + 1);
	if (map[y][x - 1] != 'G' && map[y][x - 1] != '1')
		back_tracking(map, y, x - 1);
}

void	check_after_back(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				error_msg("Error\nFinish the game is impossible\n");
			x++;
		}
		y++;
	}
}

void	count_objects(t_data *data, int y)
{
	int	x;

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
}

void	check_screen_size(t_data *data)
{
	data->screen_height = data->map.height * TILE_SIZE;
	data->screen_width = data->map.width * TILE_SIZE;
	if ((data->screen_height > HEIGHT_MACB_SCREEN)
		|| (data->screen_width > WIDTH_MACB_SCREEN))
		error_msg_free_tab("Error\nThe map are too huge for the screen size\n",
			data->map.map_data);
}

void	count_lines(t_data *data, char *name)
{
	int			fd;
	int			i;
	char		*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Error\nCan't open the map file\n");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0])
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.height = i;
}
