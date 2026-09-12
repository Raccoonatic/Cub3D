/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_zeroing_beta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:38:17 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 23:21:38 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_zero_mp(t_mp *mp);
void	cb_zero_hit(t_vd *hit);
void	cb_zero_hits(t_vd hits[]);
void	cb_zero_player(t_player *player);

void cb_zero_player(t_player *player)
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

void	cb_zero_hit(t_vd *hit)
{
	hit->x = 0.0f;
	hit->y = 0.0f;
	return ;
}

void	cb_zero_hits(t_vd hits[])
{
	unsigned int i;

	i = 0;
	while (i < WW)
	{
		cb_zero_hit(&hits[i]);
		i++;
	}
	return ;
}
