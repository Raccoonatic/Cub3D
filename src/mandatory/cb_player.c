/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeimaos <rdeimaos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:34:36 by rdeimaos          #+#    #+#             */
/*   Updated: 2026/09/08 15:34:36 by rdeimaos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void    cb_innit_player(t_game *game);
static void cb_get_player_dir(t_player *player, char dir);
void cb_get_player_pos(t_game *game, t_player *player);

void cb_get_player_pos(t_game *game, t_player *player)
{
    char **map;
    int i;
    int j;

    map = game->map;
    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
            {
                player->x = j;
                player->y = i;
                player->ren_x = j + 0.5;
                player->ren_y = i + 0.5;
                cb_get_player_dir(player, map[i][j]);
                return ;
            }
            j++;
        }
        i++;
    }
    return ;
}

void    cb_innit_player(t_game *game)
{
    cb_zero_player(&game->player);
    cb_get_player_pos(game, &game->player);
}

static void cb_get_player_dir(t_player *player, char dir)
{
    if (dir == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1;
    }
    else if (dir == 'S')
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    else if (dir == 'E')
    {
        player->dir_x = 1;
        player->dir_y = 0;
    }
    else if (dir == 'W')
    {
        player->dir_x = -1;
        player->dir_y = 0;
    }
}
