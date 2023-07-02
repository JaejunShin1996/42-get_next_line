#include "get_next_line.h"

char    *join_free(char *buffer, char *temp)
{
    char    *joined;

    joined = ft_strjoin(buffer, temp);
    free(temp);
    return (joined);
}

char    *get_chunk_strings(int fd, char *buffer)
{
    char    *temp;
    int     read_size;

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

char    *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = get_chunk_strings(fd, buffer);
    line = (char *)ft_calloc(1, sizeof(char));
    // line to be returned.
    // buffer to be prepared for the next.
}