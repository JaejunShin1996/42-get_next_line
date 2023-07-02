#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *buffer;
    char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
    line = (char *)ft_calloc(1, sizeof(char));
    while (read(fd, buffer, 1) == 1)
    {
        line = ft_strjoin(line, buffer);
        if (*buffer == '\n')
        {
            free(buffer);
            return (line);
        }
    }

    free(buffer);
    return (ft_strlen(line) > 0 ? line : NULL);
}