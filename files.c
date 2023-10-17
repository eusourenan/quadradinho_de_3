/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas-, rleite-s <adantas-@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:31:56 by adantas-, r       #+#    #+#             */
/*   Updated: 2023/10/17 12:21:07 by adantas-, r      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"
# include "mlx_test.h"
int	error_checker(int argc, char *argv[])
{
	char	*file;
	int		fd;

	if (argc != 2)
		return (you_made_the_l("Make the L!"));
	file = argv[1];
	if (ft_strlen(file) < 5 || ft_strrchr(file, '.') == NULL \
	|| ft_strcmp(ft_strrchr(file, '.'), ".cub"))
		return (you_made_the_l("Make the L! 2"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (you_made_the_l("Make the L! 3"));
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map;
	char	*attributes[7];
	t_mlx	mlx;

	mlx = (t_mlx){0};
	if (error_checker(argc, argv))
		return (1);
	if (element_checker(argv[1], map))
		return (1);
	map = get_map(argv[1]);
	if (map == NULL)
		return (1);
	ft_memset(attributes, 0, sizeof(char *[7]));
	if (get_view_attributes(attributes, argv[1]))
	{
		ft_free_matrix((void **)map);
		return (1);
	}
	*g_map() = map;
	mlx.attributes = attributes;
	make_it_visual(&mlx);
	ft_free_matrix((void **)map);
	free_local_matrix(attributes);
	return (0);
}