/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/06 12:19:31 by pde-petr         ###   ########.fr       */
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
	while ((buf[i] && buf[i] != 127) || read(fd, buf, BUFFER_SIZE) > 0)
	{
		i = size_char_in_text(buf, 127);
		while (buf[i] && buf[i] != 127)
		{
			if (buf[i] == '\n')
			{
				malloc_tamp = ft_charjoin(buf, malloc_tamp, i);
				if (malloc_tamp == NULL)
					return (NULL);
				return (malloc_tamp);
			}
			malloc_tamp = ft_charjoin(buf, malloc_tamp, (i++));
			if (malloc_tamp == NULL)
				return (NULL);
		}
	}
	return (malloc_tamp);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// void	check(int condition)
// {
// 	if (!condition)
// 	{
// 		fprintf(stderr, "Test failed\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	gnl(int fd, char const *expectedReturn)
// {
// 	char	*gnlReturn;
// 	int		i;

// 	gnlReturn = get_next_line(fd);
// 	if (expectedReturn == NULL)
// 		check(gnlReturn == NULL);
// 	else
// 	{
// 		printf("\nce que je renvoie	%s\n", gnlReturn);
// 		printf("\nce que je dois renvoyer	%s\n", expectedReturn);
// 		printf("d   %d", strcmp(gnlReturn, expectedReturn));
// 		i = 0;
// 		// while (gnlReturn[i] != 127)
// 		// {
// 		// 	i++;
// 		// }
// 		printf("\nici %c\n", gnlReturn[i - 1]);
// 		check(!strcmp(gnlReturn, expectedReturn));
// 	}
// 	check(!strcmp(gnlReturn, expectedReturn));
// 	free(gnlReturn);
// }

// int	main(void)
// {
// 	int fd;

// 	fd = open("one_line_no_nl.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}

// 	// Test pour vérifier si la ligne lue est correcte
// 	gnl(fd, "012345");
// 	// Test pour vérifier qu'il n'y a plus de ligne à lire
// 	gnl(fd, NULL);

// 	close(fd);
// 	printf("Tous les tests ont réussi.\n");
// 	return (0);
// }