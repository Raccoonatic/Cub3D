/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:53:03 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 12:53:03 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static int cb_check_content(char **map)
{
    printf("Checking map content...\n");
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] != '1'&& map[i][j] != 'B' && map[i][j] != '0'
                    && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
                return (0);
            j++;
        }
        i++;
    }
    printf("Map content is valid\n");
    return (1);
}

static int cb_check_walls(char **map, int size, int len)
{
    printf("Checking map walls...\n");
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][0] != '1' && map[i][0] != 'B')
                return 0;
            if(map[i][len - 1] != '1' && map[i][len - 1] != 'B')
                return 0;
            if(map[0][j] != '1' && map[0][j] != 'B')
                return 0;
            if(map[size - 1][j] != '1' && map[size - 1][j] != 'B')
                return 0;
            j++;
        }
        i++;
    }
     printf("Map walls are valid\n");
    return (1);
}

static int cb_validate_player(char **map)
{
    printf("Validating player position...\n");
    int i;
    int j;
    int player_count;

    i = 0;
    player_count = 0;

    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                player_count++;
            j++;
        }
        i++;
    }
    if(player_count != 1)
        return (0);
    printf("Player position is valid\n");
    return (1);
}

static int cb_validate_content(char **map)
{
    printf("Validating map content...\n");
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                if(!cb_check_surr(map, i, j))
                    return (0);
            }
            j++;
        }
        i++;
    }
    printf("Map content is valid\n");
    return (1);
}

int cb_validate_map(char **map, t_game *game)
{
    int size;
    int len;

    size = cb_map_height(map);
    len = cb_map_width(map);
    if(!cb_check_content(map))
    {
        cb_fail(1, 1, "Map contains invalid characters");
        return (0);
    }
    if(!cb_check_walls(map, size, len) || !cb_validate_content(map))
    {
        cb_fail(1, 1, "Map is not surrounded by walls");
        return (0);
    }
    if(!cb_validate_player(map))
    {
        cb_fail(1, 1, "Map must contain exactly one player starting position");
        return (0);
    }
    printf("Map validation successful\n");
	game->map = map;
    return (1);
}
