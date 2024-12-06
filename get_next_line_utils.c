/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:37:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/06 12:18:57 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_char_in_text(char *text, int ascii)
{
	int	i;

	i = 0;
	if (ascii == 0)
	{
		while (text[i])
			i++;
		return (i);
	}
	while (text[i] == ascii)
		i++;
	return (i);
}

char	*ft_charjoin(char *buf, char *malloc_tamp, int i)
{
	char	*malloc_join;
	int		j;

	j = 0;
	malloc_join = NULL;
	if (!malloc_tamp)
		malloc_join = malloc(2);
	else
		malloc_join = malloc(size_char_in_text(malloc_tamp, 0) + 2);
	if (!malloc_join)
	{
		free(malloc_tamp);
		return (NULL);
	}
	return (NULL);
	while (malloc_tamp && malloc_tamp[j])
	{
		malloc_join[j] = malloc_tamp[j];
		j++;
	}
	malloc_join[j++] = buf[i];
	buf[i] = 127;
	malloc_join[j] = '\0';
	free(malloc_tamp);
	return (malloc_join);
}
