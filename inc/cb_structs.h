/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:46:43 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 23:21:42 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_STRUCTS_H
# define CB_STRUCTS_H

# include "./cb_settings.h"

typedef enum e_kys
{
	K_W = 119,
	K_A = 97,
	K_S = 115,
	K_D = 100,
	K_ESC = 65307,
	K_LFT = 65361,
	K_RGT = 65363,
	K_UP = 65362,
	K_DOW = 65364
}	t_kys;

typedef struct s_cord
{
	int	fh;
	int	fw;
	int	th;
	int	tw;
	int	x;
	int	y;
}	t_cord;

typedef struct s_vd
{
	double	x;
	double	y;
}	t_vd;

typedef struct s_vi
{
	int	x;
	int	y;
}	t_vi;

typedef struct s_player
{
	t_vi		map;
	t_vd		ren;
	t_vd		dir;
	t_vd		plne;
	double		acel;
} t_player;

typedef struct s_line
{
    t_vi	step;
    t_vi	len;
    int		err;
}   t_line;

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

typedef struct s_mp
{
	void	*pov;
	char    *addr;
	t_img	map;
	t_img	ph;
	int     bpx;
	int     bpr;
	int     e;
	int		h;
	int		w;
	int     x;
	int     y;
	int		ray_color;
	int		flor_color;
} 	t_mp;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			h;
	int			w;
	int			flor_c;
	int 		ceil_c;

	t_mp		mp;

	t_img		bkg;
	t_img		buf;
	t_img		nwall;
	t_img		swall;
	t_img		ewall;
	t_img		wwall;

	t_player	ply;
	long long	tstamp;
	char		l; // -- Just testing the different facing options for the player sprite

	t_vd		hits[WW];

	bool	kw;
	bool	ka;
	bool	ks;
	bool	kd;
	bool	klft;
	bool	krgt;

}	t_game;

typedef	struct s_ray
{
	t_vd	stps;
	t_vi	stpdir;
	t_vi	vmap;
	t_vd	raylen;
	double	distance;
	t_game	*g;
}	t_ray;

#endif
