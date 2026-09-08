/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:47:55 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/07 14:00:15 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_frink(t_game *g);
void		cb_free_matrix(char **matrix);
void		cb_imgdata_wipe(t_game *g, t_img *i);
static void	cb_free_img_matrix(t_game *g, void **matrix);

void	cb_frink(t_game *g)
{
	if (g->bkg.main || g->bkg.frm || g->bkg.frad || g->bkg.path)
		cb_imgdata_wipe(g, &g->bkg);
	if (g->buf.main || g->buf.frm || g->buf.frad || g->buf.path)
		cb_imgdata_wipe(g, &g->buf);
	if (g->mp.map.main || g->mp.map.frm || g->mp.map.frad || g->mp.map.path)
		cb_imgdata_wipe(g, &g->mp.map);
	if (g->mp.ph.main || g->mp.ph.frm || g->mp.ph.frad || g->mp.ph.path)
		cb_imgdata_wipe(g, &g->mp.ph);
	if (g->nwall.main || g->nwall.frm || g->nwall.frad || g->nwall.path)
		cb_imgdata_wipe(g, &g->nwall);
	if (g->swall.main || g->swall.frm || g->swall.frad || g->swall.path)
		cb_imgdata_wipe(g, &g->swall);
	if (g->ewall.main || g->ewall.frm || g->ewall.frad || g->ewall.path)
		cb_imgdata_wipe(g, &g->ewall);
	if (g->wwall.main || g->wwall.frm || g->wwall.frad || g->wwall.path)
		cb_imgdata_wipe(g, &g->wwall);
	if (g->mp.pov)
		mlx_destroy_image(g->mlx, g->mp.pov);
	g->mp.pov = NULL;
	return ;
}

void	cb_free_matrix(char **matrix)
{
	int	guide;

	if (!matrix)
		return ;
	guide = 0;
	while (matrix[guide])
	{
		free(matrix[guide]);
		guide++;
	}
	free(matrix);
}

void	cb_imgdata_wipe(t_game *g, t_img *i)
{
	if (i->main)
		mlx_destroy_image(g->mlx, i->main);
	if (i->frm)
		cb_free_img_matrix(g, i->frm);
	if (i->frad)
		free(i->frad);
	if (i->path)
		free(i->path);
	i->main = NULL;
	i->addr = NULL;
	i->frm = NULL;
	i->frad = NULL;
	i->path = NULL;
	return ;
}

static void	cb_free_img_matrix(t_game *g, void **matrix)
{
	int	guide;

	if (!matrix)
		return ;
	guide = 0;
	while (matrix[guide])
	{
		mlx_destroy_image(g->mlx, matrix[guide]);
		guide++;
	}
	free(matrix);
}
