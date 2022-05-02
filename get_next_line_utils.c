/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:50:36 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/02 17:28:38 by aarribas         ###   ########.fr       */
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

char    *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == c || *s == '\0')
                return ((char *)s);
                else
                {
                        s++;
                }
        }
        if (*s == c)
        {
                return ((char *)s);
        }
        return (NULL);
}

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *new_str;
    size_t i;
    size_t j;

    if(s1 && s2)
    {
    if(!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)))))
    return (NULL);
    i = 0;
    while(s1[i] != '\0')
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j] != '\0')
    {
        new_str[i] = s2[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
    }
    return (NULL);
}