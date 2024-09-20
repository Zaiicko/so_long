/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:00:58 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/20 04:14:04 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	extract_ber_data(t_data *data, char *name)
{
	int		fd;
	int		i;
	char	*line;

	data->map.map_data = (char **)malloc(sizeof(char *)
			* (data->map.height + 1));
	if (!data->map.map_data)
		error_msg("Malloc failed");
	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open the map file");
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		check_if_valid_char(line);
		data->map.map_data[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map.map_data[i] = NULL;
	close(fd);
}

void	render_floor(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT_MACB_SCREEN)
	{
		x = 0;
		while (x < WIDTH_MACB_SCREEN)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.ground, x, y);
			x += data->sprites.width;
		}
		y += data->sprites.height;
	}
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map_data[y])
	{
		x = 0;
		while (data->map.map_data[y][x])
		{
			if (data->map.map_data[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (data->map.map_data[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (data->map.map_data[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.collec, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->sprites.player_current,
		data->map.x_player * TILE_SIZE, data->map.y_player * TILE_SIZE);
}

void	loading_map(t_data *data, char *name)
{
	count_lines(data, name);
	extract_ber_data(data, name);
	check_lines_width(data);
	check_gameobjects(data);
	check_wall(data);
	check_if_finishable(data);
	check_screen_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_width,
			data->screen_height, "Nibiru");
	if (!data->win_ptr)
		error_msg("Can't create the window with mlx");
	render_floor(data);
	render_map(data);
}
