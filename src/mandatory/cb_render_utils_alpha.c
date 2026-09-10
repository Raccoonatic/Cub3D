/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_utils_alpha.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:32:42 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/09 19:26:44 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static int	cb_colorshift(int c);
void		cb_blackpink(t_img *img, int h, int pink);
void		cb_push_bkgrnd_to_frame(t_img *d, t_img *s);
void		cb_push_tile_to_frame(t_img *dst, t_img *src, t_cord c, char f);

void	cb_push_tile_to_frame(t_img *dst, t_img *src, t_cord c, char f)
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
			if (*(unsigned int *)s_ptr != 0x00FF00FF)
				*(unsigned int *)d_ptr = *(unsigned int *)s_ptr;
			x++;
		}
		y++;
	}
}

void	cb_push_bkgrnd_to_frame(t_img *d, t_img *s)
{
	int		max_w;
	int		max_h;
	char	*d_ptr;
	char	*s_ptr;

	max_h = d->h;
	if (d->h > s->h)
		max_h = s->h;
	max_h--;
	while (max_h >= 0)
	{
		max_w = d->w;
		if (d->w > s->w)
			max_w = s->w;
		max_w--;
		while (max_w >= 0)
		{
			d_ptr = d->addr + (max_h * d->bpr) + (max_w * (d->bpx / 8));
			s_ptr = s->addr + (max_h * s->bpr) + (max_w * (s->bpx / 8));
			*(unsigned int *)d_ptr = *(unsigned int *)s_ptr;
			max_w--;
		}
		max_h--;
	}
}

static int	cb_colorshift(int c)
{
	int r;
	int g;
	int b;
	int v_shift;

	v_shift = 10;
	if (c == 0x00FF00FF || c == (int)MNMWC || c < 0 )
		return (0x00FF00FF);
	r = ((c >> 16) & 0xFF) + v_shift;
	g = ((c >> 8) & 0xFF) + v_shift;
	b = (c & 0xFF) + v_shift;
	if ((r - v_shift) > (127))
		r -= (v_shift * 2);
	if ((g - v_shift) > (127))
		g -= (v_shift * 2);
	if ((b - v_shift) > (127))
		b -= (v_shift * 2);
	return ((r << 16) | (g << 8) | b);
}

void	cb_blackpink(t_img *img, int h, int pink)
{
	char	*end;
	char	*start;

	pink = cb_colorshift(pink);
	start = img->addr;
	end = (img->addr) + (img->bpr * h);
	while (start < end)
	{
		if (*(unsigned int *)start == 0x00000000)
			*(unsigned int *)start = pink;
		start += (img->bpx / 8);
	}
	return ;
}
