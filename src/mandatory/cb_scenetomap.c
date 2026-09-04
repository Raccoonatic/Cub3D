/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scenetomap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:15:26 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/04 01:26:07 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

static char	**cb_refine_map(t_game *g, char **raw);
static char	**cb_read_the_scene(t_game *g, int fd);
char		**cb_scene_to_map(t_game *g, char *map_path);
static char	**cb_get_raw_map(t_game *g, int fd, char *line);

char	**cb_scene_to_map(t_game *g, char *map_path)
{
	char	**raw_map;
	char	**ref_map;
	int		fd;

	if (ft_strlen(map_path) <= 4)
		cb_fail(1, 2, "Map name incomplete. "NOR"Is empty or without .cub");
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		cb_fail(1, 2, "Map extension must be "LME".cub");
	fd = open(map_path, O_RDONLY);
	if (fd < 3)
		cb_fail(1, 2, "Failed to "BBY"open "PUR"map file on "BWI"READ");
	raw_map = cb_read_the_scene(g, fd);
	close(fd);
	if (!raw_map)
		cb_frexit(g, NULL, NULL, "Failed to load scene"NOR" Can't get map.");
	ref_map = cb_refine_map(g, raw_map);
	if (!ref_map)
		cb_frexit(g, NULL, raw_map, "Failed to refine the map.");
	cb_free_matrix(raw_map);
	return (ref_map);
}

static char	**cb_read_the_scene(t_game *g, int fd)
{
	char *line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		get_next_line(fd);
		cb_fail(1, 1, "Can't read secene file "BWI"gnl"NOR" Failed.");
	}
	if (cb_scene_data_fill(g, &line, fd))
	{
		if (line)
			free(line);
		close(fd);
		get_next_line(fd);
		cb_fail(1, 1, "Can't read secene file "BWI"Texture/Color"NOR" Error.");
	}
	return (cb_get_raw_map(g, fd, line));
}

char	**cb_get_raw_map(t_game *g, int fd, char *line)
{
	char	**raw_map;

	raw_map = NULL;
	while (line)
	{
		raw_map = cb_addline(raw_map, line);
		if (line)
				free(line);
		if (!raw_map)
		{
			close(fd);
			get_next_line(fd);
			cb_frexit(g, NULL, NULL, "cb_addline failed. "NOR"Can't get map.");
		}
		line = get_next_line(fd);
	}
	return (raw_map);
}

static char	**cb_refine_map(t_game *g, char **raw)
{
	int		mny;
	int		mxy;
	int		mnx;
	int		mxx;
	char	**destilled;

	mxy = 0;
	mnx = 0;
	mxx = 0;
	mny = cb_define_borders(raw, &mxy, &mnx, &mxx);
	if (mny == -1)
		cb_frexit(g, NULL, raw, "Invalid scene file. "NOR"Empty map.");
	destilled = cb_matrixalloc(mxy - mny, mxx - mnx);
	if (!destilled)
		cb_frexit(g, NULL, raw, "Couldn't load scene file. "NOR"calloc error.");
	cb_map_populate(raw, destilled, mny, mnx);
	return (destilled);
}
