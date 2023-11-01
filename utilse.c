/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:07:48 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 07:00:44 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_acceptable_char(char c)
{
	if (c == '1' || c == 'N' || c == 'W' || c == 'S' || c == 'E' || c == '0')
		return (1);
	return (0);
}

int	is_near_zero_valid(char **map, int i, int c)
{
	if ((i - 1 >= 0 && !is_acceptable_char(map[i - 1][c])) \
		|| (c - 1 >= 0 && !is_acceptable_char(map[i][c - 1])) \
		|| (map[i + 1] && !is_acceptable_char(map[i + 1][c])) \
		|| (map[i][c + 1] && !is_acceptable_char(map[i][c + 1])))
	{
		return (0);
	}
	return (1);
}

int	check_valide_map(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				if (!is_near_zero_valid(data->map, i, j) \
					|| ((i - 1 >= 0 && j > (int)ft_strlen(data->map[i - 1]))
						|| i == 0) || (data->map[i + 1] && j
						> (int)ft_strlen(data->map[i + 1])))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_column(t_map_data *data)
{
	int	i;

	i = 0;
	while (i < data->col_count)
	{
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
			return (0);
		i++;
	}
	while (i < data->col_count)
	{
		if (data->map[data->row_count - 1][i] != '1'
			&& data->map[data->row_count - 1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	remove_newlines(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
