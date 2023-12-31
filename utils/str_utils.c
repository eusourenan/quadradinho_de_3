/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas-, rleite-s <adantas-@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:48 by adantas-, r       #+#    #+#             */
/*   Updated: 2023/10/20 20:25:23 by adantas-, r      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strchr(char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (s + index);
		++index;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		difference;

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
