/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:10:25 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/18 03:54:00 by zaiicko          ###   ########.fr       */
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

