/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_layer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:48:10 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 23:08:38 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_imgmain_init(t_game *g, t_img *i, char *path);
void		cb_layer_init(t_game *g, int *bpx, int *bpr, int *e);
static void	cb_get_bkgrnd(t_game *g, int *bpx, int *bpr, int *e);

void	cb_layer_init(t_game *g, int *bpx, int *bpr, int *e)
{
	g->buf.main = mlx_new_image(g->mlx, g->w, g->h);
	if (!g->buf.main)
		cb_kill_the_game(g, 0, 3, 1);
	g->buf.addr = mlx_get_data_addr(g->buf.main, bpx, bpr, e);
	g->buf.h = g->h;
	g->buf.w = g->w;
	cb_get_bkgrnd(g, &g->bkg.bpx, &g->bkg.bpr, &g->bkg.e);
	cb_minimap_init(g, &g->mp);
	g->mp.flor_color = cb_colorshift(g->flor_c);
	return ;
}

static void	cb_get_bkgrnd(t_game *g, int *bpx, int *bpr, int *e)
{
	int		*pix;
	size_t	guide;

	g->bkg.w = WW;
	g->bkg.h = WH;
	g->bkg.main = mlx_new_image(g->mlx, g->bkg.w, g->bkg.h);
	if (!g->bkg.main)
		cb_kill_the_game(g, 0, 3, 1);
	g->bkg.addr = mlx_get_data_addr(g->bkg.main, bpx, bpr, e);
	pix = (int *)g->bkg.addr;
	guide = 0;
	while (guide < ((size_t)((g->bkg.h * (*bpr)) / sizeof(int)) / 2))
	{
		pix[guide] = g->ceil_c;
		guide++;
	}
	while (guide < (size_t)((g->bkg.h * (*bpr)) / sizeof(int)))
	{
		pix[guide] = g->flor_c;
		guide++;
	}
	cb_push_bkgrnd_to_frame(&g->buf, &g->bkg);
	return ;
}

void	cb_imgmain_init(t_game *g, t_img *i, char *path)
{
	if (path)
		i->main = mlx_xpm_file_to_image(g->mlx, path, &i->w, &i->h);
	else
		i->main = mlx_new_image(g->mlx, i->w, i->h);
	if (!i->main)
		cb_kill_the_game(g, 0, 3, 1);
	i->addr = mlx_get_data_addr(i->main, &i->bpx, &i->bpr, &i->e);
	return ;
}
