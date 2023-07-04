#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *get_next_line(int fd);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_bzero(void *str, size_t n);
void    *ft_calloc(size_t nitems, size_t size);
int     read_fd(char *file_name);
char    *ft_strjoin(char const *str1, char const *str2);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char    *ft_strdup(const char *str);

#endif