/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/27 11:41:37 by aakherra         ###   ########.fr       */
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

int	main(void)
{
	int		i;
	char	*line;
	char	**tokens;
	t_ast_node	*root;
	t_ast_node	*parent;

	line = readline("$ ");
	tokens = ft_split(line, ' ');
	if (!tokens)
		printf("error");
	if (is_word(tokens[0]))
	{
		root = create_node(tokens[0], NULL, CMD_NAME);
	}
	i = 1;
	while (tokens[i])
	{
		if (is_word(tokens[i]))
		{
			

		}
		i++;
	}
}
