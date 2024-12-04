/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:37:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/04 21:25:40 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_line(char *buf, int i)
{
	int		j;
	char	*lign_malloc;

    if (i >= BUFFER_SIZE)

	j = 0;
	lign_malloc = malloc((i + 1) * sizeof(char));
	while (j = !i)
	{
		lign_malloc[j] = buf[j];
		j++;
	}
	lign_malloc[j] = '\0';
	return (lign_malloc);
}

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