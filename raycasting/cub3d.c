/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:59:08 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/01 04:33:42 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dda(t_map_data *map, t_vect v1, t_vect v2)
{
	map->dda.i = 0;
	map->dda.dx = v2.x - v1.x;
	map->dda.dy = v2.y - v1.y;
	if (abs(map->dda.dx) > abs(map->dda.dy))
		map->dda.steps = abs(map->dda.dx);
	else
		map->dda.steps = abs(map->dda.dy);
	map->dda.xinc = map->dda.dx / (float)map->dda.steps;
	map->dda.yinc = map->dda.dy / (float)map->dda.steps;
	map->dda.x = v1.x;
	map->dda.y = v1.y;
	map->dda.inc = map->tex->height / map->heightwall;
	map->dda.y_text = 0.0;
	map->dda.x_text = 0.0;
}

void	loop(void *p)
{
	t_map_data	*a;

	a = p;
	processrotationandesc(a);
	processdirectionkeys(a);
	if (ismoveallowed(a))
	{
		a->p_x = a->p_xtmp;
		a->p_y = a->p_ytmp;
		cast_all_rays(p);
	}
}
