/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/05/08 23:33:45 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(char *s)
{
	int	i;
	int c;
	int c2;
	int	flag;

	if (!s)
		return (0);
	if (ft_strchr(s, ';' || ft_strchr(s, '\\')))
		return (1);
	i = 0;
	c = 0;
	c2 = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] && s[i] != ' ' && s[i] != '|')
		{
			if (s[i] == '<')
			{
				if (s[i + 1] == '>')
					return (1);
				c++;				
			}
			else if (s[i] == '>')
			{
				if (s[i + 1] == '<')
					return (1);
				c2++;
			}
			else
				
			if (c > 2 || c2 > 2)
				return (1);
			flag = 1;
			i++;
		}
		if (!flag)
			return (1);
		while (s[i] == ' ')
			i++;
		if (s[i] == '|')
			i++;
		while (s[i] == ' ')
			i++;
	}
	if (i > 0 && (s[i - 1] == '|' || s[i - 1] == '>' || s[i - 1] == '<'))
    	return (1);
	return (0);
}

int	check_qoutes(char *s)
{
	int	i;
	int	single_f;
	int	double_f;

	if (!s)
		return (0);
	single_f = 0;
	double_f = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !double_f)
			single_f = !single_f;
		else if (s[i] == '"' && !single_f)
			double_f = !double_f;
		i++;
	}
	if (double_f || single_f)
		return (1);
	return (0);
}

char	*handle_exp(char *s)
{
	char	*new;
	char	*d;
	char	*str;
	int		i;
	int		j;
	int	single_f;
	int	double_f;

	if (!s)
		return (NULL);
	single_f = 0;
	double_f = 0;
	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] == '\'' && !double_f)
			single_f = !single_f;
		else if (s[i] == '"' && !single_f)
			double_f = !double_f;
		if (s[i] == '$' && !single_f && (double_f || !double_f))
		{
			j += i;
			while (s[j] && s[j] != ' ' && s[j] != '\''
				&& s[j] != '"' && s[j] != '$')
				j++;
			str = ft_substr(s + i + 1, 0, j - i - 1);
			d = getenv(str);
			free(str);
			if (d)
			{
				new = ft_substr(s, 0, (s + i) - s);
				str = ft_strjoin(new, d);
				free(new);
				new = ft_strjoin(str, s + j);
				free(str);
				return (new);
			}
			else
			{
				str = ft_substr(s, 0, (s + i) - s);
				new = ft_strjoin(str, s + j);
				free(str);
				return (new);
			}
		}
		i += j;
	}
	return (NULL);
}

void	exit_with_err()
{
	printf("syntax error\n");
	exit(2);
}

int	main(void)
{
	int		i;
	int		c;
	int		j;
	int 	r_flag;
	char	*line;
	char	*new_line;
	char	*ptr;
	char	**cmds;
	t_list	*head;
	t_list	*n;
	t_redir	*r;

	while (1)
	{
		line = readline("$ ");
		add_history(line);
		new_line = ft_strtrim(line, " ");
		free(line);
		if (check_qoutes(new_line))
			exit_with_err();
		if (is_valid(new_line))
			exit_with_err();
		ptr = handle_exp(new_line);
		while (ptr)
		{
			free(new_line);
			new_line = ptr;
			ptr = handle_exp(new_line);
		}
		cmds = ft_split(new_line, '|');
		head = NULL;
		i = 0;
		while (cmds[i])
		{
			j = 0;
			r = NULL;
			ft_lstadd_back(&head, ft_lstnew(NULL, CMD_NAME));
			r_flag = -1;
			while (cmds[i][j])
			{
				c = 0;
				while (cmds[i][j] && cmds[i][j] != ' ' && cmds[i][j] != '<'
					&& cmds[i][j] != '>')
				{
					c++;
					j++;
				}
				if (c > 0)
				{
					n = ft_lstlast(head);
					if (r_flag >= 3)
					{
						ft_red_add_back(&n->redir, ft_new_red(ft_substr(cmds[i], j - c, c), r_flag));
						r_flag = -1;
					}
					else
						n->value = ft_substr(cmds[i], j - c, c);
					// if ()
					// {
					// 	ft_lstadd_back(&head, ft_lstnew(, CMD_ARGS));	
					// }
				}
				if (cmds[i][j] == '<' || cmds[i][j] == '>')
				{
					if (cmds[i][j] == '<' && cmds[i][j + 1] == '<')
					{
						r_flag = HERE_DOC;
						j += 2;
					}
					else if (cmds[i][j] == '>' && cmds[i][j + 1] == '>')
					{
						r_flag = APPEND;
						j += 2;
					}
					else
					{
						if (cmds[i][j] == '>')
							r_flag = OUT_R;
						else
							r_flag = IN_R;
						j++;
					}
				}
				while (cmds[i][j] == ' ')
					j++;
			}
			i++;
		}
		free(new_line);
	}
}
