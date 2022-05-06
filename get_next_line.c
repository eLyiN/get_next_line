/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:46:24 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/06 11:05:29 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*mybuffer;
	char			*line;
	ssize_t			nbytes;

	mybuffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	nbytes = 1;
	line = NULL;
	// 1. read from fd and add to linked list.
	ft_read(&mybuffer, &nbytes, fd);
	if (mybuffer == NULL)
		return (NULL);
	// 2. extract from mybuffer to line.
	ft_ext_line(mybuffer, &line);
	// 3. clean the line from mybuffer.
	ft_clean_buffer(&mybuffer);
	if (line[0] == '\0')
	{
		free_buffer(mybuffer);
		mybuffer = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read(t_gnl **mybuffer, ssize_t *nbytes_ptr, int fd)
{
	char	*buff;

	// Asign memory to allocate our buff read.
	while (!found_newline(*mybuffer) && *nbytes_ptr != 0)
	{
		buff = malloc(sizeof(BUFFER_SIZE + 1));
		if (!buff)
			return ;
		*nbytes_ptr = read(fd, buff, BUFFER_SIZE);
		if ((!mybuffer && *nbytes_ptr == 0) || *nbytes_ptr == -1)
		{
			free(buff);
			return ;
		}
		//Always close the string with \0 after read it.
		buff[*nbytes_ptr] = '\0';
		ft_process(mybuffer, buff, *nbytes_ptr);
		free(buff);
	}
}
void	ft_process(t_gnl **mybuffer, char *buff, ssize_t nbytes)
{
	t_gnl	*last;
	t_gnl	*new_node;
	int		i;

	new_node = malloc(sizeof(t_gnl));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = malloc(sizeof(char) * ((nbytes + 1)));
	if (!new_node->data)
		return ;
	i = 0;
	while (buff[i] && i < nbytes)
	{
		new_node->data[i] = buff[i];
		i++;
	}
	new_node->data[i] = '\0';
	if (*mybuffer == NULL)
	{
		*mybuffer = new_node;
		return ;
	}
	last = ft_lst_get_last(*mybuffer);
	last->next = new_node;
}
void	ft_ext_line(t_gnl *mybuffer, char **line)
{
	int	i;
	int	j;

	if (mybuffer == NULL)
		return ;
	make_line(mybuffer, line);
	if (!line)
		return ;
	while (mybuffer)
	{
		i = 0;
		while (mybuffer->data[i])
		{
			if (mybuffer->data[i] == '\n')
			{
				(*line)[j++] = mybuffer->data[i];
				break ;
			}
			(*line)[j++] = mybuffer->data[i++];
		}
		mybuffer = mybuffer->next;
	}
	(*line)[j] = '\0';
}

// After extract our line, we have to clear the line characters
// and only leave the rest one to use in the next read section.

void	ft_clean_buffer(t_gnl **mybuffer)
{
	t_gnl *last;
	t_gnl *clean_node;
	int i;
	int j;

	clean_node = malloc(sizeof(t_gnl));
	if (mybuffer == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*mybuffer);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data[i] == '\n')
		i++;
	clean_node->data = malloc(sizeof(char) * ((ft_strlen(last->data) - i) + 1));
	if (!clean_node->data)
		return ;
	j = 0;
	while (last->data[i])
		clean_node->data[j++] = last->data[i++];
	clean_node->data[j] = '\0';
	free_buffer(*mybuffer);
	*mybuffer = clean_node;
}