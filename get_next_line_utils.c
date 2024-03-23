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

size_t	howlong(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*free_save(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = 0;
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				len;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	len = 0;
	if (dst && !src)
		return (0);
	if (size == 0)
		return (howlong(src));
	while (src[len] && len < size - 1)
	{
		d[len] = s[len];
		len++;
	}
	d[len] = '\0';
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2, char **ptr)
{
	size_t		len;
	char		*result;

	if (!(str1 || str2))
		return (NULL);
	else if (!str1)
		return (ft_strdup(str2));
	len = howlong(str1) + howlong(str2) + 1;
	result = (char *)malloc(sizeof(char) * len);
	if (!result)
	{
		free(*ptr);
		return (NULL);
	}
	ft_strlcpy(result, str1, howlong(str1) + 1);
	ft_strlcpy(result + howlong(str1), str2, howlong(str2) + 1);
	free(*ptr);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = howlong(s1) + 1;
	if (len == 1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * len);
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
