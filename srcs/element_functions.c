/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:26 by adantas-, r       #+#    #+#             */
/*   Updated: 2023/10/25 16:52:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	validate_element(char *line)
{
	char		**splited;
	static char	*matched[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	const char	*elements[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	static int	matches;
	int			i;

	i = 0;
	while (i < 6 && ft_strncmp(elements[i], line, ft_strlen(elements[i])) != 0)
		++i;
	if (i == 6)
		return (-1);
	if (matched[i] != NULL)
		return (you_made_the_l("Duplicated element."));
	matched[i] = (char *)elements[i];
	matches++;
	splited = ft_split(line, ' ');
	if (splited[1] == NULL || splited[2] != NULL
		|| (i >= 4 && has_invalid_color(splited + 1)))
		matches = -1;
	ft_free_matrix((void **)splited);
	return (matches);
}

void	normalize_element(char *start)
{
	char	*end;

	end = start;
	while (*end && *end == ' ')
		end++;
	if (start != end)
		ft_memmove(start, end, ft_strlen(end) + 1);
	while (*start)
	{
		if (*start == ' ')
		{
			end = start + 1;
			while (*end && *end == ' ')
				end++;
			if (start + 1 != end)
				ft_memmove(start + 1, end, ft_strlen(end) + 1);
		}
		if ((*start == '\n' || *start == '\r') && start[1] == '\0')
			*start = 0;
		if (*start)
			start++;
	}
}

static int	match_validate(char *line, int match)
{
	if (!line && !match)
		return (you_made_the_l("Empty file.") * 7);
	else if (!line)
		return (you_made_the_l("Read corruption, or the file ends too soon."));
	if (line[0] != '\n')
	{
		normalize_element(line);
		match = validate_element(line);
	}
	return (match);
}

int	element_checker(char *filename)
{
	int		fd;
	char	*line;
	int		match;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (you_made_the_l("Error while trying open the file."));
	match = 0;
	while (match != 6)
	{
		line = get_next_line(fd);
		match = match_validate(line, match);
		free(line);
		if (match <= -1)
			break ;
	}
	close(fd);
	get_next_line(-1);
	if (match == -1)
		return (you_made_the_l("Invalid element."));
	if (match < -1)
		return (-1);
	return (0);
}
