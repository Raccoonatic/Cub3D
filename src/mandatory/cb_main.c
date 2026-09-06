/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/06 14:06:01 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void dispmap(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf(MNT"%c", map[i][j]);
			else if (map[i][j] == '0')
				printf(PUR"%c", map[i][j]);
			else if (map[i][j] == 'B')
				printf(NAV"%c", map[i][j]);
			else if (ft_strchr("NSWE", map[i][j]))
				printf(BBY"%c", map[i][j]);
			else
				printf(BLD"%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(RST"\n");
	return ;
}

int main(int ac, char **av)
{
	t_game game;
	char	**map;

    if (ac != 2)
		cb_fail(2, 1, "Incorrect argument count.");
	cb_zeroing(&game);
	map = cb_scene_to_map(&game, av[1]);
	dispmap(map);
	if (!cb_validate_map(map, &game))
		cb_fail(1, 1, "Invalid map.");
	if (!game.map)
		cb_fail(1, 1, "Failed to create map.");
	dispmap(game.map);
	cb_frexit(&game, NULL, NULL, "Exiting program.");
	return (0);
}
