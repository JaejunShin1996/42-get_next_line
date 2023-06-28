#include "get_next_line.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

void    ft_putnbr_fd(int n, int fd)
{
    unsigned int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = n * -1;
	}
	if (9 < i)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	ft_putchar_fd(i % 10 + '0', fd);
}

void    ft_putendl_fd(char *s, int fd)
{
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
    ft_putchar_fd('\n', fd);
}

int read_fd(char *file_name)
{
    int     fd;

    fd = open(file_name, O_RDONLY);
    return (fd);
}

size_t  ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strjoin(char const *str1, char const *str2)
{
    char    *result;
    int     i;
    int     j;

    i = 0;
    j = 0;
    result = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
    if (result == NULL)
        return (NULL);
    while (str1[i])
    {
        result[i] = str1[i];
        i++;
    }
    while (str2[j])
    {
        result[i + j] = str2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}