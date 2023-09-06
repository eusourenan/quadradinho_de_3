
#include "cube.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*dup;

	len = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	while (s[len])
		len++;
	dup = malloc (++len);
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = s[len];
	return (dup);
}

char	*ft_strrchr(char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index)
	{
		if (s[index] == c)
			return (s + index);
		--index;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int		difference;
	size_t	index;

	if (n == 0)
		return (0);
	while (n)
	{
		difference = (int)*s1++ - (int)*s2++;
		if (difference != 0)
			return (difference);
		--n;
	}
	return (difference);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strrchr(set, s1[start]) != NULL)
		++start;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strrchr(set, s1[end]) != NULL)
		--end;
	trimmed = malloc(end - start + 1);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = 0;
	return (trimmed);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		difference;

	while (*s1 != '\0' && *s2 != '\0')
	{
		difference = (int)*s1++ - (int)*s2++;
		if (difference != 0)
			return (difference);
	}
	difference = (int)*s1 - (int)*s2;
	return (difference);
}
