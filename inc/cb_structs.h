/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:46:43 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/04 01:04:58 by lde-san-         ###   ########.fr       */
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
	int			flor_c;
	int 		ceil_c;

	t_img		buf;
	t_img		flor;
	t_img		ceil;
	t_img		minimap;
	t_img		nwall;
	t_img		swall;
	t_img		ewall;
	t_img		wwall;

	t_player	player;
	long long	tstamp;
}	t_game;

typedef struct s_player
{
	int			x;
	int			y;
	double		ren_x;
	double		ren_y;
	double		dir_x;
	double		dir_y;
	double		acel;
} t_player;

#endif
