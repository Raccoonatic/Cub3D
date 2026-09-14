/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_utils_beta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:24:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/14 13:50:58 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_render_walls(t_game *g);
static void	cb_draw_column(t_img *img, t_cord *cords, int color);

static void	cb_draw_column(t_img *img, t_cord *cords, int color)
{
	char	*tmp;
	int		y;

	y = cords->y;
	while (y <= cords->th)
	{
		tmp = img->addr + (y * img->bpr) + (cords->x * (img->bpx / 8));
		*(unsigned int *)tmp = color;
		y++;
	}
}

void	cb_render_walls(t_game *g)
{
	int		i;
	int		line_height;
	t_cord	cords;

	i = 0;
	while (i < g->w)
	{
		line_height = (int)(g->h / g->columns[i].perp_dist);
		cords.y = (line_height * -1) / 2 + g->h / 2;
		if (cords.y < 0)
			cords.y = 0;
		cords.th = line_height / 2 + g->h / 2;
		if (cords.th >= g->h)
			cords.th = g->h - 1;
		cords.fh = g->h;
		cords.fw = g->w;
		cords.tw = 1;
		cords.x = i;
		cb_draw_column(&g->buf, &cords, 0x000000);
		i++;
	}
	return ;
}
