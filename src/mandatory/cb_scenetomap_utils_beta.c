/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scenetomap_utils_beta.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:03:36 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/09 18:05:39 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_flood_fill(char **map, int y, int x);
char	**cb_matrixalloc(int columns, int rows, int c);
void	cb_map_populate(char **raw, char **dest, int miny, int minx);

char	**cb_matrixalloc(int columns, int rows, int c)
{
	char	**ret;
	int		guide;
	int		death;

	ret = ft_calloc(columns + 1, sizeof(char *));
	guide = 0;
	while (guide < columns)
	{
		ret[guide] = ft_calloc(rows + 1, sizeof(char));
		if (!ret[guide])
		{
			death = 0;
			while (death < guide)
			{
				free(ret[death]);
				death++;
			}
			return (free(ret), NULL);
		}
		ft_memset(ret[guide], c, rows);
		guide++;
	}
	ret[guide] = NULL;
	return (ret);
}

void	cb_map_populate(char **raw, char **dest, int miny, int minx)
{
	int i;
	int j;

	i = 0;
	while (dest[i] && raw[miny + i])
	{
		j = 0;
		while (dest[i][j] && raw[miny + i][minx + j])
		{
			if (!ft_strchr("\n\r ", raw[miny + i][minx + j]))
				dest[i][j] = raw[miny + i][minx + j];
			j++;
		}
		i++;
	}
	return ;
}

void	cb_flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	cb_flood_fill(map, y, x + 1);
	cb_flood_fill(map, y, x - 1);
	cb_flood_fill(map, y + 1, x);
	cb_flood_fill(map, y - 1, x);
	return ;
}
