#include "libft.h"

static size_t	ft_check_f(char const *s1, char const *set)
{
	size_t	idx;
	size_t	len_f;

	idx = 0;
	len_f = 0;
	while (*s1 != 0)
	{
		while (set[idx] != s1[len_f] && set[idx] != 0)
			idx++;
		if (set[idx] == 0)
			break ;
		idx = 0;
		len_f++;
	}
	return (len_f);
}

static size_t	ft_check_r(char const *s1, char const *set, size_t len)
{
	size_t	idx;
	size_t	len_r;

	idx = 0;
	len_r = 0;
	while (len_r < len)
	{
		while (set[idx] != s1[(len - 1) - len_r] && set[idx] != 0)
			idx++;
		if (set[idx] == 0)
			break ;
		idx = 0;
		len_r++;
	}
	len_r = len - len_r;
	return (len_r);
}

char	*pull_str(char const *s1, char *str, size_t len_f, size_t len_r)
{
	size_t	idx;

	idx = 0;
	while (len_f < len_r)
	{
		str[idx] = s1[len_f];
		idx++;
		len_f++;
	}
	str[idx] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	len_f;
	size_t	len_r;
	char	*str;

	if (s1 == 0 || set == 0)
		return (0);
	len = ft_strlen(s1);
	len_f = ft_check_f(s1, set);
	len_r = ft_check_r(s1, set, len);
	if (len_r == 0)
		str = (char *)malloc(sizeof(char) * (1));
	else
		str = (char *)malloc(sizeof(char) * (len_r - len_f + 1));
	if (str == 0)
		return (0);
	str = pull_str(s1, str, len_f, len_r);
	return (str);
}
