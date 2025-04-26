/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/26 20:02:55 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_word(char *s)
{
	if (ft_strcmp(s, "|") && ft_strcmp(s, "<") && ft_strcmp(s, ">")
		&& ft_strcmp(s, "<<") && ft_strcmp(s, ">>"))
		return (1);
	return (0);
}

int	main(void)
{
	int		i;
	char	*line;
	char	**tokens;

	line = readline("$ ");
	tokens = ft_split(line, ' ');
	i = 0;
	while (tokens[i])
	{
		if (is_word(tokens[i]))
		{
			
		}
		
		i++;
	}
	
}
