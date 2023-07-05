#include "get_next_line.h"

char    *join_free(char *buffer, char *temp)
{
    char    *joined;

    joined = ft_strjoin(buffer, temp);
    free(buffer);
    return (joined);
}

char    *get_chunk_strings(int fd, char *buffer)
{
    char    *temp;
    int     read_size;

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
            break;
    }
    free(temp);
    return (buffer);
}

char    *get_return_line(char * dest, char *chunk)
{
    size_t  i;

    i = 0;
    if (!(*chunk))
        return (NULL);
    while (chunk[i] && chunk[i] != '\n')
        i++;
    dest = (char *)ft_calloc(i + 1, sizeof(char));
    i = 0;
    while (chunk[i] && chunk[i] != '\n')
    {
        dest[i] = chunk[i];
        i++;
    }
    if (chunk[i] == '\n')
        dest[i++] = '\n';
    dest[i] = '\0';
    return (dest);
}

char    *get_ready_for_next(char *chunk)
{
    char    *result;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (chunk[i] && chunk[i] != '\n')
        i++;
    result = (char *)ft_calloc(ft_strlen(chunk) - i + 1, sizeof(char));
    i++;
    while (chunk[i])
        result[j++] = chunk[i++];
    result[j] = '\0';
    free(chunk);
    return (result);
}

char    *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    buffer = get_chunk_strings(fd, buffer);
    line = (char *)ft_calloc(1, sizeof(char));
    // line to be returned.
    line = get_return_line(line, buffer);
    // buffer to be prepared for the next.
    buffer = get_ready_for_next(buffer);
    return (line);
}