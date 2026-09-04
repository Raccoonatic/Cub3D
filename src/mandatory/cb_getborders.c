/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getborders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:51:16 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/04 01:04:56 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void	cb_find_maxx(char **raw, int miny, int maxy, int *maxx)
{
	int column;

	column = 0;
	while(raw[miny][column] && ft_isspace(raw[miny][column]))
		column++;
	while(raw[miny][column] && !ft_isspace(raw[miny][column]))
		column++;
	*maxx = column;
	while (++miny <= maxy)
	{
		column = 0;
		while(raw[miny][column] && ft_isspace(raw[miny][column]))
			column++;
		while(raw[miny][column] && !ft_isspace(raw[miny][column]))
			column++;
		if (column > *maxx)
			*maxx = column;
	}
	return;
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
	cb_find_maxx(raw, miny, *maxy, maxx);
	return (miny);
}
