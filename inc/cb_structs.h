/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:39:40 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/01 16:40:05 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_STRUCTS_H
# define CB_STRUCTS_H

typedef struct s_img
{
	void	*main;
	char	*addr;
	char 	*path;
	int		bpx;
	int		bpr;
	int		e;
	int		h;
	int		w;
	void	**frm;
	char	**frad;
	int		fbpx;
	int		fbpr;
	int		fe;
	int		mx_index;
	int		crnt_frm;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			h;
	int			w;

	t_img		buf;
	t_img		flor;
	t_img		ceil;
	t_img		minimap;
	t_img		nwall;
	t_img		swall;
	t_img		ewall;
	t_img		wwall;

	long long	tstamp;
}	t_game;

#endif
