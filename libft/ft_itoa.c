/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:17:02 by aakherra          #+#    #+#             */
/*   Updated: 2024/10/30 22:49:27 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(int n, int i)
{
	char	*s;

	if (n < 0)
		s = malloc(i + 2);
	else
		s = malloc(i + 1);
	return (s);
}

static char	*handle_zero(void)
{
	char	*s;

	s = malloc(2);
	if (s)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	return (s);
}

static int	*set_int(int n, int *a, int *p)
{
	unsigned int	num;

	if (n < 0)
		num = -n;
	else
		num = n;
	while (num)
	{
		a[*p] = num % 10;
		num /= 10;
		(*p)++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		a[10];
	int		i;
	int		j;
	char	*s;

	if (n == 0)
		return (handle_zero());
	i = 0;
	set_int(n, a, &i);
	s = allocate(n, i);
	if (s)
	{
		j = 0;
		if (n < 0)
			s[j++] = '-';
		i--;
		while (i >= 0)
			s[j++] = a[i--] + 48;
		s[j] = '\0';
	}
	return (s);
}
