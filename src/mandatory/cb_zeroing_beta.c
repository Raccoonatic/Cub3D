/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_zeroing_beta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:38:17 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/14 13:37:24 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_zero_mp(t_mp *mp);
void	cb_ray_init(t_ray *ray);
void	cb_zero_columns(t_col clmn[]);
void	cb_zero_player(t_player *player);

void	cb_zero_player(t_player *player)
{
	player->map.x = 0;
	player->map.y = 0;
	player->ren.x = 0.0f;
	player->ren.y = 0.0f;
	player->dir.x = 0.0f;
	player->dir.y = 0.0f;
	player->plne.x = 0.0f;
	player->plne.y = 0.0f;
	player->acel = 0.05f;
	return ;
}

void	cb_zero_mp(t_mp *mp)
{
	mp->pov = NULL;
	mp->addr = NULL;
	mp->bpr = 0;
	mp->bpx = 0;
	mp->bpr = 0;
	mp->e = 0;
	mp->h = MXMPH;
	mp->w = MXMPW;
	mp->x = 0;
	mp->y = 0;
	mp->ray_color = 0x000000;
	mp->flor_color = 0xFF00FF;
	mp->ph.path = ft_strdup("./textures/p_head.xpm");
	if (!mp->ph.path)
		cb_fail(1, 1, "Allocation Error"NOR" p_head sprite");
}

void	cb_zero_columns(t_col clmn[])
{
	unsigned int	i;

	i = 0;
	while (i < WW)
	{
		clmn->perp_dist = 0.0f;
		clmn->face = FN;
		clmn->hit.x = 0.0f;
		clmn->hit.y = 0.0f;
		i++;
	}
	return ;
}

void	cb_zero_ray(t_ray *ray)
{
	ray->stps.x = 0.0f;
	ray->stps.y = 0.0f;
	ray->stpdir.x = 0;
	ray->stpdir.y = 0;
	ray->vmap.x = 0;
	ray->vmap.y = 0;
	ray->raylen.x = 0.0f;
	ray->raylen.y = 0.0f;
	ray->distance = 0.0f;
	ray->g = NULL;
	return ;
}
