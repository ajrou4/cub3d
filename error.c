/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:58:38 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 06:58:17 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_cheack_map(char **map, int i)
{
	printf("maps invalid! \n");
	printf("\t%s\n", map[i]);
	free_map(map);
	exit(0);
}

void	error_map(char **map)
{
	printf("Error in map \n");
	free_map(map);
	exit(0);
}

static void	skip_spaces(char *line, int *j)
{
	while (line[*j] == ' ')
		(*j)++;
}

static	int	if_map_closed(t_map_data *data)
{
	int	i;

	i = 0;
	while (i < data->row_count)
	{
		skip_spaces(data->map[i], &i);
		if (data->map[i][0] != '1')
		{
			printf("%s\n", data->map[i]);
			printf("Error: Map is not enclosed\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < data->row_count)
	{
		if (data->map[i][ft_strlen(data->map[i]) - 1] != '1')
		{
			printf("Error: Map is not enclosed\n");
			exit (1);
		}
		i++;
	}
	return (0);
}

int	check_if_map_enclosed(t_map_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
		{
			printf("Error: Map is not enclosed\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (data->map[data->row_count - 1][i])
	{
		if (data->map[data->row_count - 1][i] != '1'
			&& data->map[data->row_count - 1][i] != ' ')
		{
			printf("Error: Map is not enclosed\n");
			exit (1);
		}
		i++;
	}
	if_map_closed(data);
	return (0);
}
