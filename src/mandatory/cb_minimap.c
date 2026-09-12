/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:41:13 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 15:39:16 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_minimap_init(t_game *g, t_mp *m);
void		cb_minimap_compose(t_game *g, t_mp *m);
static void	cb_get_mapsize(t_game *g, t_mp *mp);
static void	cp_build_map(t_game *g, t_mp *m, t_img *sqr);
static void	cb_apply_pov(t_game *g);

void	cb_minimap_compose(t_game *g, t_mp *m)
{
	t_cord	c;
	t_vd	hit;

	cb_apply_pov(g);
	cb_castray(g, g->player.ren, g->player.dir, &hit);	// TODO: Ideally, *if this function returns true,
																				// * we'll print a column based on the hit coordinates.
	c.fh = g->h;
	c.fw = g->w;
	c.th = g->mp.ph.h;
	c.tw = g->mp.ph.w;
	c.x = 30 + ((g->player.ren.x * TSZ) - g->mp.x) - (c.tw / 2);
	c.y = (g->h - g->mp.h - 30)
		+ ((g->player.ren.y * TSZ) - g->mp.y) - (c.th / 2);
	cb_push_tile_to_frame(&g->buf, &m->ph, c, g->l);
	return ;
}

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

static void cb_clamp_pov(t_game *g)
{
	g->mp.x = (g->player.ren.x * TSZ) - (g->mp.w / 2) + ((float)TSZ / 2);
	g->mp.y = (g->player.ren.y * TSZ) - (g->mp.h / 2) + ((float)TSZ / 2);
	if (g->mp.x < 0)
		g->mp.x = 0;
	if (g->mp.y < 0)
		g->mp.y = 0;
	if (g->mp.x > g->mp.map.w - g->mp.w)
		g->mp.x = g->mp.map.w - g->mp.w;
	if (g->mp.y > g->mp.map.h - g->mp.h)
		g->mp.y = g->mp.map.h - g->mp.h;
	return ;
}

static void cb_apply_pov(t_game *g)
{
	int             x;
	int             y;
	unsigned int    *s;
	unsigned int    *d;

	cb_clamp_pov(g);
	y = 0;
	while (y < g->mp.h)
	{
		x = 0;
		while (x < g->mp.w)
		{
			s = (unsigned int *)(g->mp.map.addr + ((g->mp.y + y)
					* g->mp.map.bpr) + ((g->mp.x + x) * 4));
			d = (unsigned int *)(g->buf.addr + ((g->h - g->mp.h
					- 30 + y) * g->buf.bpr) + ((30 + x) * 4));
			if (*s != 0x00FF00FF)
				*d = *s;
			x++;
		}
		y++;
	}
}

static void cp_build_map(t_game *g, t_mp *m, t_img *sqr)
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
			if (g->map[y][x] == '1')
				cb_push_tile_to_frame(&m->map, sqr, c, 'R');
			x++;
		}
		y++;
	}
	cb_blackpink(&m->map, m->map.h, g->flor_c);
}

static void	cb_get_mapsize(t_game *g, t_mp *mp)
{
	int	guide;

	mp->map.w = TSZ * ft_strlen(g->map[0]);
	guide = 0;
	while (g->map[guide])
		guide++;
	mp->map.h = TSZ * guide;
	if (mp->w > mp->map.w)
		mp->w = mp->map.w;
	if (mp->h > mp->map.h)
		mp->h = mp->map.h;
	return ;
}
