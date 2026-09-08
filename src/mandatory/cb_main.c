/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/08 19:21:57 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void dispmap(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf(MNT"%c", map[i][j]);
			else if (map[i][j] == '0')
				printf(PUR"%c", map[i][j]);
			else if (map[i][j] == 'B')
				printf(NAV"%c", map[i][j]);
			else if (ft_strchr("NSWE", map[i][j]))
				printf(BBY"%c", map[i][j]);
			else
				printf(BLD"%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(RST"\n");
	return ;
}


static int	cb_handle_close(t_game *data)
{
	cb_kill_the_game(data, 1, 0, 0);
	return (0);
}

static int	cb_handle_keypress(int keycode, t_game *data)
{
	if (keycode == K_ESC)
		cb_kill_the_game(data, 1, 0, 0);
	move_player(data, keycode);
	return (0);
}

static void	cb_game_init(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		cb_kill_the_game(g, 0, 1, 1);
	g->win = mlx_new_window(g->mlx, g->w, g->h, (char *)"Verdant Veil");
	if (!g->win)
		cb_kill_the_game(g, 0, 1, 1);
	cb_layer_init(g, &g->buf.bpx, &g->buf.bpr, &g->buf.e);
	return ;
}

int main(int ac, char **av)
{
	t_game game;
	char	**map;

    if (ac != 2)
		cb_fail(2, 1, "Incorrect argument count.");
	cb_zeroing(&game);
	map = cb_scene_to_map(&game, av[1]);
	printf("Map loaded successfully\n");
	dispmap(map);
	printf("Map displayed successfully\n");
	printf("validating map...\n");
	if (!cb_validate_map(map, &game))
		cb_fail(1, 1, "Invalid map.");
	if (!game.map)
		cb_fail(1, 1, "Failed to create map.");
	dispmap(game.map);
	cb_innit_player(&game);
	cb_define_playable_map(&game, map);
	dispmap(game.map);
	// -- Post map init:

	cb_game_init(&game);
	mlx_hook(game.win, 17, 1L << 0, cb_handle_close, &game);
	mlx_hook(game.win, 2, 1L << 0, cb_handle_keypress, &game);
	mlx_loop_hook(game.mlx, cb_render, &game);
	mlx_loop(game.mlx);

	// -- For testing:
	cb_frink(&game);
	cb_free_matrix(game.map);
	cb_fail(0, 0, PUR"Exiting program.");
	return (0);
}
