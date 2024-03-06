/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:46:04 by jveirman          #+#    #+#             */
/*   Updated: 2023/12/09 17:39:16 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line_hunter(int fd, char *stash)
{
	char		*buf;
	ssize_t		nbr_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	nbr_bytes = 1;
	while (!ft_strchr(stash, '\n') && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nbr_bytes == -1)
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		buf[nbr_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] != '\n')
		next_line = ft_calloc(i + 1, sizeof(char));
	else
		next_line = ft_calloc(i + 2, sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		next_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		next_line[i] = stash[i];
	return (next_line);
}

static char	*ft_update_stash(char *stash)
{
	char	*updated_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	updated_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	if (!updated_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		updated_stash[j++] = stash[i++];
	free(stash);
	return (updated_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (0);
	}
	stash = ft_line_hunter(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	next_line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (next_line);
}
