/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_utils_beta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:24:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/20 19:55:35 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void			cb_render_walls(t_game *g);
static void		cb_draw_column(t_img *img, t_img *tex, t_cord *crd, double stp);
static t_img	*cb_get_wall_tex(t_game *g, t_card face);

static int	cb_get_tex_x(t_col *clmn, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (clmn->face == FN || clmn->face == FS)
		wall_x = clmn->hit.x;
	else
		wall_x = clmn->hit.y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->w);
	if (clmn->face == FN || clmn->face == FE)
		tex_x = tex->w - tex_x - 1;
	return (tex_x);
}

static t_img	*cb_get_wall_tex(t_game *g, t_card face)
{
	if (face == FN)
		return (&g->nwall);
	if (face == FS)
		return (&g->swall);
	if (face == FE)
		return (&g->ewall);
	return (&g->wwall);
}

static void	cb_draw_column(t_img *img, t_img *tex, t_cord *crd, double stp)
{
	char	*tmp;
	char	*src;
	double	pos;
	int		y;
	int		tex_y;

	pos = (crd->y - (double)img->h / 2 + (double)crd->lh / 2) * stp;
	y = crd->y;
	while (y <= crd->th)
	{
		tex_y = (int)pos;
		if (tex_y >= tex->h)
			tex_y = tex->h - 1;
		src = tex->addr + (tex_y * tex->bpr) + (crd->tex_x * (tex->bpx / 8));
		tmp = img->addr + (y * img->bpr) + (crd->x * (img->bpx / 8));
		if (*(unsigned int *)src != 0xFF00FF)
			*(unsigned int *)tmp = *(unsigned int *)src;
		pos += stp;
		y++;
	}
}

void	cb_render_walls(t_game *g)
{
	int		i;
	int		line_height;
	t_img	*tex;
	t_cord	cords;

	i = 0;
	while (i < g->w)
	{
		line_height = (int)(g->h / g->columns[i].perp_dist);
		tex = cb_get_wall_tex(g, g->columns[i].face);
		cords.tex_x = cb_get_tex_x(&g->columns[i], tex);
		cords.y = (line_height * -1) / 2 + g->h / 2;
		if (cords.y < 0)
			cords.y = 0;
		cords.th = line_height / 2 + g->h / 2;
		if (cords.th >= g->h)
			cords.th = g->h - 1;
		cords.fh = g->h;
		cords.fw = g->w;
		cords.lh = line_height;
		cords.x = i;
		cb_draw_column(&g->buf, tex, &cords, ((double)tex->h / cords.lh));
		i++;
	}
	return ;
}
