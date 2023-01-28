#ifndef GET_NEXT_LINE_ARRAY_H
#define GET_NEXT_LINE_ARRAY_H

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define OPEN_MAX 256

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);

#endif