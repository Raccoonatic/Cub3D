/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_zeroing_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:54:35 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 21:19:48 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		cb_null_ptrs(t_img *i);
void		cb_zero_ints(t_img *i);
void		cb_zeroing(t_game *game);
static void	cb_zero_img(t_game *game);

void	cb_zeroing(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->h = WH;
	game->w = WW;
	game->flor_c = -1;
	game->ceil_c = -1;
	game->tstamp = cb_now();
	game->l = 'R';
	cb_zero_img(game);
	cb_zero_mp(&(game->mp));
	game->kw = false;
	game->ka = false;
	game->ks = false;
	game->kd = false;
	game->klft = false;
	game->krgt = false;

	return ;
}

static void	cb_zero_img(t_game *game)
{
	cb_null_ptrs(&game->bkg);
	cb_null_ptrs(&game->buf);
	cb_null_ptrs(&game->mp.map);
	cb_null_ptrs(&game->mp.ph);
	cb_null_ptrs(&game->nwall);
	cb_null_ptrs(&game->swall);
	cb_null_ptrs(&game->ewall);
	cb_null_ptrs(&game->wwall);
	cb_zero_ints(&game->buf);
	cb_zero_ints(&game->bkg);
	cb_zero_ints(&game->mp.map);
	cb_zero_ints(&game->mp.ph);
	cb_zero_ints(&game->nwall);
	cb_zero_ints(&game->swall);
	cb_zero_ints(&game->ewall);
	cb_zero_ints(&game->wwall);
	return ;
}

void	cb_null_ptrs(t_img *i)
{
	i->main = NULL;
	i->addr = NULL;
	i->path = NULL;
	i->frm = NULL;
	i->frad = NULL;
	return ;
}

void	cb_zero_ints(t_img *i)
{
	i->bpx = 0;
	i->bpr = 0;
	i->e = 0;
	i->h = 0;
	i->w = 0;
	i->fbpx = 0;
	i->fbpr = 0;
	i->fe = 0;
	i->mx_index = 0;
	i->crnt_frm = 0;
	return ;
}
