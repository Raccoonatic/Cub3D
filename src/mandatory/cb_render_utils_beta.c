/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_utils_beta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:24:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/13 18:29:39 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

double		cb_dist(t_vd *ply, t_vd *hit);
void		sl_clear_map_buffer(t_mp *mp);
void		cb_push_map_to_frame(t_img *dst, t_mp *src, t_cord c, char f);
static void	cb_draw_wall(t_game *g, int i);
static void	cb_draw_line(t_img *img, int x, int start, int end, int color);

void	cb_push_map_to_frame(t_img *dst, t_mp *src, t_cord c, char f)
{
	int     x;
	int     y;
	char    *d_ptr;
	char    *s_ptr;

	if (!dst || !src)
	    return ;
	y = 0;
	while (y < c.th)
	{
		x = 0;
		while (x < c.tw)
		{
			if (f == 'L')
				s_ptr = src->addr + (y * src->bpr) + ((c.tw - 1 - x) * 4);
			else
				s_ptr = src->addr + (y * src->bpr) + (x * 4);
			d_ptr = dst->addr + ((c.y + y) * dst->bpr) + ((c.x + x) * 4);
			if (*(unsigned int *)s_ptr != 0xFF00FF)
				*(unsigned int *)d_ptr = *(unsigned int *)s_ptr;
			x++;
		}
		y++;
	}
}

void	sl_clear_map_buffer(t_mp *mp)
{
	char		*end;
	char		*start;

	start = mp->addr;
	end = mp->addr + (mp->bpr * mp->h);
	while (start < end)
	{
		*(unsigned int *)start = mp->flor_color;
		start += (mp->bpx / 8);
	}
	return ;
}

double cb_dist(t_vd *ply, t_vd *hit)
{
	double	delta_x;
	double	delta_y;

	delta_x = hit->x - ply->x;
	delta_y = hit->y - ply->y;
	delta_x *= delta_x;
	delta_y *= delta_y;
	return (sqrt(delta_x + delta_y));
}

static void	cb_draw_wall(t_game *g, int i)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(g->h / g->perp_wall_dist);
	draw_start = -line_height / 2 + g->h / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + g->h / 2;
	if (draw_end >= g->h)
		draw_end = g->h - 1;
	cb_draw_line(&g->buf, i, draw_start, draw_end, 0x000000);
}

static void	cb_draw_line(t_img *img, int x, int start, int end, int color)
{
	char	*tmp;
	int		y;

	y = start;
	while (y <= end)
	{
		tmp = img->addr + (y * img->bpr) + (x * (img->bpx / 8));
		*(unsigned int *)tmp = color;
		y++;
	}
}


void    cb_raycast_render(t_game *g)
{
    int    i;
    double  cam_x;
    t_vd    ray_start;
    t_vd    ray_dir;
    t_vd    hit;

    i = 0;
    while (i < g->w)
    {
        cam_x = 2.0 * i / (double)g->w - 1;
        ray_start.x = g->player.ren.x;
        ray_start.y = g->player.ren.y;
        ray_dir.x = g->player.dir.x + g->player.plane_x * cam_x;
        ray_dir.y = g->player.dir.y + g->player.plane_Y * cam_x;
        if (cb_castray(g, ray_start, ray_dir, &hit))
            cb_draw_wall(g, i);
        i++;
    }
}
