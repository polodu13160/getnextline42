/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/04 21:14:49 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE+1] = "\0";
	int			i;
	int			start_ope_bool;
	int			end;

	if (fd == -1)
		return (1);
	i = 0;
	if (buf[i] == '\0')
	{
		read(fd, buf, BUFFER_SIZE);
		start_ope_bool = 1;
	}
	while (buf[i])
	{
		if (start_ope_bool == 1 && i == 0)
			break ;
		if ((!buf[++i] || buf[i] == 127))
			break ;
	}
	return (get_line(buf, i, end_lign(buf, i)));
}

int	main(void)
{
	int fd = "text.txt";
	printf("%s", get_next_line(open(fd)));
	close(fd);
}