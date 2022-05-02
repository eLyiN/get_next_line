/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:50:36 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/02 08:50:36 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        unsigned char *dest_temp;
        unsigned char *src_temp;
        size_t i;

        i = 0;
        dest_temp = (unsigned char *)dest;
        src_temp = (unsigned char *)src;

        if (dest == NULL && src == NULL)
                return (NULL);
        while (i < n)
        {
                dest_temp[i] = src_temp[i];
                i++;
        }
        return (dest);
}

char    *ft_strdup(const char *s)
{
    char *str;
    int i;

    i = 0;
    if(!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
    {
        return (NULL);
    }
                while (s[i])
                {
                        str[i] = (char)s[i];
            i++;
                }
        str[i] = '\0';
    return (str);
}