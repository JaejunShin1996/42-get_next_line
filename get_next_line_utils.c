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

void    *ft_memset(void *str, int c, size_t n)
{
    size_t          i;
    unsigned char   *temp;
    
    i = 0;
    temp = (unsigned char *)str;
    while (i < n)
    {
        temp[i] = c;
        i++;
    }
    return (str);
}

void    ft_bzero(void *str, size_t n)
{
    ft_memset(str, 0, n);
}

void    *ft_calloc(size_t nitems, size_t size)
{
    void    *result;
 
    result = malloc(nitems * size);
    if (result == NULL)
        return (NULL);
    ft_bzero(result, nitems * size);
    return (result);
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
        i++;
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

char    *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if (*str == c)
            return ((char *)str);
        str++;
    }
    if (*str == c)
        return ((char *)str);
    return (NULL);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;

    i = 0;
    if (size == 0)
    {
        while (src[i])
            i++;
        return (i);
    }
    while ((size-- > 1) && (src[i]))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    i = 0;
    while (src[i])
        i++;
    return (i);
}

char    *ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
    while (str[j])
        j++;
	result = (char *)malloc(sizeof(*result) * (j + 1));
	if (!(result))
		return (NULL);
	while (i < j)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}