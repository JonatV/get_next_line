/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:49:04 by jveirman          #+#    #+#             */
/*   Updated: 2023/12/09 17:45:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *line, char *buf);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif