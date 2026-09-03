/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getpaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:33:50 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 17:37:03 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int	cb_get_north(t_game *g, char *cursor, char *line, int fd);
int	cb_get_south(t_game *g, char *cursor, char *line, int fd);
int	cb_get_westh(t_game *g, char *cursor, char *line, int fd);
int	cb_get_easth(t_game *g, char *cursor, char *line, int fd);

int	cb_get_north(t_game *g, char *cursor, char *line, int fd)
{
	char	*path;
	int		path_fd;

	path = ft_strtrim(cursor, " \t\n\v\f\r");
	if (!path)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_strtrim failed on "NOR"north_path");
	}
	path_fd = open(path, O_RDONLY);
	if (path_fd < 3 || g->nwall.path)
	{
		close(fd);
		get_next_line(fd);
		free(path);
		if (path_fd < 3)
			cb_frexit(g, line, NULL, "Failed to reach "NOR"north_path");
		close(path_fd);
		cb_frexit(g, line, NULL, "There can only be one "NOR"north_path");
	}
	close(path_fd);
	g->nwall.path = path;
	return (0);
}

int	cb_get_south(t_game *g, char *cursor, char *line, int fd)
{
	char	*path;
	int		path_fd;

	path = ft_strtrim(cursor, " \t\n\v\f\r");
	if (!path)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_strtrim failed on "NOR"south_path");
	}
	path_fd = open(path, O_RDONLY);
	if (path_fd < 3 || g->swall.path)
	{
		close(fd);
		get_next_line(fd);
		free(path);
		if (path_fd < 3)
			cb_frexit(g, line, NULL, "Failed to reach "NOR"south_path");
		close(path_fd);
		cb_frexit(g, line, NULL, "There can only be one "NOR"south_path");
	}
	close(path_fd);
	g->swall.path = path;
	return (0);
}

int	cb_get_westh(t_game *g, char *cursor, char *line, int fd)
{
	char	*path;
	int		path_fd;

	path = ft_strtrim(cursor, " \t\n\v\f\r");
	if (!path)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_strtrim failed on "NOR"west_path");
	}
	path_fd = open(path, O_RDONLY);
	if (path_fd < 3 || g->wwall.path)
	{
		close(fd);
		get_next_line(fd);
		free(path);
		if (path_fd < 3)
			cb_frexit(g, line, NULL, "Failed to reach "NOR"west_path");
		close(path_fd);
		cb_frexit(g, line, NULL, "There can only be one "NOR"west_path");
	}
	close(path_fd);
	g->wwall.path = path;
	return (0);
}

int	cb_get_easth(t_game *g, char *cursor, char *line, int fd)
{
	char	*path;
	int		path_fd;

	path = ft_strtrim(cursor, " \t\n\v\f\r");
	if (!path)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_strtrim failed on "NOR"east_path");
	}
	path_fd = open(path, O_RDONLY);
	if (path_fd < 3 || g->ewall.path)
	{
		close(fd);
		get_next_line(fd);
		free(path);
		if (path_fd < 3)
			cb_frexit(g, line, NULL, "Failed to reach "NOR"east_path");
		close(path_fd);
		cb_frexit(g, line, NULL, "There can only be one "NOR"east_path");
	}
	close(path_fd);
	g->ewall.path = path;
	return (0);
}
