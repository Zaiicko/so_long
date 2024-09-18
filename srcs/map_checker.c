/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/18 21:43:20 by zaiicko          ###   ########.fr       */
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

void	check_if_valid_char(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		error_msg("Empty line in ber file");
	while(line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			error_msg("Wrong char in the ber file");
		i++;
	}
}

void	check_gameobjects(t_data *data)
{
	int	i;
	int	j;
	

	i = 0;
	data->map.p_count = 0;
	data->map.e_count = 0;
	data->map.c_count = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.map_data[i][j])
		{
			if (data->map.map_data[i][j] == 'P')
				data->map.p_count++;
			else if (data->map.map_data[i][j] == 'E')
				data->map.e_count++;
			else if (data->map.map_data[i][j] == 'C')
				data->map.c_count++;
			j++;
		}
		i++;
	}
	if (data->map.p_count != 1 || data->map.e_count != 1 || data->map.c_count < 1)
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
	data->map.width = ft_strlen(data->map.map_data[0]) - 1;
}
