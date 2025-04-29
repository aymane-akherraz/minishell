/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:01:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/04/29 15:22:10 by aakherra         ###   ########.fr       */
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
	char	*d;
	char	*str;
	size_t		i;

	d = ft_strchr(s, '"');
	str = ft_strchr(s, '\'');
	if (((d && str) && (d < str))
		|| (!d && !str) || (d && !str))
	{
		if (d)
			ptr = ft_strchr(d, '$');
		else
			ptr = ft_strchr(s, '$');
		if (ptr)
		{
			ptr++;
			i = 0;
			while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\''
					&& ptr[i] != '"' && ptr[i] != '$')
				i++;
			str = ft_substr(ptr, 0, i);
			d = getenv(str);
			free(str);
			if (d)
			{
				new = ft_substr(s, 0, ptr - s - 1);
				str = ft_strjoin(new, d);
				free(new);
				new = ft_strjoin(str, ptr + i);
				free(str);
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
		free(line);
		if (is_valid(new_line))
			printf("error1\n");
		if (check_qoutes(new_line))
			printf("error2\n");
		ptr = handle_exp(new_line);
		while (ptr)
		{
			free(new_line);
			new_line = ptr;
			ptr = handle_exp(new_line);
		}
		printf("%s\n", new_line);
		free(new_line);
	}
}
