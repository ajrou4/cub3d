/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texteur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:32:43 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 06:55:36 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	text_no(t_map_data *data, int i)
{
	if (access(data->map[i] + 3, R_OK))
	{
		printf("Error\n");
		exit(0);
	}
	data->texteur->no = mlx_load_png(data->map[i] + 3);
	if (data->texteur->no == NULL)
	{
		printf("Error\n");
		exit(0);
	}
}

static void	text_so(t_map_data *data, int i)
{
	if (access(data->map[i] + 3, R_OK))
	{
		printf("Error\n");
		exit(0);
	}
	data->texteur->so = mlx_load_png(data->map[i] + 3);
	if (data->texteur->so == NULL)
	{
		printf("Error\n");
		exit(0);
	}
}

static void	text_ea(t_map_data *data, int i)
{
	if (access(data->map[i] + 3, R_OK))
	{
		printf("Error\n");
		exit(0);
	}
	data->texteur->ea = mlx_load_png(data->map[i] + 3);
	if (data->texteur->no == NULL)
	{
		printf("Error\n");
		exit(0);
	}
}

static void	text_we(t_map_data *data, int i)
{
	if (access(data->map[i] + 3, R_OK))
	{
		printf("Error\n");
		exit(0);
	}
	data->texteur->we = mlx_load_png(data->map[i] + 3);
	if (data->texteur->no == NULL)
	{
		printf("Error\n");
		exit(0);
	}
}

t_texteur	*get_tex(t_map_data *data)
{
	int	i;

	i = 0;
	data->texteur = malloc(sizeof(t_texteur));
	while (data->map[i])
	{
		if (ft_strnstr(data->map[i], "NO ", 3))
			text_no(data, i);
		if (ft_strnstr(data->map[i], "SO ", 3))
			text_so(data, i);
		if (ft_strnstr(data->map[i], "WE ", 3))
			text_we(data, i);
		if (ft_strnstr(data->map[i], "EA ", 3))
			text_ea(data, i);
		i++;
	}
	return (0);
}
