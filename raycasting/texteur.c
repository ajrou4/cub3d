/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:14:25 by majrou            #+#    #+#             */
/*   Updated: 2023/10/31 20:45:46 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_offsetx(t_map_data *data, mlx_texture_t *img)
{
	(void)img;
	if (data->foundvertwallhit == 1)
		data->x_text = fmod(data->hwallhitx, SQ_);
	else if (data->foundhorzwallhit == 1)
		data->x_text = fmod(data->hwallhitx, SQ_);
	return (data->x_text);
}

int	get_color_from_textur(mlx_texture_t *texteur, int x, int y)
{
	int	index;
	int	max;

	max = texteur->width * texteur->height * texteur->bytes_per_pixel;
	index = (x * 4 * texteur->width) + (y * 4);
	if (index >= max)
		return (0);
	return (ft_pixel(texteur->pixels[index], texteur->pixels[index + 1],
			texteur->pixels[index + 2], texteur->pixels[index + 3]));
}
