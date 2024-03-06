/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:04:04 by jveirman          #+#    #+#             */
/*   Updated: 2023/12/09 16:34:15 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len_tot;
	void	*the_memory;
	size_t	i;

	i = -1;
	len_tot = count * size;
	the_memory = malloc(len_tot);
	if (the_memory)
	{
		while (++i < len_tot)
			((char *)the_memory)[i] = '\0';
		return (the_memory);
	}
	free(the_memory);
	return (NULL);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *stash, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buf)
		return (NULL);
	str = ft_calloc(((ft_strlen(stash) + ft_strlen(buf)) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i] != '\0')
		str[i] = stash[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	free(stash);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
	{
	}
	return (i);
}
