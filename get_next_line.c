/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/06 04:41:06 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "\0";
	int			i;
	char		*malloc_tamp;

	malloc_tamp = NULL;
	i = 0;
	while (buf[i] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		i = size_char_in_text(buf, 127);
		while (buf[i])
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
#include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *str;
// 	int i = 1;

// 	fd = open("one_line_no_nl.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("line %d : %s", i++, str);
// 		free(str);
// 		str = get_next_line(fd);
// 		if (!str)
// 			printf("\nEOF\n");
// 	}
// 	close(fd);
// }