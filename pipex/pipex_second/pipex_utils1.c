#include "pipex.h"

// strncmp 함수, strjoin 함수, strlen, 함수
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (s1[len] != s2[len])
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		if (s1[len] == 0 && s2[len] == 0)
			return (0);
		len++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == 0)
		return (0);
	ptr = memmove(ptr, s1, s1_len);
	ptr = memmove((ptr + s1_len), s2, s2_len);
	ptr = (ptr - s1_len);
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}
