/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:09:05 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 06:33:09 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}

char	**read_map(char *file)
{
	int			i;
	int			fd;
	char		**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (count_lines(fd) + 1));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_elements(t_map_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (data->map && data->map[i])
	{
		str = ft_strtrim(data->map[i], " ");
		if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2))
			j++;
		if (!ft_strncmp(str, "1", 1))
		{
			free(str);
			break ;
		}
		free(str);
		i++;
	}
	if (j != 6)
		error_map(data->map);
	return (i);
}

void	check_map(t_map_data *data)
{
	int		j;
	char	*str;
	int		i;

	j = 0;
	i = check_elements(data);
	while (data->map[i])
	{
		j = 0;
		str = ft_strtrim(data->map[i], " \t");
		if (ft_strlen(str) == 0)
			error_map(data->map);
		while (str[j])
		{
			if (ft_strchr("10 NSWE\n", str[j]) == NULL)
				error_cheack_map(data->map, i);
			j++;
		}
		free(str);
		i++;
	}
}
