/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_define_playable_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:37:38 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/08 19:13:57 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static int	cb_is_border(char **map, int y, int x);
void		cb_define_playable_map(t_game *g, char **map);
static void	cb_upgrade_border(char **map, int *maxy, int *maxx);
static void	cb_mapdatafill(char **des, char **src, int miny, int minx);
static char	**cb_allocate_playable_map(char **map, int maxy, int maxx);

void	cb_define_playable_map(t_game *g, char **map)
{
	int	maxy;
	int	maxx;
	int	i;
	char dir;

	maxy = 0;
	maxx = 0;
	dir = g->map[g->player.y][g->player.x];
	cb_flood_fill(map, g->player.y, g->player.x);
	g->map[g->player.y][g->player.x] = dir;
	cb_upgrade_border(map, &maxy, &maxx);
	map = cb_allocate_playable_map(map, maxy, maxx);
	if (!map)
		cb_frexit(g, NULL, map, "Playable Area"NOR"Allocation Error");
	i = 0;
	while (map[i])
		i++;
	cb_mapdatafill(map, g->map, maxy - i + 1, maxx - ft_strlen(map[0]) + 1);
	cb_free_matrix(g->map);
	g->map = map;
	cb_get_player_pos(g, &g->player);
	return ;
}

static void	cb_mapdatafill(char **des, char **src, int miny, int minx)
{
	int	y;
	int	x;

	y = 0;
	while (des[y])
	{
		x = 0;
		while (des[y][x])
		{
			if (src[miny + y][minx + x] == 'F')
				des[y][x] = '0';
			else if (src[miny + y][minx + x] == '5')
				des[y][x] = '1';
			else if (!ft_strchr("10B", src[miny + y][minx + x]))
				des[y][x] = src[miny + y][minx + x];
			x++;
		}
		y++;
	}
	return ;
}

static char	**cb_allocate_playable_map(char **map, int maxy, int maxx)
{
	int	y;
	int	x;
	int	miny;
	int	minx;

	y = 0;
	miny = maxy;
	minx = maxx;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '5')
			{
				if (y < miny)
					miny = y;
				if (x < minx)
					minx = x;
			}
			x++;
		}
		y++;
	}
	return (cb_matrixalloc((maxy - miny) + 1, (maxx - minx) + 1, '1'));
}

static int	cb_is_border(char **map, int y, int x)
{
	int	i;
	int	j;

	i = y - 1;
	while (i <= y + 1)
	{
		if (i >= 0 && map[i])
		{
			j = x - 1;
			while (j <= x + 1)
			{
				if (j >= 0 && j < (int)ft_strlen(map[i])
					&& map[i][j] == 'F')
				{
					map[y][x] = '5';
					return (1);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}

static void	cb_upgrade_border(char **map, int *maxy, int *maxx)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				if (cb_is_border(map, y, x))
				{
					if (y > *maxy)
						*maxy = y;
					else if (x > *maxx)
						*maxx = x;
				}
			}
			x++;
		}
		y++;
	}
	return ;
}
