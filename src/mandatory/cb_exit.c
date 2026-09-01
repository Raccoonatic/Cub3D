/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:13:48 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/01 16:40:04 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_fail(int errn, int code, const char *msg);
void	cb_kill_the_game(t_game *gm, int flag, int errn, int code);

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
		cb_fail(0, 69, BLD"Game Over. "NOR"You is dead boy"RST);
	else
	{
		if (errn == 2)
			cb_fail(1, code, "Game didn't load. "NOR"mlx init Failed"RST);
		if (errn == 2)
			cb_fail(1, code, "Game didn't load. "NOR"mlx failed"RST);
	}
	cb_fail(1, code, "Memory allocation error"RST);
	return ;
}
