/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:46:53 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/02 17:28:40 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
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
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);				

#endif