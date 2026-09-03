/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filterset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:19:21 by lde-san-          #+#    #+#             */
/*   Updated: 2026/09/02 19:45:16 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	count_valid(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_filterset(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	trimmed = malloc(sizeof(char) * (count_valid(s1, set) + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
		{
			trimmed[j] = s1[i];
			j++;
		}
		i++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}
/* Allocates memory for a new string array that's essentially a copy of
   the original s1, without any of the characters from the set.*/
