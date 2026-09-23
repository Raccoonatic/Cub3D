/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:41:13 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/20 19:29:15 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_minimap_init(t_game *g, t_mp *m);
static void	cp_build_map(t_game *g, t_mp *m, t_img *sqr);

void	cb_minimap_init(t_game *g, t_mp *m)
{
	t_img	sqr;
	size_t	guide;

	cb_get_mapsize(g, m);
	m->pov = mlx_new_image(g->mlx, m->w, m->h);
	if (!m->pov)
		cb_kill_the_game(g, 0, 3, 1);
	m->addr = mlx_get_data_addr(m->pov, &m->bpx, &m->bpr, &m->e);
	cb_imgmain_init(g, &m->map, NULL);
	cb_null_ptrs(&sqr);
	cb_zero_ints(&sqr);
	sqr.h = TSZ;
	sqr.w = TSZ;
	cb_imgmain_init(g, &sqr, NULL);
	guide = 0;
	while (guide < (size_t)((sqr.h * sqr.bpr) / sizeof(int)))
	{
		((int *)sqr.addr)[guide] = MNMWC;
		guide++;
	}
	cp_build_map(g, m, &sqr);
	cb_imgdata_wipe(g, &sqr);
	cb_imgmain_init(g, &m->ph, m->ph.path);
	m->ray_color = cb_get_ray_color(g);
	return ;
}

static void	cp_build_map(t_game *g, t_mp *m, t_img *sqr)
{
	int		x;
	int		y;
	t_cord	c;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			cb_coordinate(&c, 1, g, x * TSZ);
			c.y = y * TSZ;
			if (g->map[y][x] == '1' || g->map[y][x] == '2')
				cb_push_tile_to_frame(&m->map, sqr, c, 'R');
			x++;
		}
		y++;
	}
	cb_blackpink(&m->map, m->map.h, 0xFF00FF);
}
