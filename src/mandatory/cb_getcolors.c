/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_getcolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:30:12 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/06 15:55:39 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int			cb_get_flor(t_game *g, char *cursor, char *line, int fd);
int			cb_get_ceil(t_game *g, char *cursor, char *line, int fd);
static int	cb_rgb_check(char **rgb, t_game *g, char *line, int fd);

static bool	cb_is_num_invalid(char *str, bool *inv)
{
	int	j;

	j = 0;
	while(ft_isdigit(str[j]))
		j++;
	if (str[j] && !ft_isdigit(str[j]))
	{
		*inv = true;
		return (*inv);
	}
	return (false);
}

static int	cb_rgb_check(char **rgb, t_game *g, char *line, int fd)
{
	int		i;
	bool	invalid;
	char	*flush;

	i = 0;
	invalid = false;
	if (!rgb)
		return (1);
	while (rgb[i])
	{
		if(cb_is_num_invalid(rgb[i], &invalid))
			break;
		i++;
	}
	if (invalid || i != 3)
	{
		close(fd);
		while ((flush = get_next_line(fd)))
			free(flush);
		cb_frexit(g, line, rgb, "Incorrect color formatting");
	}
	return (0);
}

int	cb_get_flor(t_game *g, char *cursor, char *line, int fd)
{
	char	*color;
	char	**rgb;
	int		red;
	int		gre;
	int		blu;

	color = ft_filterset(cursor, " \t\n\v\f\r");
	if (!color)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_filterset failed on "NOR"floor_color");
	}
	rgb = ft_split(color, ',');
	free(color);
	if (cb_rgb_check(rgb, g, line, fd))
		return (1);
	red =	atoi(rgb[0]);
	gre = atoi(rgb[1]);
	blu = atoi(rgb[2]);
	if (red > 255 || gre > 255 || blu > 255
		|| red < 0 || gre < 0 || blu < 0 )
		return (cb_free_matrix(rgb), 1);
	g->flor_c = red << 16 | gre << 8 | blu;
	return (cb_free_matrix(rgb), 0);
}

int	cb_get_ceil(t_game *g, char *cursor, char *line, int fd)
{
	char	*color;
	char	**rgb;
	int		red;
	int		gre;
	int		blu;

	color = ft_filterset(cursor, " \t\n\v\f\r");
	if (!color)
	{
		close(fd);
		get_next_line(fd);
		cb_frexit(g, line, NULL, "ft_filterset failed on "NOR"ceiling_color");
	}
	rgb = ft_split(color, ',');
	free(color);
	if (cb_rgb_check(rgb, g, line, fd))
		return (1);
	red =	atoi(rgb[0]);
	gre = atoi(rgb[1]);
	blu = atoi(rgb[2]);
	if (red > 255 || gre > 255 || blu > 255
		|| red < 0 || gre < 0 || blu < 0 )
		return (cb_free_matrix(rgb), 1);
	g->ceil_c = red << 16 | gre << 8 | blu;
	return (cb_free_matrix(rgb), 0);
}
