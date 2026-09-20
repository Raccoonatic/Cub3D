/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:56:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/18 13:56:01 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header_bonus.h"

void		cb_innit_player(t_game *game);
static void	cb_camera_plane_init(t_player *player);
static void	cb_get_player_dir(t_player *player, char dir);
void		cb_get_player_pos(t_game *game, t_player *player);

void	cb_get_player_pos(t_game *game, t_player *player)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				player->map.x = j;
				player->map.y = i;
				player->ren.x = j + 0.5;
				player->ren.y = i + 0.5;
				cb_get_player_dir(player, game->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	cb_innit_player(t_game *game)
{
	cb_zero_player(&game->ply);
	cb_get_player_pos(game, &game->ply);
	cb_camera_plane_init(&game->ply);
	return ;
}

static void	cb_camera_plane_init(t_player *player)
{
	player->plne.x = (player->dir.y * -1) * FOV;
	player->plne.y = player->dir.x * FOV;
	return ;
}

static void	cb_get_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	return ;
}
