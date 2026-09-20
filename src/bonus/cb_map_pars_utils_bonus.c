/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_pars_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:54:45 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/18 13:54:45 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header_bonus.h"

int		cb_dispmap(char **map);
int		cb_map_width(char **map);
int		cb_map_height(char **map);
void	cb_get_mapsize(t_game *g, t_mp *mp);
int		cb_check_surr(char **map, int i, int j);

int	cb_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	cb_map_width(char **map)
{
	int	i;

	i = ft_strlen(map[0]);
	return (i);
}

int	cb_check_surr(char **map, int i, int j)
{
	if (map[i - 1][j] == 'B' || map[i + 1][j] == 'B'
		|| map[i][j - 1] == 'B' || map[i][j + 1] == 'B')
		return (0);
	return (1);
}

int	cb_dispmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				rprint(1, MNT"%c", map[i][j]);
			else if (map[i][j] == '0')
				rprint(1, PUR"%c", map[i][j]);
			else if (map[i][j] == 'B')
				rprint(1, NAV"%c", map[i][j]);
			else if (ft_strchr("NSWE", map[i][j]))
				rprint(1, BBY"%c", map[i][j]);
			else
				rprint(1, BLD"%c", map[i][j]);
			j++;
		}
		rprint(1, RST"\n");
		i++;
	}
	return (rprint(1, RST"\n"), 0);
}

void	cb_get_mapsize(t_game *g, t_mp *mp)
{
	int	guide;

	mp->map.w = TSZ * ft_strlen(g->map[0]);
	guide = 0;
	while (g->map[guide])
		guide++;
	mp->map.h = TSZ * guide;
	if (mp->w > mp->map.w)
		mp->w = mp->map.w;
	if (mp->h > mp->map.h)
		mp->h = mp->map.h;
	return ;
}
