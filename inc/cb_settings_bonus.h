/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_settings_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:04:12 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/18 14:01:32 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_SETTINGS_H
# define CB_SETTINGS_H

// Main Settings Definition:
# ifndef TSZ
#  define TSZ		20			// Tile Size.
# endif
# ifndef FOV
#  define FOV		0.86f		// Field of View.
# endif
# ifndef WH
#  define WH		900			// Window Height.
# endif
# ifndef WW
#  define WW		1700		// Window Width.
# endif
# ifndef ROTSPD
#  define ROTSPD	0.02f		// Player Rotation Speed.
# endif
# ifndef MVMSPD
#  define MVMSPD	0.04f		// Player Movement Speed.
# endif
# ifndef MXMPH
#  define MXMPH		200			// Max Minimap Height.
# endif
# ifndef MXMPW
#  define MXMPW		300			// Max Minimap Width.
# endif
# ifndef MNMWC
#  define MNMWC		0xFFFFFFFF	// Minimap Wall Color.
# endif

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

#endif
