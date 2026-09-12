/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_utils_beta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:24:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 23:21:41 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	sl_clear_map_buffer(t_mp *mp);
void	cb_push_map_to_frame(t_img *dst, t_mp *src, t_cord c, char f);

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
