/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:33:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/10 18:48:06 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void get_step_direction(t_vd ray_dir)
{}

// cb_castray(g, ply->ren, ply->dir)
t_vd	cb_castray(t_game *g, t_vd ray_start, t_vd ray_dir)
{
	t_vd	step;
	t_vd	step_dir;
	t_vd	ray_len;

	step.x = sqrt(1 + (ray_dir.y / ray_dir.x)) * (ray_dir.y / ray_dir.x);
	step.y = sqrt(1 + (ray_dir.x / ray_dir.y)) * (ray_dir.x / ray_dir.y);
	g->player.map.x = (int)ray_start.x;
	g->player.map.y = (int)ray_start.y;
	step_dir = get_step_direction(ray_dir);

	return ();
}
