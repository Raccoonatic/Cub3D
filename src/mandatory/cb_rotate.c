#include "../../inc/cb_main_header.h"

static void cb_rotate_left(t_game *game, double rotate_speed)
{
    double old_dir_x;

    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(-rotate_speed) - game->player.dir_y * sin(-rotate_speed);
    game->player.dir_y = old_dir_x * sin(-rotate_speed) + game->player.dir_y * cos(-rotate_speed);
    return ;
}

static void cb_rotate_right(t_game *game, double rotate_speed)
{
    double old_dir_x;

    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(rotate_speed) - game->player.dir_y * sin(rotate_speed);
    game->player.dir_y = old_dir_x * sin(rotate_speed) + game->player.dir_y * cos(rotate_speed);
    return ;
}

void cb_rotate_player(t_game *game, int key)
{
    double rotate_speed;

    rotate_speed = 0.1;
    if (key == K_LFT)
        cb_rotate_left(game, rotate_speed);
    else if (key == K_RGT)
        cb_rotate_right(game, rotate_speed);
    return ;
}

