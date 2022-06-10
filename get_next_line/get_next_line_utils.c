/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:42:44 by kbrechin          #+#    #+#             */
/*   Updated: 2022/06/07 19:44:13 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getlen(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
		i++;
	return (i);
}

int	ft_charfind(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc(ft_getlen(str1) + ft_getlen(str2) + 1);
	if (str1)
		while (str1[j])
			join[i++] = str1[j++];
	j = 0;
	if (str2)
		while (str2[j])
			join[i++] = str2[j++];
	join[i++] = '\0';
	if (str1)
		free(str1);
	return (join);
}

char	*ft_assign(char **store)
{
	int		i;
	int		j;
	char	*buff_line;
	char	*new_store;

	i = ft_charfind(*store);
	if (i == 0)
		i = ft_getlen(*store);
	buff_line = malloc(i + 1);
	new_store = (NULL);
	buff_line[i] = '\0';
	while (i-- > 0)
		buff_line[i] = (*store)[i];
	i = ft_getlen(*store) - ft_charfind(*store);
	if (i != ft_getlen(*store) && i > 0)
	{
		new_store = malloc(i + 1);
		new_store[i++] = '\0';
		j = ft_getlen(*store);
		while (i-- > 0)
			new_store[i] = (*store)[j--];
	}
	free(*store);
	*store = new_store;
	return (buff_line);
}
