/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/27 22:27:41 by aakherra         ###   ########.fr       */
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

t_ast_node	*create_node(char *val, t_ast_node *parent, t_token type)
{
	t_ast_node	*node;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->left_node = NULL;
	node->right_node = NULL;
	node->value = val;
	node->type = type;
	return (node);
}

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
				|| s[i] == '/' || s[i] == '.')
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
	if (s[i - 1] == '|')
    	return (1);
	return (0);
}

int	main(void)
{
	//int		i;
	char	*line;
	//char	**tokens;

	line = readline("$ ");
	
}
