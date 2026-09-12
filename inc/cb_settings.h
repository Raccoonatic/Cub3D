/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:04:12 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/12 23:21:43 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_SETTINGS_H
# define CB_SETTINGS_H

// Main Settings Definition:
# define TSZ	50			// Tile Size. At school: 20
# define FOV	0.66f		// Field of View.
# define WH		2160		// Window Height. At school: 900
# define WW		3840		// Window Width. At school: 1600
# define RAYMX	100.0f	 	// Max Ray Distance.
# define ROTSPD	0.03f		// Player Rotation Speed. At school: 0.01
# define MVMSPD	0.04f		// Player Movement Speed. At school: 0.02
# define MXMPH	500			// Max Minimap Height. At school: 200
# define MXMPW	400			// Max Minimap Width. At school: 300
# define MNMWC	0xFFFFFFFF	// Minimap Wall Color.

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
