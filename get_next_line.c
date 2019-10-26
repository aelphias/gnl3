/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:25:00 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/24 21:51:24 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char **line, int fd, char *left[MAX_FD_NUM])
{
	char *pos;
	char *tmp;

	tmp = ft_strdup(left[fd]);
	if ((pos = ft_strchr(tmp, '\n')))
	{
		*pos = '\0';
		*line = ft_strdup(tmp);
		pos++;
		if (*pos == '\0')
		{
			free(left[fd]);
			left[fd] = NULL;
			free(tmp);
			return (1);
		}
		left[fd] = ft_strdup(pos);
		free(tmp);
		return (1);
	}
	else
		{
			free(tmp);
			return (0);
		}

}

int	get_next_line(const int fd, char **line)
{
	static char *left[MAX_FD_NUM];
	char		*tmp;
	char		b[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd > 11000 || read(fd, NULL, 0) < 0)
		return (-1);
	if (left[fd] && ft_strchr(left[fd], '\n'))
		return (ft_check(line, fd, left));
	while ((ret = read(fd, b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		if (left[fd] == NULL)
			left[fd] = ft_strdup(b);
		else
		{
			tmp = left[fd];
			left[fd] = ft_strjoin(left[fd], b);
			free(tmp);
		}
		if (ft_check(line, fd, left))
			return (1);
	}
	if (left[fd])
	{
		*line = ft_strdup(left[fd]);
		free(left[fd]);
		left[fd] = NULL;
		return (1);
	}
	return (0);
}
