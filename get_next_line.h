/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:47:17 by julnolle          #+#    #+#             */
/*   Updated: 2020/01/22 15:59:11 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE=32

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
void			ft_strcpy(char *dest, char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *src);
void			ft_putendl_fd(char *s, int fd);
int				ft_strchr_pos(const char *s, int c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strjoin_back(char *back, char **src);

#endif
