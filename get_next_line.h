/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:41:47 by gablee            #+#    #+#             */
/*   Updated: 2023/12/02 20:41:50 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFF_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

#endif
