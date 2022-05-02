/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:46:53 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/01 23:46:53 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define FD_SIZE 404
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
#

char    *get_next_line(int fd);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strdup(const char *s);
typedef struct s_node
{
	char    *data;
	s_node	*next;
}           s_node;					

#endif