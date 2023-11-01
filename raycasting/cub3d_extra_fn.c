/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_extra_fn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:06 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/31 20:47:56 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floooor(t_map_data *m, int i)
{
	while (m->p.j < m->p.walltoppixel)
	{
		if (i > 0 && i < HEIGHT && m->p.j > 0 && m->p.j < WIDTH)
			mlx_put_pixel(m->img, i, m->p.j, 
				ft_pixel(m->cr, m->cg, m->cb, 255));
		m->p.j++;
	}
}

void	ceeeil(t_map_data *m, int i)
{
	while (m->p.j < HEIGHT)
	{
		if (i > 0 && i < HEIGHT && m->p.j > 0 && m->p.j < WIDTH)
			mlx_put_pixel(m->img, i, m->p.j, 
				ft_pixel(m->fr, m->fg, m->fb, 255));
		m->p.j++;
	}
}

void	generate3dprojection(t_map_data *m, int __unused i)
{
	t_vect	v1;
	t_vect	v2;

	m->p.j = 0;
	m->p.distance = short_distance(m);
	m->p.perpdistance = m->p.distance * cos(m->ray_angle - m->r_angle);
	m->p.projectedwallheight = (SQ_ / m->p.perpdistance) * ((WIDTH / 2)
			/ tan(m->fov / 2));
	m->p.wallstripheight = (int)m->p.projectedwallheight;
	m->heightwall = m->p.wallstripheight;
	m->p.walltoppixel = (HEIGHT / 2) - (m->p.wallstripheight / 2);
	if (m->p.walltoppixel < 0)
		m->p.walltoppixel = 0;
	m->p.wallbottompixel = (HEIGHT / 2) + (m->p.wallstripheight / 2);
	if (m->p.wallbottompixel > HEIGHT)
		m->p.wallbottompixel = HEIGHT;
	v1.x = i;
	v1.y = m->p.walltoppixel;
	v2.x = i;
	v2.y = m->p.wallbottompixel;
	dda(m, v1, v2);
	floooor(m, i);
	m->p.j = m->p.wallbottompixel;
	ceeeil(m, i);
}

bool	maphaswallat(t_map_data *mape, float y, float x)
{
	int		mapgridindexx;
	int		mapgridindexy;
	char	mapcontent;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return (true);
	}
	mapgridindexx = (int)floor(x / SQ_);
	mapgridindexy = (int)floor(y / SQ_);
	if (mapgridindexx >= mape->col_count)
		return (true);
	if (mapgridindexy >= mape->row_count)
		return (true);
	mapcontent = mape->map[mapgridindexy][mapgridindexx];
	return (mapcontent == '1');
}

float	short_distance(t_map_data *mape)
{
	if (mape->hordis < mape->verdis)
		return (mape->hordis);
	else
		return (mape->verdis);
}
