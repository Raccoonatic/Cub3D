/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:40:01 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/01 16:40:09 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	new -> next = *lst;
	*lst = n;
}
/*Takes the node "new" and integrates it to the
start of the list pointed to by lst*/
