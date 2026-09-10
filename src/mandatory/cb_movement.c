/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:34:30 by rdeimaos          #+#    #+#             */
/*   Updated: 2026/09/08 15:34:30 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void cb_move_foward(t_game *game, double move_speed, double *new_x, double *new_y)
{
	double new_new_x;
	double new_new_y;

	if (!game->kw)
		return ;
	new_new_x = game->player.ren_x + game->player.dir_x * move_speed;
	new_new_y = game->player.ren_y + game->player.dir_y * move_speed;

	if (game->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*new_x = new_new_x;
		*new_y = new_new_y;
	}
	else
	{
		*new_x = game->player.ren_x;
		*new_y = game->player.ren_y;
	}
	return ;
}

static void cb_move_backward(t_game *game, double move_speed, double *new_x, double *new_y)
{
	double new_new_x;
	double new_new_y;

	if (!game->ks)
		return ;
	new_new_x = game->player.ren_x - game->player.dir_x * move_speed;
	new_new_y = game->player.ren_y - game->player.dir_y * move_speed;

	if (game->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*new_x = new_new_x;
		*new_y = new_new_y;
	}
	else
	{
		*new_x = game->player.ren_x;
		*new_y = game->player.ren_y;
	}
	return ;
}

static void cb_move_left(t_game *game, double move_speed, double *new_x, double *new_y)
{
	double new_new_x;
	double new_new_y;

	if (!game->ka)
		return ;
	new_new_x = game->player.ren_x + game->player.dir_y * move_speed;
	new_new_y = game->player.ren_y - game->player.dir_x * move_speed;

	if (game->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*new_x = new_new_x;
		*new_y = new_new_y;
	}
	else
	{
		*new_x = game->player.ren_x;
		*new_y = game->player.ren_y;
	}
	return ;
}

static void cb_move_right(t_game *game, double move_speed, double *new_x, double *new_y)
{
	double new_new_x;
	double new_new_y;

	if (!game->kd)
		return ;
	new_new_x = game->player.ren_x - game->player.dir_y * move_speed;
	new_new_y = game->player.ren_y + game->player.dir_x * move_speed;

	if (game->map[(int)new_new_y][(int)new_new_x] != '1')
	{
		*new_x = new_new_x;
		*new_y = new_new_y;
	}
	else
	{
		*new_x = game->player.ren_x;
		*new_y = game->player.ren_y;
	}
	return ;
}

void    move_player(t_game *game)
{
	double move_speed;
	double new_x;
	double new_y;

	move_speed = 0.03;
	new_x = game->player.ren_x;
	new_y = game->player.ren_y;
	cb_move_foward(game, move_speed, &new_x, &new_y);
	cb_move_backward(game, move_speed, &new_x, &new_y);
	cb_move_left(game, move_speed, &new_x, &new_y);
	cb_move_right(game, move_speed, &new_x, &new_y);
	game->player.ren_x = new_x;
	game->player.ren_y = new_y;
	return ;
}
