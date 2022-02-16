/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoldyyk <zoldyyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:07:59 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/16 17:41:28 by zoldyyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init_check(int fd, t_read *strct)
{
	strct->pos = 0;
	strct->fd = fd;
	strct->max = read(fd, strct->str, BUFFER_SIZE);
	if (strct->max <= 0)
		return (0);
	else
		return(1);
}

char read_check(t_read *strct)
{
	char	result;
	
	if (strct->pos >= strct->max)
	{
		strct->max = read(strct->fd, strct-> str, BUFFER_SIZE);
		strct->pos = 0;
		if (strct->max <= 0)
			return (0);
	}
	result = strct->str[strct->pos];
	strct->pos++;
	return (result);
}