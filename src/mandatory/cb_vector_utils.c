/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_vector_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:47:41 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/11 19:53:44 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cb_main_header.h"

void	cb_ray_init(t_ray *ray);
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

void	cb_ray_init(t_ray *ray)
{
	ray->stps.x = 0.0f;
	ray->stps.y = 0.0f;
	ray->stpdir.x = 0;
	ray->stpdir.y = 0;
	ray->vmap.x = 0;
	ray->vmap.y = 0;
	ray->raylen.x = 0.0f;
	ray->raylen.y = 0.0f;
	ray->distance = 0.0f;
	ray->g = NULL;
	return ;
}
