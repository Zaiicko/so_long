/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:48:22 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/26 15:52:49 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	good_player_sprite(t_data *data, int y, int x)
{
	if (y > data->map.y_player)
	{
		if (data->sprites.player_current == data->sprites.player_left)
			data->sprites.player_current = data->sprites.player_left;
		else
			data->sprites.player_current = data->sprites.player_right;
	}
	if (y < data->map.y_player)
		data->sprites.player_current = data->sprites.player_back;
	if (x > data->map.x_player)
		data->sprites.player_current = data->sprites.player_right;
	if (x < data->map.x_player)
		data->sprites.player_current = data->sprites.player_left;
}

void	moves(t_data *data, int y, int x)
{
	good_player_sprite(data, y, x);
	if (data->map.map_data[y][x] != '1')
	{
		ft_printf("Your number of movements : %d\n", data->move_count);
		data->map.y_player = y;
		data->map.x_player = x;
		if (data->map.map_data[y][x] == 'C')
		{
			data->map.map_data[y][x] = '0';
			data->map.c_count--;
		}
		render_floor(data);
		render_map(data);
		if (data->map.c_count == 0 && data->map.map_data[y][x] == 'E')
		{
			cleanup(data);
			ft_printf("Gg wp\n");
			exit(0);
		}
		data->move_count += 1;
	}
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		cleanup_and_exit(data);
	else if (keycode == UP_KEY || keycode == W_KEY)
		moves(data, data->map.y_player - 1, data->map.x_player);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		moves(data, data->map.y_player + 1, data->map.x_player);
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		moves(data, data->map.y_player, data->map.x_player - 1);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		moves(data, data->map.y_player, data->map.x_player + 1);
	return (0);
}

void	hook_managing(t_data *data)
{
	data->move_count = 1;
	mlx_key_hook(data->win_ptr, key_pressed, data);
	mlx_hook(data->win_ptr, CLOSE_BUTTON, 0, (void *)cleanup_and_exit, data);
	mlx_loop(data->mlx_ptr);
}
