/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:41:59 by gablee            #+#    #+#             */
/*   Updated: 2023/12/02 20:42:02 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t howlong(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = 0;
	return (NULL);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int len;
	char *arr;

	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		arr[0] = 0;
		return (arr);
	}
	len = sslen(size, strs) + (howlong(sep) * (size - 1)) + 1;
	arr = (char *)malloc(sizeof(char) * len);
	i = 0;
	if (arr == 0)
		return (0);
	arr[0] = 0;
	while (i < size - 1)
	{
		scat(arr, strs[i]);
		scat(arr, sep);
		i++;
	}
	scat(arr, strs[i]);
	return (arr);
}

char *ft_strdup(const char *s1)
{
	int len;
	int i;
	char *dup;

	i = 0;
	len = howlong(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}