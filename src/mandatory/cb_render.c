/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:35:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/20 19:54:27 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int			cb_render(t_game *g);

int	cb_render(t_game *g)
{
	int		i;
	t_vd	ray_dir;

	cb_move_player(g);
	cb_rotate_player(g);
	cb_push_bkgrnd_to_frame(&g->buf, &g->bkg);
	i = 0;
	while (i < WW)
	{
		ray_dir.x = g->ply.dir.x + (g->ply.plne.x * ((i / (double)WW) * 2 - 1));
		ray_dir.y = g->ply.dir.y + (g->ply.plne.y * ((i / (double)WW) * 2 - 1));
		cb_castray(g, g->ply.ren, ray_dir, &(g->columns[i]));
		i++;
	}
	cb_render_walls(g);
	mlx_put_image_to_window(g->mlx, g->win, g->buf.main, 0, 0);
	mlx_do_sync(g -> mlx);
	return (0);
}
