/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:39:20 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/24 14:24:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int 	i;

	i = 0;
	if (argc < 2)
		return (-1);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	printf("{ %i }\n",i);

/*while (i++ < 1)
{
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
}*/
	close(fd);
	return (0);
}
