/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:48:46 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/07 15:59:26 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_fail(int errn, int code, const char *msg);
void	cb_kill_the_game(t_game *gm, int flag, int errn, int code);
void	cb_frexit(t_game *g, char *str, char **mtrx, const char *msg);

void	cb_fail(int errn, int code, const char *msg)
{
	if (errn != 0)
		rprint(2, BLD"Error\n"RST);
	if (errn == 1)
		rprint(2, PUR"%e %s\n"RST, "nope", msg);
	if (errn == 2)
	{
		rprint(2, PUR"%e %s\n"RST, "nope", msg);
		rprint(1, BBY"Usage: "MNT"./cub3D "NOR"path_to/map"LME".cub\n"RST);
	}
	if (errn == 0)
		rprint(2, LME"%e The Verdant Veil Perseveres! %s\n"RST, "yep", msg);
	rprint(1, RST);
	exit(code);
}

void	cb_frexit(t_game *g, char *str, char **mtrx, const char *msg)
{
	cb_frink(g);
	if (str)
		free(str);
	if (mtrx)
		cb_free_matrix(mtrx);
	cb_fail(1, 1, msg);
}

void	cb_kill_the_game(t_game *gm, int flag, int errn, int code)
{
	if (!gm->mlx)
		cb_fail(1, errn, "Game didn't load. "NOR"mlx failed"RST);
	if (gm->win)
		mlx_destroy_window(gm->mlx, gm->win);
	cb_frink(gm);
	mlx_destroy_display(gm->mlx);
	free(gm->mlx);
	cb_free_matrix(gm->map);
	if (flag == 1)
		cb_fail(errn, code, MNT"Game Over. "NOR"Thanks 4 playing"RST);
	else
	{
		if (errn == 2)
			cb_fail(1, code, "Game didn't load. "NOR"mlx_init Failed"RST);
		if (errn == 3)
			cb_fail(1, code, "Game didn't load. "NOR"mlx_img failed"RST);
	}
	cb_fail(1, code, "Memory allocation error"RST);
	return ;
}
