/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:35:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/08 19:22:02 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int	cb_render(t_game *g)
{
	cb_push_bkgrnd_to_frame(&g->buf, &g->bkg);
	cb_minimap_compose(g, &g->mp);
	mlx_put_image_to_window(g->mlx, g->win, g->buf.main, 0, 0);
	mlx_do_sync(g -> mlx);
	return (0);
}
