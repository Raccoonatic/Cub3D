/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scenetomap_utils_beta.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:03:36 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 11:03:59 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

char	**cb_matrixalloc(int columns, int rows);
void	cb_map_populate(char **raw, char **dest, int miny, int maxy);

char	**cb_matrixalloc(int columns, int rows)
{
	char	**ret;
	int		guide;
	int		death;

	ret = ft_calloc(columns + 1, sizeof(char *));
	if (!ret)
		return (NULL);
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
		ft_memset(ret[guide], 'B', rows);
		guide++;
	}
	return (ret);
}

void	cb_map_populate(char **raw, char **dest, int miny, int maxy)
{
	int i;
	int j;

	i = 0;
	while ((miny + i) < maxy)
	{
		j = 0;
		while (raw[miny + i][j])
		{
			if (raw[miny + i][j] != ' ')
				dest[i][j] = raw[miny + i][j];
			j++;
		}
		i++;
	}
	return ;
}
