/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/01 17:16:44 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"



char	**cb_scene_to_map(char *map_path)
{
	char	**map;
	int		rows;
	int		fd;

	if (ft_strlen(map_path) <= 4)
		cb_fail(1, 2, "Map name incomplete. "NOR"Is empty or without .cub");
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		cb_fail(1, 2, "Map extension must be "LME".cub");
	rows = cb_count_lines(map_path);
	if (rows < 3)
		cb_fail(1, 2, "Map is too tiny."BABY" File has less than 3 rows");
	fd = open(map_path, O_RDONLY);
	if (fd < 3)
		cb_fail(1, 2, "Failed to "BABY"open "PURP"map file on "B_WI"READ");
	map = ft_calloc((rows + 1), sizeof(char *));
	if (!map)
		cb_fail(1, 2, "Memory allocation failed on "B_WI" conversion");
	return (cb_map_populate(map, fd, rows));
}

int main(int ac, char **av)
{
	t_game game;

    if (ac != 2)
		cb_fail(2, 2, "Incorrect argument count.");
	cb_zeroing(&game);
	game.map = cb_check_map(cb_scene_to_map(av[1]), &game);
    //just checking if the file in the parameter is a .cub or not
    if(!ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
    {
        printf("Error\nPlease provide a .cub file\n");
        return (1);
    }
    //cheecking if the file can be opened
    if (open(av[1], O_RDONLY) == -1)
    {
        printf("Error\nCould't open the file\n");
        return(1);
    }
    //i've put this check in the main but it is better to have a function for that. the main function is going to be 25+lines if we do everything here
}
