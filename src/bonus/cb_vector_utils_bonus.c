/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_vector_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:47:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/18 13:57:08 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	t_vd_equal(t_vd *v1, t_vd *v2);
void	t_vi_equal(t_vi *v1, t_vi *v2);
void	t_vd_toint(t_vi *v1, t_vd *v2);
void	t_vi_tofloat(t_vd *v1, t_vi *v2);

void	t_vd_equal(t_vd *v1, t_vd *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	return ;
}

void	t_vi_equal(t_vi *v1, t_vi *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	return ;
}

void	t_vd_toint(t_vi *v1, t_vd *v2)
{
	v1->x = (int)v2->x;
	v1->y = (int)v2->y;
	return ;
}

void	t_vi_tofloat(t_vd *v1, t_vi *v2)
{
	v1->x = (double)v2->x;
	v1->y = (double)v2->y;
	return ;
}
