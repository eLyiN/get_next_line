/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:50:36 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/06 11:05:21 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	found_newline(t_gnl *mybuffer)
{
	int		i;
	t_gnl	*current;

	if (mybuffer == NULL)
		return (0);
	current = ft_lst_get_last(mybuffer);
	i = 0;
	while (current->data[i])
	{
		if (current->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnl	*ft_lst_get_last(t_gnl *mybuffer)
{
	t_gnl	*current;

	current = mybuffer;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	make_line(t_gnl *mybuffer, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (mybuffer)
	{
		i = 0;
		while (mybuffer->data[i])
		{
			if (mybuffer->data[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		mybuffer = mybuffer->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_buffer(t_gnl *mybuffer)
{
	t_gnl *current;
	t_gnl *next;

	current = mybuffer;
	while (current)
	{
		free(current->data);
		next = current->next;
		free(current);
		current = next;
	}
}