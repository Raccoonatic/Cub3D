/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_load_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:53:48 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/20 19:53:48 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static bool	cb_tex_to_img(t_game *g, t_img *tex)
{
	tex->main = mlx_xpm_file_to_image(g->mlx, tex->path, &tex->w, &tex->h);
	if (!tex->main)
		return (false);
	tex->addr = mlx_get_data_addr(tex->main, &tex->bpx, &tex->bpr, &tex->e);
	return (true);
}

bool	cb_load_textures(t_game *g)
{
	if (!cb_tex_to_img(g, &g->nwall))
	{
		printf("N failed: %s\n", g->nwall.path);
		return (false);
	}
	if (!cb_tex_to_img(g, &g->swall))
	{
		printf("S failed: %s\n", g->swall.path);
		return (false);
	}
	if (!cb_tex_to_img(g, &g->ewall))
	{
		printf("E failed: %s\n", g->ewall.path);
		return (false);
	}
	if (!cb_tex_to_img(g, &g->wwall))
	{
		printf("W failed: %s\n", g->wwall.path);
		return (false);
	}
	return (true);
}
