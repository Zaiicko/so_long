/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:00:58 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/17 23:12:49 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	extract_ber_data(t_data *data, char *name)
{ 
	int	fd;
	size_t	i;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open the map file");
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->map.map_data[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map.map_data[i] = NULL;
	close(fd);
}

void	loading_map(t_data *data, char *name)
{
	extract_ber_data(data, name);
	data->map.width = ft_strlen(data->map.map_data[0]) - 1;
	data->map.height = 0;
	while (data->map.map_data[data->map.height])
		data->map.height++;
	check_map(data);
}
