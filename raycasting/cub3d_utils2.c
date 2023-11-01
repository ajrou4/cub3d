/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:34:55 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/01 03:55:53 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	rad(float degree)
{
	return (degree * M_PI / 180);
}

int	strlen_nn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

void	player_x_y(t_map_data *mape)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mape->row_count)
	{
		j = -1;
		while (++j < mape->col_count && mape->map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", mape->map[i][j]))
			{
				mape->p_x = i * SQ_ + SQ_ / 2;
				mape->p_y = j * SQ_ + SQ_ / 2;
				initialize_player_data(mape, mape->p_x / SQ_, mape->p_y / SQ_);
			}
		}
	}
}

void	initialize_player_data(t_map_data *mape, int x, int y)
{
	if (mape->map[x][y] == 'N')
		mape->r_angle = M_PI;
	else if (mape->map[x][y] == 'S')
		mape->r_angle = 0;
	else if (mape->map[x][y] == 'E')
		mape->r_angle = M_PI / 2;
	else if (mape->map[x][y] == 'W')
		mape->r_angle = (3 * M_PI) / 2;
	mape->fov = (60 * (M_PI / 180));
}
