/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/18 13:54:31 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void	cb_game_init(t_game *g);
static int	cb_doclose(t_game *data);
static int	cb_dokeyup(int keycode, t_game *data);
static int	cb_dokeydow(int keycode, t_game *data);

int	main(int ac, char **av)
{
	t_game	g;
	char	**map;

	if (ac != 2)
		cb_fail(2, 1, "Incorrect argument count.");
	cb_zeroing(&g);
	map = cb_scene_to_map(&g, av[1]);
	if (!cb_validate_map(map, &g))
		cb_fail(1, 1, "Invalid map.");
	if (!g.map)
		cb_fail(1, 1, "Failed to create map.");
	dispmap(g.map);
	cb_innit_player(&g);
	cb_define_playable_map(&g, map);
	dispmap(g.map);
	cb_game_init(&g);
	mlx_hook(g.win, 17, 1L << 0, (int (*)(void))(void (*)(void))cb_doclose, &g);
	mlx_hook(g.win, 2, 1L << 0, (int (*)(void))(void (*)(void))cb_dokeydow, &g);
	mlx_hook(g.win, 3, 1L << 1, (int (*)(void))(void (*)(void))cb_dokeyup, &g);
	mlx_loop_hook(g.mlx, (int (*)(void))(void (*)(void))cb_render, &g);
	mlx_loop(g.mlx);
	cb_frink(&g);
	cb_free_matrix(g.map);
	cb_fail(0, 0, PUR"Exiting program.");
	return (0);
}

static int	cb_doclose(t_game *data)
{
	cb_kill_the_game(data, 1, 0, 0);
	return (0);
}

static int	cb_dokeydow(int keycode, t_game *data)
{
	if (keycode == K_ESC)
		cb_kill_the_game(data, 1, 0, 0);
	else if (keycode == K_A)
		data->ka = true;
	else if (keycode == K_D)
		data->kd = true;
	else if (keycode == K_W)
		data->kw = true;
	else if (keycode == K_S)
		data->ks = true;
	else if (keycode == K_LFT)
		data->klft = true;
	else if (keycode == K_RGT)
		data->krgt = true;
	return (0);
}

static int	cb_dokeyup(int keycode, t_game *data)
{
	if (keycode == K_W)
		data->kw = false;
	else if (keycode == K_S)
		data->ks = false;
	else if (keycode == K_A)
		data->ka = false;
	else if (keycode == K_D)
		data->kd = false;
	else if (keycode == K_LFT)
		data->klft = false;
	else if (keycode == K_RGT)
		data->krgt = false;
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
	if (!cb_load_textures(g))
		cb_kill_the_game(g, 0, 3, 1);
	cb_layer_init(g, &g->buf.bpx, &g->buf.bpr, &g->buf.e);
	return ;
}
