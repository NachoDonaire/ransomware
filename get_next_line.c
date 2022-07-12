/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:19:29 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/20 13:29:52 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ransomlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*join(char *sol, char *buff)
{
	char	*solu;

	solu = ft_strjoin(sol, buff);
	if (sol)
		free(sol);
	return (solu);
}

char	*lecture(char *buff, int fd, int BUFFER_SIZE)
{
	int		lec;
	char	*sol;

	if (!buff)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	lec = 1;
	sol = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (lec > 0)
	{
		lec = read(fd, sol, BUFFER_SIZE);
		if (lec < 0)
		{
			free(buff);
			free(sol);
			return (NULL);
		}
		sol[lec] = '\0';
		buff = join(buff, sol);
		if (find_nl(buff))
			break ;
	}
	free(sol);
	return (buff);
}

char	*the_line(char *buff)
{
	char	*sol;
	int		i;

	i = 0;
	if (!buff[i])
	{
		return (NULL);
	}
	while (buff[i] && buff[i] != '\n')
		i++;
	sol = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		sol[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
	{
		sol[i] = buff[i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}

char	*next_line(char *buff)
{
	int		i;
	char	*sol;
	int		y;

	i = 0;
	y = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	else if (buff[i] == '\n')
		i++;
	sol = ft_calloc((lens(buff) - i + 1), sizeof(char));
	while (buff[i])
		sol[y++] = buff[i++];
	sol[y] = '\0';
	if (buff)
		free(buff);
	return (sol);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*sol;
	int		BUFFER_SIZE;

	BUFFER_SIZE = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = lecture(buff[fd], fd, BUFFER_SIZE);
	if (!buff[fd])
		return (NULL);
	sol = the_line(buff[fd]);
	buff[fd] = next_line(buff[fd]);
	return (sol);
}
/*
int	main()
{
	int	fd;
	int	fd2;
	char	*buff;

	fd = open("1.txt", O_RDONLY);
	fd2 = open("files", O_RDONLY);
	buff = get_next_line(fd);
	printf("%s", buff);
	while (buff)
	{
		buff = get_next_line(fd);
		printf("%s", buff);
	}
	buff = get_next_line(fd2);
	printf("%s", buff);
	return (0);
}
*/
/*
int main()
  {
    int fd;
    char *s;
	char *s2;
  //char *s3;
//char *s4 ;
//char *s5;
//char *s6;
//	char *s7;
//	char *s8;
//	char *s9;

    fd = open("multiple_line_with_nl", O_RDONLY);
  s = get_next_line(fd);
   printf("%s", s);
  s2 = get_next_line(fd);
  printf("%s", s2);
 //s3 = get_next_line(fd);
 //printf("%s", s3);

   //y = n_char_fd(fd);
   //printf("%d", y);
 //s4 = get_next_line(fd);
 //printf("%s", s4);
 //s5 = get_next_line(fd);
 //printf("%s", s5);

//s6 = get_next_line(fd);
// s7 = get_next_line(fd);
 //s8 = get_next_line(fd);
 //s9 = get_next_line(fd);

 //printf("%s", s6);
 //printf("%s", s7);
 //printf("%s", s8);
 //printf("%s", s9);
  //system("leaks a.out");
  return (0);
  }*/
