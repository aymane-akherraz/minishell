/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:40:46 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/26 19:50:03 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum token
{
	WORD,
	PIPE,
	IN_R,
	OUT_R,
	HERE_DOC,
	APPEND
}	t_token;

typedef struct ast_node
{
	char				*value;
	t_token				type;
	struct ast_node		*parent_node;
	struct ast_node		*left_node;
	struct ast_node		*right_node;
}	t_ast_node;

#endif
