/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/11 14:44:28 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

bool			cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit);
static void		cb_get_step_dir(t_vd raystart, t_vd raydir, t_ray *ray);
static double	cb_raydis(t_vi *vmap, t_vd *raylen, t_vi step_dir, t_vd steps);

static double	cb_raydis(t_vi *vmap, t_vd *raylen, t_vi step_dir, t_vd steps)
{
	double	distance;

	distance = 0.0f;
	if (raylen->x < raylen->y)
	{
		vmap->x += step_dir.x;
		distance = raylen->x;
		raylen->x += steps.x;
	}
	else
	{
		vmap->y += step_dir.y;
		distance = raylen->y;
		raylen->y += steps.y;
	}
	return (distance);
}

static void	cb_get_step_dir(t_vd raystart, t_vd raydir, t_ray *ray)
{
	if (raydir.x < 0)
	{
		ray->stpdir.x = -1;
		ray->raylen.x = (raystart.x - (double)ray->vmap.x) * ray->stps.x;
	}
	else
	{
		ray->stpdir.x = 1;
		ray->raylen.x = ((double)(ray->vmap.x + 1) - raystart.x) * ray->stps.x;
	}
	if (raydir.y < 0)
	{
		ray->stpdir.y = -1;
		ray->raylen.y = (raystart.y - (double)ray->vmap.y) * ray->stps.y;
	}
	else
	{
		ray->stpdir.y = 1;
		ray->raylen.y = ((double)(ray->vmap.y + 1) - raystart.y) * ray->stps.y;
	}
	return ;
}

// if (cb_castray(g, ply->ren, ply->dir, &hit))
bool	cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit)
{
	t_ray	ray;
	bool	found;

	cb_ray_init(&ray);
	ray.stps.x = sqrt(1 + (ray_dir.y / ray_dir.x) * (ray_dir.y / ray_dir.x));
	ray.stps.y = sqrt(1 + (ray_dir.x / ray_dir.y) * (ray_dir.x / ray_dir.y));
	t_vd_toint(&g->player.map, &ray_start);
	t_vi_equal(&ray.vmap, &g->player.map);
	found = false;
	cb_get_step_dir(ray_start, ray_dir, &ray);
	while (!found && ray.distance < RAYMX)
	{
		ray.distance = cb_raydis(&ray.vmap, &ray.raylen, ray.stpdir, ray.stps);
		if (g->map[ray.vmap.y][ray.vmap.x] == 1)
			found = true;
	}
	if (found)
	{
		hit->x = ray_start.x + ray_dir.x * ray.distance;
		hit->y = ray_start.y + ray_dir.y * ray.distance;
	}
	return (found);
}
