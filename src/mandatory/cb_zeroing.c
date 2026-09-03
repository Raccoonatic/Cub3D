<<<<<<< HEAD
<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_zeroing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:54:56 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/02 19:45:19 by lde-san-         ###   ########.fr       */
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
	game->h = 0;
	game->w = 0;
	game->flor_c = -1;
	game->ceil_c = -1;
	game->tstamp = cb_now();
	cb_zero_img(game);
	return ;
}

static void	cb_zero_img(t_game *game)
{
	cb_null_ptrs(&game->buf);
	cb_null_ptrs(&game->flor);
	cb_null_ptrs(&game->ceil);
	cb_null_ptrs(&game->minimap);
	cb_null_ptrs(&game->nwall);
	cb_null_ptrs(&game->swall);
	cb_null_ptrs(&game->ewall);
	cb_null_ptrs(&game->wwall);
	cb_zero_ints(&game->buf);
	cb_zero_ints(&game->flor);
	cb_zero_ints(&game->ceil);
	cb_zero_ints(&game->minimap);
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
=======
=======
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_zeroing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:54:56 by lde-san-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/09/01 16:40:03 by lde-san-         ###   ########.fr       */
=======
/*   Updated: 2026/09/02 19:45:19 by lde-san-         ###   ########.fr       */
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
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
	game->h = 0;
	game->w = 0;
<<<<<<< HEAD
=======
	game->flor_c = -1;
	game->ceil_c = -1;
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
	game->tstamp = cb_now();
	cb_zero_img(game);
	return ;
}

static void	cb_zero_img(t_game *game)
{
	cb_null_ptrs(&game->buf);
	cb_null_ptrs(&game->flor);
	cb_null_ptrs(&game->ceil);
	cb_null_ptrs(&game->minimap);
	cb_null_ptrs(&game->nwall);
	cb_null_ptrs(&game->swall);
	cb_null_ptrs(&game->ewall);
	cb_null_ptrs(&game->wwall);
	cb_zero_ints(&game->buf);
	cb_zero_ints(&game->flor);
	cb_zero_ints(&game->ceil);
	cb_zero_ints(&game->minimap);
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
<<<<<<< HEAD
>>>>>>> origin/rdeimaos
=======
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
