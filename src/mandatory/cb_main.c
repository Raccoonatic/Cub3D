<<<<<<< HEAD
<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/02 19:45:17 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int main(int ac, char **av)
{
	t_game game;

    if (ac != 2)
		cb_fail(2, 2, "Incorrect argument count.");
	cb_zeroing(&game);
	if (cb_check_map(&game, cb_scene_to_map(&game, av[1]), &game));

	return (0);
}
=======
=======
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:23:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/02 19:45:17 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

int main(int ac, char **av)
{
	t_game game;

    if (ac != 2)
		cb_fail(2, 2, "Incorrect argument count.");
	cb_zeroing(&game);
	if (cb_check_map(&game, cb_scene_to_map(&game, av[1]), &game));

<<<<<<< HEAD
	
}
>>>>>>> origin/rdeimaos
=======
	return (0);
}
>>>>>>> 024ec7ff1bbcb68fabeee1d251413eb19ed6ba95
