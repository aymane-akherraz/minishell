/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:40:46 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/30 12:34:02 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>


typedef enum token
{
	CMD_NAME,
	CMD_ARGS,
	PIPE,
	IN_R,
	OUT_R,
	HERE_DOC,
	APPEND
}	t_token;

typedef struct redir
{
	char		*file;
	t_token		type;
	struct redir *next;
}	t_redir;

typedef struct ast_node
{
	char				*value;
	t_token				type;
	struct redirect		*redir;
	struct ast_node		*parent;
	struct ast_node		*left_node;
	struct ast_node		*right_node;
}	t_ast_node;

#endif
