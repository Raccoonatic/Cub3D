/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:47:46 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/03 11:44:46 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_MAIN_HEADER_H
# define CB_MAIN_HEADER_H

// External Libraries:
# include "./libft/includes/libft.h"
# include "./mlx_linux/mlx.h"
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

// Project typedefs:
# include "./cb_structs.h"

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

// Macro Definitions:
# define TSZ	30
# define WH		1080
# define WW		1920
# define MXMPH	300
# define MXMPW	400
# define MNMWC	0xFFFFFFFF

// Text Color:
# define RST	"\033[0m"
# define BWI	"\033[1;37m"
# define NAV	"\033[38;2;0;2;31m"
# define LME	"\033[38;2;0;255;0m"
# define BBY	"\033[1;38;2;0;255;247m"
# define BLD	"\033[1;38;2;255;0;0m"
# define PUR	"\033[1;38;2;174;5;252m"
# define MNT	"\033[1;38;2;55;250;133m"
# define NOR	"\033[3m\033[1;38;2;255;153;51m"

// Prototypes:

// ----	cb_exit.c
void		cb_fail(int errn, int code, const char *msg);
void		cb_kill_the_game(t_game *gm, int flag, int errn, int code);
void		cb_frexit(t_game *g, char *str, char **mtrx, const char *msg);

// ----	cb_time.c
long long	cb_now(void);

// ----	cb_destroy.c
void		cb_frink(t_game *g);
void		cb_free_matrix(char **matrix);
void		cb_imgdata_wipe(t_game *g, t_img *i);

// ----	cb_zeroing.c
void		cb_null_ptrs(t_img *i);
void		cb_zero_ints(t_img *i);
void		cb_zeroing(t_game *game);
void 		cb_zero_player(t_player *player);

// ----	cb_map_pars_utils.c
int			cb_map_height(char **map);
int			cb_map_width(char **map);
int			cb_check_surr(char **map, int i, int j);

// ----	cb_map_pars.c
int			cb_validate_map(char **map, t_game *game);

// ----	cb_getcolors.c
int			cb_get_flor(t_game *game, char *cursor, char *line, int fd);
int			cb_get_ceil(t_game *game, char *cursor, char *line, int fd);

// ----	cb_getpaths.c
int			cb_get_north(t_game *g, char *cursor, char *line, int fd);
int			cb_get_south(t_game *g, char *cursor, char *line, int fd);
int			cb_get_westh(t_game *g, char *cursor, char *line, int fd);
int			cb_get_easth(t_game *g, char *cursor, char *line, int fd);

// ----	cb_scenetomap.c
char		**cb_scene_to_map(t_game *g, char *map_path);

// ----	cb_scenetomap_utils_alpha.c
char		*cb_skip_blank(char *line);
char		**cb_addline(char **raw_map, char **line);
int			cb_scene_data_fill(t_game *g, char **line, int fd);

// ----	cb_scenetomap_utils_beta.c
void		cb_flood_fill(char **map, int y, int x);
char		**cb_matrixalloc(int columns, int rows);
void		cb_map_populate(char **raw, char **dest, int miny, int minx);

// ----	cb_getborders.c
int			cb_define_borders(char **raw, int *maxy, int *minx, int *maxx);

<<<<<<< HEAD
// ---- cb_player.c
void    	cb_innit_player(t_game *game);
=======
// ----	cb_define_playable_map.c
void		cb_define_playable_map(t_game *g, char **map);

// ----	cb_layer_init.c
void		cb_imgmain_init(t_game *g, t_img *i, char *path);
void		cb_layer_init(t_game *g, int *bpx, int *bpr, int *e);

// ----	cb_minimap.c
void		cb_minimap_init(t_game *g, t_mp *m);
void		cb_minimap_compose(t_game *g, t_mp *m);

// --- cb_render.c
int			cb_render(t_game *g);

// ----	cb_render_utils_alpha.c
void		cb_blackpink(t_img *img, int h);
void		cb_push_bkgrnd_to_frame(t_img *d, t_img *s);
void		cb_push_tile_to_frame(t_img *dst, t_img *src, t_cord c, char f);

// ----	cb_coordinate.c
void		cb_coordinate(t_cord *vessel, int c_unit, t_game *g, int ctrl);
>>>>>>> origin/mapache

#endif
