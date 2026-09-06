
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

void    cb_innit_player(t_game *game)
{
    t_player *player;

    cb_zero_player(player);
    cb_get_player_pos(game, player);
    game->player = player;
}