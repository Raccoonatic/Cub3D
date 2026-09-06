/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getborders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:51:16 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/06 14:06:03 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void cb_get_max_len(char **raw, int maxy, int *max_len)
{
	int	y;

	y = 0;
	*max_len = 0;
	while (y <= maxy && raw[y])
	{
		if (ft_strlen(raw[y]) > (size_t)(*max_len))
			*max_len = ft_strlen(raw[y]);
		y++;
	}
	return ;
}

static void	cb_find_maxx(char **raw, int minx, int maxy, int *maxx)
{
	int max_len;
	int y;
	bool is_blank;

	cb_get_max_len(raw, maxy, &max_len);
	while (minx < max_len)
	{
		is_blank = true;
		y = 0;
		while (y <= maxy && raw[y])
		{
			if ((size_t)minx < ft_strlen(raw[y]) && !ft_isspace(raw[y][minx]))
			{
				is_blank = false;
				break;
			}
			y++;
		}
		*maxx = minx;
		if (is_blank)
			return ;
		minx++;
	}
	*maxx = max_len;
	return ;
}

static void	cb_find_minx(char **raw, int miny, int maxy, int *minx)
{
	int column;

	column = 0;
	while(raw[miny][column] && ft_isspace(raw[miny][column]))
		column++;
	*minx = column;
	while (++miny <= maxy)
	{
		column = 0;
		while(raw[miny][column] && ft_isspace(raw[miny][column]))
			column++;
		if (column < *minx)
			*minx = column;
	}
	return;
}

static void	cb_find_maxy(char **raw, int miny, int *maxy)
{
	char *trav;

	trav = cb_skip_blank(raw[miny]);
	while(*trav)
	{
		miny++;
		if (raw[miny])
			trav = cb_skip_blank(raw[miny]);
		else
		 	break ;
	}
	*maxy = miny - 1;
	return ;
}

int	cb_define_borders(char **raw, int *maxy, int *minx, int *maxx)
{
	int		miny;
	char	*trav;

	miny = 0;
	trav = cb_skip_blank(raw[miny]);
	while(!*trav)
	{
		miny++;
		trav = cb_skip_blank(raw[miny]);
	}
	if (!raw[miny])
		return (-1);
	cb_find_maxy(raw, miny, maxy);
	cb_find_minx(raw, miny, *maxy, minx);
	cb_find_maxx(&raw[miny], *minx, *maxy, maxx);
	return (miny);
}
