#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;

	if (fd == -1)
	{
		ft_putendl_fd("Failed to open the text file.\n", 2);
		return (NULL);
	}

    buffer = (char *)malloc(sizeof(char) * 1);
    line = (char *)malloc(sizeof(char) * 1);
    while (read(fd, buffer, 1) == 1 && *buffer != '\n')
    {
        line = ft_strjoin(line, buffer);
    }

    free(buffer);
    return (line);
}