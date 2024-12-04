/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:37:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/04 21:54:05 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	end_lign(char *buf, int i)
{
    while (!buf[i])
    {
        if (buf[i]==127)
        {
            buf[i] = '\n';
            i++;
        }   
        if (buf[i+1]=='\n')
        {
            buf[i] = 127;
            return (i);
        }
        i++;
    }
    return i; 
}

char *get_line(char *buf, int i, int end)
{
    int size;
    char *malloc_lign;
    int j;
    
    size = end - (++i);
    malloc_lign = malloc(size * sizeof(char));
    if (!malloc_lign)
        return NULL;
    j = 0;
    while(i <= end)
        malloc_lign[j++] = buf[i++];       
    return malloc_lign;
}