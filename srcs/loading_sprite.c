/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:35:12 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/16 20:57:32 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	loading_all_sprites(t_data *data)
{
	loading_a_sprite(data, &data->sprites.ground,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/ground.xpm");
	loading_a_sprite(data, &data->sprites.player_left,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/player_left.xpm");
	loading_a_sprite(data, &data->sprites.player_right,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/player_right.xpm");
	loading_a_sprite(data, &data->sprites.player_back,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/player_back.xpm");
	loading_a_sprite(data, &data->sprites.exit,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/exit.xpm");
	loading_a_sprite(data, &data->sprites.collec,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/collec.xpm");
	loading_a_sprite(data, &data->sprites.wall,
		"/Users/zaiicko/Dev/42_Cursus/so_long/sprites/wall.xpm");
	return (0);
}

void	loading_a_sprite(t_data *data, void **sprite, char *path)
{
	*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->sprites.width, &data->sprites.height);
	if (!*sprite)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
}
