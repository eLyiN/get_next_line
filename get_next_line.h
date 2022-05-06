/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:46:53 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/06 11:03:23 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			*data;
}					t_gnl;
char				*get_next_line(int fd);
size_t				ft_strlen(const char *str);
t_gnl				*ft_lst_get_last(t_gnl *mybuffer);
void				ft_read(t_gnl **mybuffer, ssize_t *nbytes_ptr, int fd);
void				ft_process(t_gnl **mybuffer, char *buff, ssize_t nbytes);
void				ft_ext_line(t_gnl *mybuffer, char **line);
void				ft_clean_buffer(t_gnl **mybuffer);
int					found_newline(t_gnl *mybuffer);
void				make_line(t_gnl *mybuffer, char **line);
void				free_buffer(t_gnl *mybuffer);

#endif