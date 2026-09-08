/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:35:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/08 01:11:08 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void cb_get_player_pos(t_game *game, t_player *player)
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
                player->dir = map[i][j];
                return ;
            }
            j++;
        }
        i++;
    }
    return ;
}

int	cb_render(t_game *g)
{
	cb_get_player_pos(g, &g->ply);
	cb_push_bkgrnd_to_frame(&g->buf, &g->bkg);
	cb_minimap_compose(g, &g->mp);
	mlx_put_image_to_window(g->mlx, g->win, g->buf.main, 0, 0);
	mlx_do_sync(g -> mlx);
	return (0);
}
