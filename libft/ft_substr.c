/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:45:51 by aakherra          #+#    #+#             */
/*   Updated: 2024/11/02 12:19:34 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sl;
	char	*p;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (start >= sl)
		len = 0;
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < len && s[start])
		{
			p[i] = s[start];
			i++;
			start++;
		}
		p[i] = '\0';
	}
	return (p);
}
