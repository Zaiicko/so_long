/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:40:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/18 21:27:32 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int key_pressed(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    return (0);
}

void	error_msg(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	count_lines(t_data *data, char *name)
{
	int	fd;
	int	i;
	char	c;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open the map file");
	while(read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			i++;
	}
	close(fd);
	data->map.height = i;
}
