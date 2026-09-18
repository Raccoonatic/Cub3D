/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:34:30 by rdeimaos          #+#    #+#             */
/*   Updated: 2026/09/18 13:55:08 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void		move_player(t_game *game);
static void	cb_move_left(t_game *g, double mvspd, double *nwx, double *nwy);
static void	cb_move_right(t_game *g, double mvspd, double *nwx, double *nwy);
static void	cb_move_foward(t_game *g, double mvspd, double *nwx, double *nwy);
static void	cb_move_backward(t_game *g, double mvspd, double *nwx, double *nwy);

static void	cb_move_foward(t_game *g, double mvspd, double *nwx, double *nwy)
{
	double	new_new_x;
	double	new_new_y;

	if (!g->kw)
		return ;
	if (g->ply.dir.x < 0)
		g->looking = 'L';
	else
		g->looking = 'R';
	new_new_x = g->ply.ren.x + g->ply.dir.x * mvspd;
	new_new_y = g->ply.ren.y + g->ply.dir.y * mvspd;
	if (g->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*nwx = new_new_x;
		*nwy = new_new_y;
	}
	else
	{
		*nwx = g->ply.ren.x;
		*nwy = g->ply.ren.y;
	}
	return ;
}

static void	cb_move_backward(t_game *g, double mvspd, double *nwx, double *nwy)
{
	double	new_new_x;
	double	new_new_y;

	if (!g->ks)
		return ;
	if (g->ply.dir.x < 0)
		g->looking = 'L';
	else
		g->looking = 'R';
	new_new_x = g->ply.ren.x - g->ply.dir.x * mvspd;
	new_new_y = g->ply.ren.y - g->ply.dir.y * mvspd;
	if (g->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*nwx = new_new_x;
		*nwy = new_new_y;
	}
	else
	{
		*nwx = g->ply.ren.x;
		*nwy = g->ply.ren.y;
	}
	return ;
}

static void	cb_move_left(t_game *g, double mvspd, double *nwx, double *nwy)
{
	double	new_new_x;
	double	new_new_y;

	if (!g->ka)
		return ;
	if (g->ply.dir.x < 0)
		g->looking = 'L';
	else
		g->looking = 'R';
	new_new_x = g->ply.ren.x + g->ply.dir.y * mvspd;
	new_new_y = g->ply.ren.y - g->ply.dir.x * mvspd;
	if (g->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*nwx = new_new_x;
		*nwy = new_new_y;
	}
	else
	{
		*nwx = g->ply.ren.x;
		*nwy = g->ply.ren.y;
	}
	return ;
}

static void	cb_move_right(t_game *g, double mvspd, double *nwx, double *nwy)
{
	double	new_new_x;
	double	new_new_y;

	if (!g->kd)
		return ;
	if (g->ply.dir.x < 0)
		g->looking = 'L';
	else
		g->looking = 'R';
	new_new_x = g->ply.ren.x - g->ply.dir.y * mvspd;
	new_new_y = g->ply.ren.y + g->ply.dir.x * mvspd;
	if (g->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*nwx = new_new_x;
		*nwy = new_new_y;
	}
	else
	{
		*nwx = g->ply.ren.x;
		*nwy = g->ply.ren.y;
	}
	return ;
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	new_x;
	double	new_y;

	move_speed = MVMSPD;
	new_x = game->ply.ren.x;
	new_y = game->ply.ren.y;
	cb_move_foward(game, move_speed, &new_x, &new_y);
	cb_move_backward(game, move_speed, &new_x, &new_y);
	cb_move_left(game, move_speed, &new_x, &new_y);
	cb_move_right(game, move_speed, &new_x, &new_y);
	game->ply.ren.x = new_x;
	game->ply.ren.y = new_y;
	return ;
}
