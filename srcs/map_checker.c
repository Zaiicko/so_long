/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/18 04:38:56 by zaiicko          ###   ########.fr       */
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
	while(line[i] != '\n' && line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			error_msg("Wrong char in the ber file");
		i++;
	}
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

}
