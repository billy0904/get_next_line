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

char *split_line(char *str, char *save)
{
	int i;
	char *res;
	char *tmp;

	i = 0;
	if (!str)
		return (NULL);
	tmp = str;
	if (i < 0)
	{
		*save = NULL;
		return (str);
	}
	res = ft_substr(str, 0, i + 1);
	*save = ft_substr(str, i + 1, howlong(str));

	free(tmp);
	return (res);

	i = 0;
	while (str[i] == "\n")
	{
		i++;
	}
}

char *return_line(int fd)
{
	char *line;
	char *buffer;
}

char *get_next_line(int fd) // byte 크기가 잘 설정되었는지
{

	int byte;
	char *line;
	char buffer[BUFFER_SIZE + 1];
	static char *save;

	if (enter_exists(save) != -1)
		return (save에서 개행까지);
	while (1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0)
			return (return_line(남아있는 읽어온 애들));
		else if (byte >= 1)
		{
			if (enter_exists(buffer) == -1)
			{
				line = buffer; // 아직 리턴 전임
			}
			else // 개행이 있을 경우
			{
			}
		}

		else if (byte == -1)
		{
			asdf
		}
	}
	return (line);
}
