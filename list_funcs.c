/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:58:22 by aakherra          #+#    #+#             */
/*   Updated: 2025/05/08 22:52:04 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(char *value, e_token type)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (p)
	{
		p->value = value;
		p->type = type;
		p->redir = NULL;
		p->next = NULL;
	}
	return (p);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_redir	*ft_new_red(char *file, e_token type)
{
	t_redir	*p;

	p = malloc(sizeof(t_redir));
	if (p)
	{
		p->file = file;
		p->type = type;
		p->next = NULL;
	}
	return (p);
}

void	ft_red_add_back(t_redir **lst, t_redir *new)
{
	t_redir	*p;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
