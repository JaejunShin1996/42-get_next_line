/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:02:38 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/22 14:03:30 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *buffer, char *temp)
{
	char	*joined;

	joined = ft_strjoin(buffer, temp);
	free(buffer);
	return (joined);
}

char	*get_chunk_strings(int fd, char *buffer)
{
	char	*temp;
	int		read_size;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_size] = '\0';
		buffer = join_free(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_return_line(char *chunk)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!chunk[i])
		return (NULL);
	while (chunk[i] && chunk[i] != '\n')
		i++;
	result = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (chunk[i] && chunk[i] != '\n')
	{
		result[i] = chunk[i];
		i++;
	}
	if (chunk[i] && chunk[i] == '\n')
		result[i] = '\n';
	result[i + 1] = '\0';
	return (result);
}

char	*get_ready_for_next(char *chunk)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (chunk[i] && chunk[i] != '\n')
		i++;
	if (!chunk[i])
	{
		free(chunk);
		return (NULL);
	}
	result = (char *)ft_calloc(ft_strlen(chunk) - i + 1, sizeof(char));
	i++;
	while (chunk[i])
		result[j++] = chunk[i++];
	result[j] = '\0';
	free(chunk);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_chunk_strings(fd, buffer);
	line = get_return_line(buffer);
	buffer = get_ready_for_next(buffer);
	return (line);
}
