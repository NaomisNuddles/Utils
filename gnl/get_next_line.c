/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:40 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/31 23:39:17 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	dat;
	char			*res;

	if (fd < 0 || fd > MAX_FD - 1 || BUFFER_SIZE <= 0)
		return (0);
	dat.size = read(fd, dat.lag, BUFFER_SIZE);
	res = NULL;
	while (dat.size > 0 || (!dat.size && dat.rem[fd].buff && *dat.rem[fd].buff))
	{
		if (dat.size)
			dat.rem[fd].buff = buff_save(dat.rem[fd].buff, dat.lag);
		if (!dat.rem[fd].buff && dat.size)
			return (NULL);
		if (line_check(dat.rem[fd].buff) || !dat.size)
		{
			res = line_pull(dat.rem[fd].buff, line_check(dat.rem[fd].buff));
			if (!res)
				break ;
			return (res);
		}
		dat.size = read(fd, dat.lag, BUFFER_SIZE);
	}
	free(dat.rem[fd].buff);
	dat.rem[fd].buff = NULL;
	return (NULL);
}
