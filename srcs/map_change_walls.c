/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas-, rleite-s <adantas-@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:57:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 10:59:27 by adantas-, r      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_walls(char **map)
{
	int	y;
	int	x;

	if (!map || !*map)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
				map[y][x] = '1';
			++x;
		}
		++y;
	}
}
