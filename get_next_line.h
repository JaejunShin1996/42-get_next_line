#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_putendl_fd(char *s, int fd);
int     read_fd(char *file_name);
char    *ft_strjoin(char const *str1, char const *str2);
size_t  ft_strlen(const char *str);

#endif