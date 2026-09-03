/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 19:46:28 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static void dispmap(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	t_game game;

    if (ac != 2)
		cb_fail(2, 1, "Incorrect argument count.");
	cb_zeroing(&game);
	if (!cb_validate_map(cb_scene_to_map(&game, av[1]), &game))
		cb_fail(1, 1, "Invalid map.");
	if (!game.map)
		cb_fail(1, 1, "Failed to create map.");
	dispmap(&game);
	cb_frexit(&game, NULL, NULL, "Exiting program.");
	return (0);
}
