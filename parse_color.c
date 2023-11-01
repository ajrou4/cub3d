/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:21:21 by majrou            #+#    #+#             */
/*   Updated: 2023/10/31 17:36:28 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_duplcit(t_map_data *data)
{
	int	i;
	int	j;
	int	k;

	i = check_elements(data);
	j = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSWE", data->map[i][j]))
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
	{
		printf("Error\n\tMultiple or no player position\n");
		free_map(data->map);
		exit(0);
	}
}

void	parse_floor_line(t_map_data *data, char *line)
{
	char	**str;
	int		k;

	str = ft_split(line + 2, ',');
	if (!str)
		exit(0);
	if (!str[0] || !str[1] || !str[2])
	{
		printf("Error :number in rgb is not complet !!\n");
		exit(0);
	}
	k = 0;
	while (str[k])
	{
		if (ft_atoi(str[k]) > 255)
		{
			printf("Error : Color value must be between 0 and 255\n");
			free_map(str);
			exit(0);
		}
		else if (ft_atoi(str[k]) <= 255)
			data->color->floor[k] = ft_atoi(str[k]);
		k++;
	}
	free_map(str);
}

void	parse_ceiling_line(t_map_data *data, char *line)
{
	char	**str;
	int		k;

	str = ft_split(line + 2, ',');
	if (!str)
		exit(0);
	if (!str[0] || !str[1] || !str[2])
	{
		printf("Error :number in rgb is not complet !!\n");
		exit(0);
	}
	k = 0;
	while (str[k])
	{
		if (ft_atoi(str[k]) > 255)
		{
			printf("Error : Color value must be between 0 and 255\n");
			free_map(str);
			exit(0);
		}
		else if (ft_atoi(str[k]) <= 255)
			data->color->sky[k] = ft_atoi(str[k]);
		k++;
	}
	free_map(str);
}

void	get_color(t_map_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strnstr(data->map[i], "F ", 2))
			parse_floor_line(data, data->map[i]);
		if (ft_strnstr(data->map[i], "C ", 2))
			parse_ceiling_line(data, data->map[i]);
		i++;
	}
	free(data->color);
}
