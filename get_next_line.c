/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/09 21:10:50 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	size_t		i;
	char		*malloc_tamp;

	malloc_tamp = NULL;
	i = size_char_in_text(buf, 127);
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	malloc_tamp = line_by_line(buf, i, fd, malloc_tamp);
	return (malloc_tamp);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// char	*get_next_line(int fd);

// int	main(void)
// {
// 	int fd = open("bible.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}
// 	int i = 0;
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		i++;
// 		printf("%d : %s", i, line);
// 		if (i == 10000)
// 		{
// 			close(fd);
// 		}
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }