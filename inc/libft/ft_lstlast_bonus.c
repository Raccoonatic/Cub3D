/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:48:44 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/21 12:48:44 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst -> next))
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}
