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

int enter_exists(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char *read_line(int fd, char **save)
{
	char buffer[BUFFER_SIZE + 1];
	int byte;

	while (enter_exists(*save) != -1)
	{
		if (!*save)
			return (NULL);
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0)
			return (*save);
		else if (byte == -1)
			return (ft_free(save));
		buffer[byte] = '\0';
		*save = ft_strjoin(*save, buffer, save);
	}
	return (*save);
}

char *return_line(char *save)
{
	char *line;
	int i;

	i = 0;
	if (!save[i])
		return (NULL);
	if (enter_exists(save) != -1)
		i = enter_exists(save) + 1;
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
		line[i] = save[i];
	i++;
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	save = read_line(fd, &save);
	if (save == NULL)
		return (NULL);
	line = return_line(save);
	if (!line)
		return (ft_free(&save));
	return (line);
}
