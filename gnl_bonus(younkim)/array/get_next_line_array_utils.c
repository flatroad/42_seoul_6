#include "get_next_line_array.h"

size_t ft_strlen(const char *s)
{
	int cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	i = -1;
	while (c > 127)
		c -= 128;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}

char *ft_strdup(const char *s)
{
	size_t buf_size;
	size_t i;
	char *buf;

	i = 0;
	buf_size = ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * (buf_size + 1));
	if (buf == NULL)
		return (0);
	while (i < buf_size && s[i])
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = 0;
	return (buf);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_size;
	size_t s2_size;
	size_t i;
	char *str;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = (char *)malloc(s1_size + s2_size + 1);
	if (!str)
		return (NULL);
	while (i < s1_size)
		str[i++] = *s1++;
	while (i < s1_size + s2_size)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}
