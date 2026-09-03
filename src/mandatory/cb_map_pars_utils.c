/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_pars_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:50:11 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 12:50:11 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int cb_map_height(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return (i);
}
int cb_map_width(char **map)
{
    int i;

    i = ft_strlen(map[0]);
    return (i);
}

int cb_check_surr (char **map, int i, int j)
{
    if(map[i - 1][j] == 'B' || map[i + 1][j] == 'B' || map[i][j - 1] == 'B' || map[i][j + 1] == 'B')
        return (0);
    return (1);
}
