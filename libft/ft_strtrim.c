/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:06:24 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/28 14:53:09 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n, size_t start)
{
	size_t	i;

	i = 0;
	while (i < n)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	l = ft_strlen(set);
	j = ft_strlen(s1);
	if (l > j)
		return (NULL);
	while (s1[i] && ft_memchr(set, s1[i], l))
		i++;
	while (j > i && ft_memchr(set, s1[j - 1], l))
		j--;
	p = malloc(((j - i) * sizeof(char)) + 1);
	if (p)
		ft_strncpy(p, s1, (j - i), i);
	return (p);
}
