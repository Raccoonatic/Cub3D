/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scenetomap_utils_alpha.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:38:18 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/09 18:05:39 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

char		*cb_skip_blank(char *line);
static int	cb_check_missing_data(t_game *g);
char		**cb_addline(char **raw_map, char **line);
int			cb_scene_data_fill(t_game *g,char **line, int fd);
static int	cb_get_data(t_game *g, char *cursor, char *line, int fd);

char **cb_addline(char **raw_map, char **line)
{
	static int	raw_lines = 0;
	char		**ret;
	int			guide;

	raw_lines++;
	ret = ft_calloc(raw_lines + 1, sizeof(char *));
	if (!ret)
		return (cb_free_matrix(raw_map), NULL);
	guide = 0;
	if (raw_map)
	{
		while (raw_map[guide])
		{
			ret[guide] = ft_strdup(raw_map[guide]);
			if (!ret[guide])
				return (cb_free_matrix(ret), cb_free_matrix(raw_map), NULL);
			guide++;
		}
	}
	ret[guide] = ft_strdup(*line);
	if (!ret[guide])
		return (cb_free_matrix(ret), cb_free_matrix(raw_map), NULL);
	cb_free_matrix(raw_map);
	return(ret);
}

int	cb_scene_data_fill(t_game *g, char **line, int fd)
{
	char *cursor;

	cursor = NULL;
	while (line && *line)
	{
		cursor = cb_skip_blank(*line);
		if (cursor && *cursor)
		{
			if(cb_get_data(g, cursor, *line, fd))
				break;
		}
		free(*line);
		*line = get_next_line(fd);
	}
	return (cb_check_missing_data(g));
}

char	*cb_skip_blank(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (line);
		line++;
	}
	return (line);
}

static int	cb_get_data(t_game *g, char *cursor, char *line, int fd)
{
	if (*cursor == 'N' && *(cursor + 1) == 'O' && *(cursor + 2))
		return (cb_get_north(g, cursor + 2, line, fd));
	if (*cursor == 'S' && *(cursor + 1) == 'O' && *(cursor + 2))
		return (cb_get_south(g, cursor + 2, line, fd));
	if (*cursor == 'W' && *(cursor + 1) == 'E' && *(cursor + 2))
		return (cb_get_westh(g, cursor + 2, line, fd));
	if (*cursor == 'E' && *(cursor + 1) == 'A' && *(cursor + 2))
		return (cb_get_easth(g, cursor + 2, line, fd));
	if (*cursor == 'F' && *(cursor + 1))
		return (cb_get_flor(g, cursor + 1, line, fd));
	if (*cursor == 'C' && *(cursor + 1))
		return (cb_get_ceil(g, cursor + 1, line, fd));
	return (1);
}

static int	cb_check_missing_data(t_game *g)
{
	if (!g->nwall.path)
		return (1);
	if (!g->swall.path)
		return (1);
	if (!g->ewall.path)
		return (1);
	if (!g->wwall.path)
		return (1);
	if (g->ceil_c == -1)
		return (1);
	if (g->flor_c == -1)
		return (1);
	return (0);
}
