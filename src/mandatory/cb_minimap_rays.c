/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_minimap_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:03:18 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 21:19:58 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int		cb_get_ray_color(t_game *g);

static void cb_put_mmap_pixel(t_game *g, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= g->mp.w || y >= g->mp.h)
        return ;
    dst = g->mp.addr + (y * g->mp.bpr) + (x * (g->mp.bpx / 8));
    *(unsigned int *)dst = color;
    return ;
}

static void cb_bresenham_loop(t_game *g, t_vi start, t_vi end, t_line line)
{
	int     err_twice;

	while (true)
	{
		cb_put_mmap_pixel(g, start.x, start.y, g->mp.ray_color);
		if (start.x == end.x && start.y == end.y)
			break ;
		err_twice = 2 * line.err;
		if (err_twice >= line.len.y)
		{
			line.err += line.len.y;
			start.x += line.step.x;
		}
		if (err_twice <= line.len.x)
		{
			line.err += line.len.x;
			start.y += line.step.y;
		}
	}
	return ;
}

void	cb_draw_ray_minimap(t_game *g, t_vd hit)
{
	t_vi	start;
	t_vi	end;
	t_line	line;

	start.x = (int)((g->ply.ren.x * TSZ) - g->mp.x);
	start.y = (int)((g->ply.ren.y * TSZ) - g->mp.y);
	end.x = (int)((hit.x * TSZ) - g->mp.x);
	end.y = (int)((hit.y * TSZ) - g->mp.y);
	line.len.x = abs(end.x - start.x);
	line.len.y = abs(end.y - start.y) * -1;
	if (start.x < end.x)
		line.step.x = 1;
	else
		line.step.x = -1;
	if (start.y < end.y)
		line.step.y = 1;
	else
		line.step.y = -1;
	line.err = line.len.x + line.len.y;
	cb_bresenham_loop(g, start, end, line);
	return ;
}

int cb_get_ray_color(t_game *g)
{
	int color;

	color = cb_colorshift(g->ceil_c);
	if (g->flor_c == g->ceil_c || g->flor_c == color)
	{
		if (g->flor_c == 0x000000)
		{
			if (MNMWC == 0xFFFFFF)
				return (0xFF0000);
			return (0xFFFFFF);
		}
		else
		{
			if (MNMWC == 0xFFFFFF)
				return (0x000000);
			return (0xFFFFFF);
		}
	}
	return (color);
}
