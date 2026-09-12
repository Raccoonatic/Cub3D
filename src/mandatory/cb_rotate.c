/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:13:40 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 19:13:40 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void cb_rotate_left(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plne_x;

	if (!game->klft)
		return ;
	old_dir_x = game->ply.dir.x;
	old_plne_x = game->ply.plne.x;
	game->ply.dir.x = game->ply.dir.x * cos(rotate_speed * -1)
					- game->ply.dir.y * sin(rotate_speed * -1);
	game->ply.dir.y = old_dir_x * sin(rotate_speed * -1)
					+ game->ply.dir.y * cos(rotate_speed * -1);
	game->ply.plne.x = game->ply.plne.x * cos(rotate_speed * -1)
					- game->ply.plne.y * sin(rotate_speed * -1);
	game->ply.plne.y = old_plne_x * sin(rotate_speed * -1)
					+ game->ply.plne.y * cos(rotate_speed * -1);
	return ;
}

static void cb_rotate_right(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plne_x;

	if (!game->krgt)
		return ;
	old_dir_x = game->ply.dir.x;
	old_plne_x = game->ply.plne.x;
	game->ply.dir.x = game->ply.dir.x * cos(rotate_speed)
					- game->ply.dir.y * sin(rotate_speed);
	game->ply.dir.y = old_dir_x * sin(rotate_speed)
					+ game->ply.dir.y * cos(rotate_speed);
	game->ply.plne.x = game->ply.plne.x * cos(rotate_speed)
					- game->ply.plne.y * sin(rotate_speed);
	game->ply.plne.y = old_plne_x * sin(rotate_speed)
					+ game->ply.plne.y * cos(rotate_speed);
	return ;
}

void cb_rotate_player(t_game *game)
{
	double rotate_speed;

	rotate_speed = ROTSPD;
	cb_rotate_left(game, rotate_speed);
	cb_rotate_right(game, rotate_speed);
	return ;
}
