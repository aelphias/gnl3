/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:24:50 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/21 20:13:12 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# define MAX_FD_NUM 11000
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
