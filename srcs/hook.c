/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:48:22 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/20 03:38:42 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	moves(t_data *data, int y, int x)
{
	if (data->map.map_data[y][x] != '1')
	{
		data->map.y_player = y;
		data->map.x_player = x;
		if (data->map.map_data[y][x] == 'C')
		{
			data->map.map_data[y][x] = '0';
			data->map.c_count--;
		}
		render_floor(data);
		render_map(data);
		if (data->map.c_count == 0)
			data->sprites.exit = data->sprites.exit_open;
		if (data->map.c_count == 0 && data->map.map_data[y][x] == 'E')
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			ft_printf("Gg wp");
			exit(0);
		}
	}
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
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

void	destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.player_right);
	mlx_destroy_image(data->mlx_ptr, data->sprites.player_left);
	mlx_destroy_image(data->mlx_ptr, data->sprites.player_back);
	mlx_destroy_image(data->mlx_ptr, data->sprites.ground);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collec);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
}

void	hook_managing(t_data *data)
{
	mlx_key_hook(data->win_ptr, key_pressed, data);
	mlx_hook(data->win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(data->mlx_ptr);
	destroy_sprites(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
