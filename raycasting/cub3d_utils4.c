/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:31:37 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/01 04:42:54 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	processrotationandesc(t_map_data *a)
{
	a->p_xtmp = a->p_x;
	a->p_ytmp = a->p_y;
	a->p_xtmp_check = a->p_x;
	a->p_ytmp_check = a->p_y;
	if (mlx_is_key_down(a->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(a->mlx);
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT))
	{
		rotate_player(a, 0.070000);
		a->r_angle = normalize(a->r_angle);
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT))
	{
		rotate_player(a, -0.070000);
		a->r_angle = normalize(a->r_angle);
	}
}

void	moveindirection(t_map_data *a, double angle)
{
	a->p_ytmp += sin(angle) * PLAYER_SPEED;
	a->p_xtmp += cos(angle) * PLAYER_SPEED;
	a->p_ytmp_check += sin(angle) * (PLAYER_SPEED + 1);
	a->p_xtmp_check += cos(angle) * (PLAYER_SPEED + 1);
}

void	processdirectionkeys(t_map_data *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_W))
	{
		moveindirection(a, a->r_angle);
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_S))
	{
		moveindirection(a, a->r_angle + rad(180));
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_D))
	{
		moveindirection(a, a->r_angle + rad(90));
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_A))
	{
		moveindirection(a, a->r_angle + rad(270));
	}
}

int	ismoveallowed(t_map_data *a)
{
	return (a->map[(int)a->p_x / SQ_][(int)a->p_ytmp_check
		/ SQ_] != '1' &&
			a->map[(int)a->p_xtmp_check / SQ_][(int)a->p_y
				/ SQ_] != '1' &&
			a->map[(int)a->p_xtmp_check / SQ_][(int)a->p_ytmp_check
				/ SQ_] != '1');
}
