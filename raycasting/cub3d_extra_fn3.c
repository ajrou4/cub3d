/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_extra_fn3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:55:27 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/01 04:43:57 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_putpix(t_map_data *map)
{
	mlx_put_pixel(map->img, map->dda.x, map->dda.y,
		get_color_from_textur(map->tex, map->dda.y_text,
			map->dda.x_text));
}

mlx_texture_t	*def_tex(t_map_data *map)
{
	mlx_texture_t	*tex;

	if (map->hordis > map->verdis)
	{
		if (map->israyfacingright)
			tex = map->texteur->ea;
		else
			tex = map->texteur->we;
	}
	else
	{
		if (map->israyfacingup)
			tex = map->texteur->no;
		else
			tex = map->texteur->so;
	}
	return (tex);
}

void	dda(t_map_data *map, t_vect v1, t_vect v2)
{
	map->tex = def_tex(map);
	init_dda(map, v1, v2);
	if (map->heightwall > HEIGHT)
		map->dda.y_text = ((map->heightwall - HEIGHT) / 2) * map->dda.inc;
	while (map->dda.i <= map->dda.steps)
	{
		if (map->dda.x >= WIDTH || map->dda.y >= HEIGHT)
			break ;
		if (map->hordis > map->verdis)
			map->dda.x_text = ((map->vwallhity / SQ_) - (int)(map->vwallhity
						/ SQ_)) * map->tex->width;
		else
			map->dda.x_text = ((map->hwallhitx / SQ_) - (int)(map->hwallhitx
						/ SQ_)) * map->tex->width;
		my_putpix(map);
		map->dda.x += map->dda.xinc;
		map->dda.y += map->dda.yinc;
		map->dda.y_text += map->dda.inc;
		map->dda.i++;
	}
}
