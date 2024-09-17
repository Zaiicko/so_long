/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:53:23 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/17 22:44:32 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../minilibx/mlx.h"

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define VALID_CHARS "01CEP"

typedef struct s_map
{
	char	**map_data;
	int	width;
	int	height;
}	t_map;

typedef struct s_sprites
{
	void	*ground;
	void	*player_left;
	void	*player_right;
	void	*player_back;
	void	*exit;
	void	*collec;
	void	*wall;
	int	width;
	int	height;
}	t_sprites;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_sprites	sprites;
	t_map		map;
}	t_data;

int	key_pressed(int keysym, t_data *data);
void	loading_all_sprites(t_data *data);
void	loading_a_sprite(t_data *data, void **sprite, char *path);
void	error_msg(char *msg);
void	check_args(int ac, char **av);
int	check_if_ber(char *name);
void	loading_map(t_data *data, char *name);
void	extract_ber_data(t_data *data, char *name);
void	check_if_valid_char(t_data *data);
void	check_map(t_data *data);
