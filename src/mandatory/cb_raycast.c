/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/11 19:53:42 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

bool			cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit);
static void		cb_get_step_dir(t_game *g, t_vd rstart, t_vd rdir, t_ray *ray);
static double	cb_raydis(t_ray *ray);

static double	cb_raydis(t_ray *ray)
{
	double	distance;

	distance = 0.0f;
	if (ray->raylen.x < ray->raylen.y)
	{
		ray->vmap.x += ray->stpdir.x;
		distance = ray->raylen.x;
		ray->raylen.x += ray->stps.x;
	}
	else
	{
		ray->vmap.y += ray->stpdir.y;
		distance = ray->raylen.y;
		ray->raylen.y += ray->stps.y;
	}
	return (distance);
}

static void	cb_get_step_dir(t_game *g, t_vd rstart, t_vd rdir, t_ray *ray)
{
	if (rdir.x < 0)
	{
		ray->stpdir.x = -1;
		g->l = 'L';
		ray->raylen.x = (rstart.x - (double)ray->vmap.x) * ray->stps.x;
	}
	else
	{
		ray->stpdir.x = 1;
		g->l = 'R';
		ray->raylen.x = ((double)(ray->vmap.x + 1) - rstart.x) * ray->stps.x;
	}
	if (rdir.y < 0)
	{
		ray->stpdir.y = -1;
		ray->raylen.y = (rstart.y - (double)ray->vmap.y) * ray->stps.y;
	}
	else
	{
		ray->stpdir.y = 1;
		ray->raylen.y = ((double)(ray->vmap.y + 1) - rstart.y) * ray->stps.y;
	}
	return ;
}

bool	cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit)
{
	t_ray	ray;
	bool	found;

	cb_ray_init(&ray);
	ray.g = g;
	t_vd_equal(&ray.raylen, &ray_dir);
	ray.stps.x = sqrt(1 + (ray_dir.y / ray_dir.x) * (ray_dir.y / ray_dir.x));
	ray.stps.y = sqrt(1 + (ray_dir.x / ray_dir.y) * (ray_dir.x / ray_dir.y));
	t_vd_toint(&g->player.map, &ray_start);
	t_vi_equal(&ray.vmap, &g->player.map);
	found = false;
	cb_get_step_dir(g, ray_start, ray_dir, &ray);
	while (!found && ray.distance < RAYMX)
	{
		ray.distance = cb_raydis(&ray);
		hit->x = ray_start.x + ray_dir.x * ray.distance;
		hit->y = ray_start.y + ray_dir.y * ray.distance;
		cb_draw_ray_minimap(ray.g, *hit);
		if (g->map[ray.vmap.y][ray.vmap.x] == '1')
			found = true;
	}
	return (found);
}
