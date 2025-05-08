/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:40:46 by aakherra          #+#    #+#             */
/*   Updated: 2025/05/08 22:56:40 by aakherra         ###   ########.fr       */
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
}	e_token;

typedef struct s_redir
{
	char		*file;
	e_token		type;
	struct s_redir *next;
}	t_redir;

typedef struct s_list
{
	char				*value;
	e_token				type;
	struct redirect		*redir;
	struct s_list		*next;
}	t_list;

void	ft_red_add_back(t_redir **lst, t_redir *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *value, e_token type);
t_redir	*ft_new_red(char *file, e_token type);
t_list	*ft_lstlast(t_list *head);

#endif
