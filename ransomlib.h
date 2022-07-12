/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:40:09 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/20 13:37:05 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANSOMLIB_H
# define RANSOMLIB_H
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		lens(const char *s);
int		find_nl(char *s);
char	*join(char *sol, char *buff);
char	*lectur(char *buff, int fd, int BUFFER_SIZE);
char	*the_line(char *buff);
char	*next_line(char *buff);
void    *ft_calloc(size_t nmemb, size_t size);
char    **ft_split(char const *s, char c);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void	fr_every_single_directory();





#endif
