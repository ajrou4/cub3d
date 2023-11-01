/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:20:01 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/31 17:03:32 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_all_rays(t_map_data *mape)
{
	int	i;

	i = 0;
	mape->ray_angle = mape->r_angle - (mape->fov / 2);
	while (i < WIDTH)
	{
		cast_horizontal_ray(mape);
		cast_vertical_ray(mape);
		mape->ray_angle += mape->fov / WIDTH;
		if (mape->foundhorzwallhit)
			mape->hordis = calc_hor_dis(mape);
		else
			mape->hordis = 100000;
		if (mape->foundvertwallhit)
			mape->verdis = calc_vert_dis(mape);
		else
			mape->verdis = 100000;
		generate3dprojection(mape, i);
		i++;
	}
}

void	init_hor(t_map_data *mape)
{
	mape->ray_angle = normalize(mape->ray_angle);
	mape->israyfacingdown = mape->ray_angle > 0 && mape->ray_angle < M_PI;
	mape->israyfacingup = !mape->israyfacingdown;
	mape->israyfacingright = mape->ray_angle < M_PI_2 || mape->ray_angle > 3
		* M_PI_2;
	mape->israyfacingleft = !mape->israyfacingright;
	mape->foundhorzwallhit = false;
	mape->hwallhitx = mape->p_y;
	mape->horzwallhity = mape->p_x;
	mape->hr.yintercept = (int)mape->p_y / SQ_ * SQ_;
	if (mape->israyfacingdown)
		mape->hr.yintercept += SQ_;
	else
		mape->hr.yintercept -= 0.001;
	mape->hr.xintercept = mape->p_x + (mape->hr.yintercept - mape->p_y)
		/ tan(mape->ray_angle);
	mape->hr.ystep = SQ_;
	if (mape->israyfacingup)
		mape->hr.ystep = -mape->hr.ystep;
	mape->hr.xstep = mape->hr.ystep / tan(mape->ray_angle);
	mape->nexthorztouchx = mape->hr.xintercept;
	mape->nexthorztouchy = mape->hr.yintercept;
}

void	cast_horizontal_ray(t_map_data *mape)
{
	init_hor(mape);
	while (mape->nexthorztouchx >= 0 && mape->nexthorztouchx <= WIDTH
		&& mape->nexthorztouchy >= 0 && mape->nexthorztouchy <= HEIGHT)
	{
		mape->hr.xtocheck = mape->nexthorztouchx;
		mape->hr.ytocheck = mape->nexthorztouchy;
		if (mape->israyfacingup)
			mape->hr.ytocheck -= 1;
		if (maphaswallat(mape, mape->hr.xtocheck, mape->hr.ytocheck))
		{
			mape->hwallhitx = mape->nexthorztouchx;
			mape->horzwallhity = mape->nexthorztouchy;
			mape->foundhorzwallhit = true;
			break ;
		}
		else
		{
			mape->nexthorztouchx += mape->hr.xstep;
			mape->nexthorztouchy += mape->hr.ystep;
		}
	}
}

void	init_vert(t_map_data *mape)
{
	mape->ray_angle = normalize(mape->ray_angle);
	mape->foundvertwallhit = false;
	mape->vertwallhitx = mape->p_y;
	mape->vwallhity = mape->p_x;
	mape->vr.xintercept = (int)mape->p_x / SQ_ * SQ_;
	if (mape->israyfacingright)
		mape->vr.xintercept += SQ_;
	else
		mape->vr.xintercept -= 0.001;
	mape->vr.yintercept = mape->p_y + (mape->vr.xintercept - mape->p_x)
		* tan(mape->ray_angle);
	mape->vr.xstep = SQ_;
	if (mape->israyfacingleft)
		mape->vr.xstep = -mape->vr.xstep;
	mape->vr.ystep = SQ_ * tan(mape->ray_angle);
	if (mape->israyfacingup && mape->vr.ystep > 0)
		mape->vr.ystep = -mape->vr.ystep;
	else if (mape->israyfacingdown && mape->vr.ystep < 0)
		mape->vr.ystep = -mape->vr.ystep;
	mape->nextverttouchx = mape->vr.xintercept;
	mape->nextverttouchy = mape->vr.yintercept;
}

void	cast_vertical_ray(t_map_data *mape)
{
	init_vert(mape);
	while (mape->nextverttouchx >= 0 && mape->nextverttouchx <= WIDTH
		&& mape->nextverttouchy >= 0 && mape->nextverttouchy <= HEIGHT)
	{
		mape->vr.ytocheck = mape->nextverttouchy;
		mape->vr.xtocheck = mape->nextverttouchx;
		if (mape->israyfacingleft)
			mape->vr.xtocheck -= 1;
		if (maphaswallat(mape, mape->vr.xtocheck, mape->vr.ytocheck))
		{
			mape->vertwallhitx = mape->nextverttouchx;
			mape->vwallhity = mape->nextverttouchy;
			mape->foundvertwallhit = true;
			break ;
		}
		else
		{
			mape->nextverttouchx += mape->vr.xstep;
			mape->nextverttouchy += mape->vr.ystep;
		}
	}
}
