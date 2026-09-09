#include "../../inc/cb_main_header.h"

static void cb_rotate_left(t_game *game, double rotate_speed)
{
    double old_dir_x;

	if (!game->klft)
		return ;
    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(-rotate_speed) - game->player.dir_y * sin(-rotate_speed);
    game->player.dir_y = old_dir_x * sin(-rotate_speed) + game->player.dir_y * cos(-rotate_speed);
    return ;
}

static void cb_rotate_right(t_game *game, double rotate_speed)
{
    double old_dir_x;

	if (!game->krgt)
		return ;
    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(rotate_speed) - game->player.dir_y * sin(rotate_speed);
    game->player.dir_y = old_dir_x * sin(rotate_speed) + game->player.dir_y * cos(rotate_speed);
    return ;
}

void cb_rotate_player(t_game *game)
{
    double rotate_speed;

    rotate_speed = 0.008;
    cb_rotate_left(game, rotate_speed);
    cb_rotate_right(game, rotate_speed);
    return ;
}
