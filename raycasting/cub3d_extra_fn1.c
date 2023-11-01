/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_extra_fn1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:25:16 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/31 01:26:00 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	calc_vert_dis(t_map_data *mape)
{
	float	dis;

	dis = sqrt(pow((mape->vertwallhitx - mape->p_x), 2) + pow((mape->vwallhity
					- mape->p_y), 2));
	return (dis);
}

float	calc_hor_dis(t_map_data *mape)
{
	float	dis;

	dis = sqrt(pow(mape->hwallhitx - mape->p_x, 2) + pow(mape->horzwallhity
				- mape->p_y, 2));
	return (dis);
}
