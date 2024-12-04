/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:34 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/04 21:10:55 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *buf, int i, int end);
int	end_lign(char *buf, int i);

#endif