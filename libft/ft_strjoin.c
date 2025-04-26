/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:26:24 by aakherra          #+#    #+#             */
/*   Updated: 2024/10/30 22:35:53 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	i;
	size_t	j;
	size_t	len;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	len = l1 + ft_strlen(s2);
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < l1)
		{
			p[i] = s1[i];
			i++;
		}
		j = 0;
		while (i < len)
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	return (p);
}
