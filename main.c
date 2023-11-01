/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:55:02 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 06:59:01 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_map(t_map_data *data, char ***map)
{
	data->jk.i = 0;
	while ((*map)[data->jk.i])
	{
		data->jk.str = ft_strtrim((*map)[data->jk.i], " ");
		if (!ft_strncmp(data->jk.str, "11", 2))
		{
			free(data->jk.str);
			break ;
		}
		free(data->jk.str);
		data->jk.i++;
	}
	data->jk.new_map = ft_calloc((map_size(*map)
				- data->jk.i + 1), sizeof (char *));
	if (!data->jk.new_map)
		return ;
	data->jk.j = 0;
	while ((*map)[data->jk.i])
	{
		data->jk.new_map[data->jk.j] = ft_strdup((*map)[data->jk.i]);
		data->jk.j++;
		data->jk.i++;
	}
	free_map(*map);
	*map = data->jk.new_map;
}

static void	get_color2(t_map_data *data)
{
	data->fr = data->color->floor[0];
	data->fg = data->color->floor[1];
	data->fb = data->color->floor[2];
	data->cr = data->color->sky[0];
	data->cg = data->color->sky[1];
	data->cb = data->color->sky[2];
}

void	destroy_program(t_map_data *data)
{
	free_map(data->map);
	mlx_delete_texture(data->texteur->no);
	mlx_delete_texture(data->texteur->ea);
	mlx_delete_texture(data->texteur->we);
	mlx_delete_texture(data->texteur->so);
	free(data->color);
	free(data);
}

int	main(int ac, char **av)
{
	t_map_data	*data;

	if (ac != 2)
		return (printf("Error: Where is map\n"), 1);
	data = malloc(sizeof(t_map_data));
	data->map = read_map(av[1]);
	remove_newlines(data);
	check_map(data);
	check_duplcit(data);
	data->color = malloc(sizeof(t_rgb));
	get_color(data);
	get_color2(data);
	get_tex(data);
	new_map(data, &data->map);
	if (check_valide_map(data) == 0)
		error_map(data->map);
	data->col_count = ft_strlen(data->map[0]);
	data->row_count = map_size(data->map);
	check_if_map_enclosed(data);
	player_x_y(data);
	render_map(data);
	destroy_program(data);
	return (0);
}

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
