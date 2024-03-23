/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:41:32 by gablee            #+#    #+#             */
/*   Updated: 2023/12/02 20:41:34 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*enter_exists(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*read_line(int fd, char **save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		byte;

	while (enter_exists(*save) == NULL)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0)
			return (*save);
		else if (byte == -1)
			return (free_save(save));
		buffer[byte] = '\0';
		*save = ft_strjoin(*save, buffer, save);
		if (!*save)
			return (NULL);
	}
	return (*save);
}

char	*initialize_save(char **save)
{
	char	*new;
	char	*enter;

	enter = enter_exists(*save);
	if (enter == NULL)
		return (free_save(save));
	new = ft_strdup(enter + 1);
	if (!new)
		return (free_save(save));
	free_save(save);
	return (new);
}

char	*return_line(char *save, int i)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	save = read_line(fd, &save);
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = return_line(save, i);
	if (!line)
		return (free_save(&save));
	save = initialize_save(&save);
	return (line);
}
