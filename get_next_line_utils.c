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

char	*ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = 0;
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (howlong(s) <= start)
	{
		str = (char *)malloc(1);
		if (!str)
			return (0);
		*str = 0;
		return (str);
	}
	if (len > howlong(s) - start)
		len = howlong(s) - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
