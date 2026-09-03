/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:14:20 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/01 16:40:09 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*last;

	if (!lst || !n)
		return ;
	if (!*lst)
	{
		*lst = n;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = n;
}
/*Takes the node "new" and integrates it at the
end of the list pointed to by lst*/
