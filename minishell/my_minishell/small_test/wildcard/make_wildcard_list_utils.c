#include "../minishell.h"
#include "../libft/libft.h"

int	check_wc_list(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s1[i] != 0)
	{
		if (s2[j] == '*')
			flag = star_case(s1, &i, s2, &j);
		else
			flag = other_case(s1, &i, s2, &j);
		if (flag == 1)
			return (1);
	}
	return (0);
}

int	star_case(char *s1, int *i, char *s2, int *j)
{
	while (s2[*j] == '*')
		(*j)++;
	while (1)
	{
		while (s1[*i] != 0 && s1[*i] != s2[*j])
			(*i)++;
		if (check_case(s1, i, s2, j) == 0)
			break ;
	}
	if (s1[*i] != 0 && s2[*j] == 0)
		return (1);
	if (s1[*i] == 0 && s2[*j] != '*' && s2[*j] != 0)
		return (1);
	return (0);
}

int	check_case(char *s1, int *i, char *s2, int *j)
{
	int	idx;

	idx = 0;
	while (s2[*j + idx] != 0 && s2[*j + idx] != '*')
		idx++;
	if (s1[*i] == 0)
		return (0);
	if (ft_strncmp(&s1[*i], &s2[*j], idx) == 0)
	{
		*i = *i + idx;
		*j = *j + idx;
		return (0);
	}
	(*i)++;
	return (1);
}

int	other_case(char *s1, int *i, char *s2, int *j)
{
	if (s1[*i] != s2[*j])
		return (1);
	(*i)++;
	(*j)++;
	return (0);
}
