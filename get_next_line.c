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

char	*split(char *str, char *save)
{
	int		i;
	char	*res;
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = str;
	if (i < 0)
	{
		*save = NULL;
		return (str);
	}

	free(tmp);
	return (res);

	i = 0;
	while(str[i] == "\n")
	{
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*save;

	if (save 안에 내용이 있을 경우)
		return (save);
	while (1)
	{
		line = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
