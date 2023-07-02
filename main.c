#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *one_line;

    fd = read_fd("text.txt");
    while ((one_line = get_next_line(fd)) != NULL)
    {
        ft_putstr_fd(one_line, 1);
    }
    return (0);
}