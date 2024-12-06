/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/06 02:19:17 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_charjoin(char *buf, char *malloc_tamp, int i)
{
	char	*malloc_join;
	int		j;

	j = 0;
	malloc_join = NULL;
	if (!malloc_tamp)
	{
		malloc_join = malloc(2);
		if (!malloc_join)
			return (NULL);
	}
	else
	{
		while (malloc_tamp[j])
			j++;
		malloc_join = malloc(j + 2);
		j = 0;
		while (malloc_tamp[j])
		{
			malloc_join[j] = malloc_tamp[j];
			j++;
		}
	}
	malloc_join[j++] = buf[i];
	buf[i] = 0;
	malloc_join[j] = '\0';
	free(malloc_tamp);
	return (malloc_join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	int			i;
	char		*malloc_tamp;
	
	malloc_tamp = NULL;
	while ((buf[BUFFER_SIZE - 1] != 0 && buf[BUFFER_SIZE - 1]) || read(fd, buf,
			BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buf[i] == 127)
			i++;
		while (i < BUFFER_SIZE)
		{
			malloc_tamp = ft_charjoin(buf, malloc_tamp, i);
			if (malloc_tamp == NULL)
				return (NULL);
			if (buf[i + 1] == '\n')
			{
				malloc_tamp = ft_charjoin(buf, malloc_tamp, i + 1);
				return (malloc_tamp);
			}
			i++;
		}
	}
	return (malloc_tamp);
}

int	main(void)
{
	int fd;
	char *str;
	int i = 1;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("line %d : %s", i++, str);
		free(str);
		str = get_next_line(fd);
		if (!str)
			printf("\nEOF\n");
	}
	close(fd);
}