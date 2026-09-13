/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/13 21:30:11 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void			cb_castray(t_game *g, t_vd raystart, t_vd raydir, t_col *clmn);
static void		cb_get_step_dir(t_vd rstart, t_vd rdir, t_ray *ray);
static void		cb_raydis(t_ray *ray, t_col *clmn);
static double	cb_get_perp_dist(t_ray *ray, t_col *clmn);

static double	cb_get_perp_dist(t_ray *ray, t_col *clmn)
{
	if (clmn->face == FE || clmn->face == FW)
		return (ray->raylen.x - ray->stps.x);
	return (ray->raylen.y - ray->stps.y);
}

static void	cb_raydis(t_ray *ray, t_col *clmn)
{
	if (ray->raylen.x < ray->raylen.y)
	{
		ray->vmap.x += ray->stpdir.x;
		ray->distance = ray->raylen.x;
		ray->raylen.x += ray->stps.x;
		if (ray->stpdir.x < 0)
			clmn->face = FE;
		else
			clmn->face = FW;
	}
	else
	{
		ray->vmap.y += ray->stpdir.y;
		ray->distance = ray->raylen.y;
		ray->raylen.y += ray->stps.y;
		if (ray->stpdir.y < 0)
			clmn->face = FS;
		else
			clmn->face = FN;
	}
	return ;
}

static void	cb_get_step_dir(t_vd rstart, t_vd rdir, t_ray *ray)
{
	if (rdir.x < 0)
	{
		ray->stpdir.x = -1;
		ray->raylen.x = (rstart.x - (double)ray->vmap.x) * ray->stps.x;
	}
	else
	{
		ray->stpdir.x = 1;
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

void	cb_castray(t_game *g, t_vd raystart, t_vd raydir, t_col *clmn)
{
	t_ray	ray;
	bool	found;

	cb_zero_ray(&ray);
	ray.g = g;
	t_vd_equal(&ray.raylen, &raydir);
	ray.stps.x = fabs(1.0 / raydir.x);
	ray.stps.y = fabs(1.0 / raydir.y);
	t_vd_toint(&g->ply.map, &raystart);
	t_vi_equal(&ray.vmap, &g->ply.map);
	found = false;
	cb_get_step_dir(raystart, raydir, &ray);
	while (!found && ray.distance < g->raymx)
	{
		cb_raydis(&ray, clmn);
		clmn->hit.x = raystart.x + raydir.x * ray.distance;
		clmn->hit.y = raystart.y + raydir.y * ray.distance;
		cb_draw_ray_minimap(ray.g, clmn->hit);
		if (g->map[ray.vmap.y][ray.vmap.x] == '1')
		{
			found = true;
			clmn->perp_dist = cb_get_perp_dist(&ray, clmn);
		}
	}
	return ;
}
