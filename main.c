/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/28 15:35:09 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(char *s)
{
	int	i;
	int	flag;

	i = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] == ' ')
			i++;
		while (ft_isalnum(s[i]) || s[i] == '-' || s[i] == '_'
				|| s[i] == '/' || s[i] == '.' || s[i] == '\'' || s[i] == '"')
		{
			flag = 1;
			i++;
		}
		if (!flag)
			return (1);
		while (s[i] == ' ')
			i++;
		if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<'))
			i += 2;
		else if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			i++;
	}
	if (s[i - 1] == '|' || s[i - 1] == '>' || s[i - 1] == '<')
    	return (1);
	return (0);
}

int	main(void)
{
	//int		i;
	char	*line;
	char	*new_line;
	//char	**tokens;

	while (1)
	{
		line = readline("$ ");
		add_history(line);
		new_line = ft_strtrim(line, " ");
		if (is_valid(new_line))
			printf("error\n");
		free(line);
		free(new_line);
	}
}
