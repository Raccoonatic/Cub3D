#include "../../inc/cb_main_header.h"

static void	cb_draw_wall(t_game *g, int i);
static void	cb_draw_line(t_img *img, int x, int start, int end, int color);

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