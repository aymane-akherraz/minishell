/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/29 12:37:12 by aakherra         ###   ########.fr       */
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
		while (ft_isalnum(s[i]) || s[i] == '-' || s[i] == '_' || s[i] == '$'
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

int	check_qoutes(char *s)
{
	int	i;
	int	single_f;
	int	double_f;

	single_f = 0;
	double_f = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '\'' && s[i] != '"')
			i++;
		if (s[i] == '\'' && !double_f)
			single_f = !single_f;
		else if (s[i] == '"' && !single_f)
			double_f = !double_f;
		if (s[i])
			i++;
	}
	if (double_f || single_f)
		return (1);
	return (0);
}

char	*handle_exp(char *s)
{
	char	*ptr;
	char	*new;
	char	*d_quote;
	char	*s_quote;
	size_t		i;

	d_quote = ft_strchr(s, '"');
	s_quote = ft_strchr(s, '\'');
	if (((d_quote && s_quote) && (d_quote < s_quote)) || (!d_quote && !s_quote) || (d_quote && !s_quote))
	{
		if (d_quote)
			ptr = ft_strchr(d_quote, '$');
		else
			ptr = ft_strchr(s, '$');
		if (ptr)
		{
			ptr++;
			i = 0;
			while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\'' && ptr[i] != '"')
				i++;
			s_quote = ft_substr(ptr, 0, i);
			d_quote = getenv(s_quote);
			free(s_quote);
			if (d_quote)
			{
				new = ft_substr(s, 0, ptr - s - 1);
				s_quote = ft_strjoin(new, d_quote);
				free(new);
				new = ft_strjoin(s_quote, ptr + i);
				free(s_quote);
				return (new);
			}
		}
	}
	return (NULL);
}

int	main(void)
{
	//int		i;
	char	*line;
	char	*new_line;
	char	*ptr;
	//char	**tokens;

	while (1)
	{
		line = readline("$ ");
		add_history(line);
		new_line = ft_strtrim(line, " ");
		if (is_valid(new_line))
			printf("error1\n");
		if (check_qoutes(new_line))
			printf("error2\n");
		ptr = handle_exp(new_line);
		if (ptr)
		{
			free(new_line);
			new_line = ptr;
		}
		printf("%s\n", new_line);
		free(line);
		free(new_line);
	}
}
