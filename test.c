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
	if (!malloc_tamp)
	{
		malloc_join = malloc(2);
		if (!malloc_join)
			return (NULL);
		malloc_join[0] = buf[i];
		malloc_join[1] = '\0';
	}
	else
	{
		while (malloc_tamp[j])
			j++;
		malloc_join = malloc(j + 2);
		if (!malloc_join)
			return (NULL);
		j = 0;
		while (malloc_tamp[j])
		{
			malloc_join[j] = malloc_tamp[j];
			j++;
		}
		malloc_join[j++] = buf[i];
		malloc_join[j] = '\0';
		free(malloc_tamp);
	}
	buf[i] = 0;
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
			if (buf[i] == '\n')
			{
				buf[i] = 0;
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
		printf("line %d : %s\n", i++, str);
		free(str);
		str = get_next_line(fd);
		if (!str)
			printf("EOF\n");
	}
	close(fd);
}