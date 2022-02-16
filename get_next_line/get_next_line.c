/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoldyyk <zoldyyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:02:08 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/16 17:49:04 by zoldyyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t 	i;
	size_t	size;

	i = 0;
	if (!s1 || !s2)
		return(NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc((sizeof(char) * size));
	if (!str)
		return (NULL);
		while (*s1)
			str[++i] = *s1++;
		while(*s2)
			str[++i] = *s2++;
		str[i] = '\0';
		return (str);
}

char *get_next_line(int fd)
{
	static t_read	strct = {.fd = -1};
	char			*str;
	char			chara;
	
	str = NULL;
	if (strct.fd != fd)
	{
		if (!init_check(fd, &strct))
			return(NULL);
	}
	chara = read_check(&strct);
	while(chara)
	{
		str = ft_strjoin(str, &chara);
		if (chara == '\n')
			return(str);
		chara = read_check(&strct);
	}
	return (str);
}
	
	
