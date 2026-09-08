/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:53:06 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/08 15:59:10 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"


void	cb_coordinate(t_cord *vessel, int c_unit, t_game *g, int ctrl)
{
	if (c_unit == 1)
	{
		vessel -> fw = g->mp.map.w;
		vessel -> fh = g->mp.map.h;
		vessel -> th = TSZ;
		vessel -> tw = TSZ;
		vessel -> x = ctrl;
	}
	return ;
}
