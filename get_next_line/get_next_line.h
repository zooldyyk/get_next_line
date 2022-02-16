/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoldyyk <zoldyyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:02:19 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/16 17:48:46 by zoldyyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_read
{
	int		fd;
	int		max;
	int		pos;
	char	str[BUFFER_SIZE];
}	t_read;

size_t  ft_strlen(char	*str);
char    *ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int	    init_check(int fd, t_read *strct);
char    read_check(t_read *strct);
#endif
