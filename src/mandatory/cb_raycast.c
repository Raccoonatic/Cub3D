/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/11 13:14:58 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

bool			cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit);
static t_vi		cb_get_step_dir(t_game *g, t_vd raydir, t_vd *stps, t_vd *rlen);
static double	cb_raydis(t_vi *vmap, t_vd *raylen, t_vi step_dir, t_vd steps);
static bool		cb_find_hit(t_game *g, t_vd *raylen, t_vd steps, t_vd *hit);

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

static bool	cb_find_hit(t_game *g, t_vd *raylen, t_vd steps, t_vd *hit)
{
	bool			found;
	double			distance;
	double const	max_distance = RAYMX;
	t_vi			vmap;
	t_vi			step_dir;

	vmap = g->player.map;
	found = false;
	distance = 0.0f;
	step_dir = cb_get_step_dir(g, g->player.dir, &steps, raylen);
	while (!found && distance < max_distance)
	{
		distance = cb_raydis(&vmap, raylen, step_dir, steps);
		if (g->map[vmap.y][vmap.x] == 1)
			found = true;
	}
	if (found)
	{
		hit->x = g->player.ren.x + g->player.dir.x * distance;
		hit->y = g->player.ren.y + g->player.dir.y * distance;
	}
	return (found);
}

static t_vi	cb_get_step_dir(t_game *g, t_vd raydir, t_vd *stps, t_vd *rlen)
{
	t_vi	step_dir;

	if (raydir.x < 0)
	{
		step_dir.x = -1;
		rlen->x = (g->player.ren.x - (double)g->player.map.x) * stps->x;
	}
	else
	{
		step_dir.x = 1;
		rlen->x = ((double)(g->player.map.x + 1) - g->player.ren.x) * stps->x;
	}
	if (raydir.y < 0)
	{
		step_dir.y = -1;
		rlen->y = (g->player.ren.y - (double)g->player.map.y) * stps->y;
	}
	else
	{
		step_dir.y = 1;
		rlen->y = ((double)(g->player.map.y + 1) - g->player.ren.y) * stps->y;
	}
	return (step_dir);
}

// if (cb_castray(g, ply->ren, ply->dir, &hit))
bool	cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir, t_vd *hit)
{
	t_vd	steps;
	t_vd	ray_len;

	steps.x = sqrt(1 + (ray_dir.y / ray_dir.x)) * (ray_dir.y / ray_dir.x);
	steps.y = sqrt(1 + (ray_dir.x / ray_dir.y)) * (ray_dir.x / ray_dir.y);
	g->player.map.x = (int)ray_start.x;
	g->player.map.y = (int)ray_start.y;
	return (cb_find_hit(g, &ray_len, steps, hit));
}
