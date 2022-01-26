/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:55 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/13 16:35:48 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char	*s);
size_t	ft_strle(const char	*s);
char	*ft_substr(char	*s, unsigned int start, size_t	len);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif
