/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:01:41 by aakherra          #+#    #+#             */
/*   Updated: 2024/11/03 17:17:47 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (j > 0)
				count++;
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (j > 0)
		count++;
	return (count);
}

static void	free_all(char **p, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static int	allocate(char **a, char const *s, size_t i, size_t *p)
{
	a[*p] = ft_substr(s, (i - p[1]), p[1]);
	if (!a[*p])
	{
		p[1] = 0;
		free_all(a, *p);
		return (0);
	}
	(*p)++;
	return (1);
}

static char	**helper(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	p[2];

	i = 0;
	p[0] = 0;
	p[1] = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (p[1] > 0 && (!allocate(arr, s, i, p)))
				break ;
			p[1] = 0;
		}
		else
			p[1]++;
		i++;
	}
	if (p[1] > 0)
		allocate(arr, s, i, p);
	arr[*p] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((sizeof(char *) * count_strs(s, c)) + sizeof(char *));
	if (!arr)
	{
		free(arr);
		arr = NULL;
		return (arr);
	}
	return (helper(s, c, arr));
}
