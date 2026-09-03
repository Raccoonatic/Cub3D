<<<<<<< HEAD
<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:39:40 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/02 19:45:19 by lde-san-         ###   ########.fr       */
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

	long long	tstamp;
}	t_game;

#endif
=======
=======
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:39:40 by lde-san-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/09/01 16:40:05 by lde-san-         ###   ########.fr       */
=======
/*   Updated: 2026/09/02 19:45:19 by lde-san-         ###   ########.fr       */
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
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
<<<<<<< HEAD
=======
	int			flor_c;
	int 		ceil_c;
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95

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
<<<<<<< HEAD
>>>>>>> origin/rdeimaos
=======
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
