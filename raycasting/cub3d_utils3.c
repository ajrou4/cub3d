/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:37:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/31 21:06:05 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_map(t_map_data *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 1);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_loop_hook(map->mlx, loop, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}
