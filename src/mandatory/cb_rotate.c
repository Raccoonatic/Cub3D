#include "../../inc/cb_main_header.h"

static void	cb_rotate_left(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!game->klft)
		return ;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(-rotate_speed)
		- game->player.dir.y * sin(-rotate_speed);
	game->player.dir.y = old_dir_x * sin(-rotate_speed)
		+ game->player.dir.y * cos(-rotate_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-rotate_speed)
		- game->player.plane_Y * sin(-rotate_speed);
	game->player.plane_Y = old_plane_x * sin(-rotate_speed)
		+ game->player.plane_Y * cos(-rotate_speed);
}

static void	cb_rotate_right(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!game->krgt)
		return ;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rotate_speed)
		- game->player.dir.y * sin(rotate_speed);
	game->player.dir.y = old_dir_x * sin(rotate_speed)
		+ game->player.dir.y * cos(rotate_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotate_speed)
		- game->player.plane_Y * sin(rotate_speed);
	game->player.plane_Y = old_plane_x * sin(rotate_speed)
		+ game->player.plane_Y * cos(rotate_speed);
}

void cb_rotate_player(t_game *game)
{
    double rotate_speed;

    rotate_speed = ROTSPD;
    cb_rotate_left(game, rotate_speed);
    cb_rotate_right(game, rotate_speed);
    return ;
}
