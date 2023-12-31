/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:54:22 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/23 12:16:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

double	rad_overflow(double radians)
{
	if (radians < 0)
		return (radians + RAD_360);
	if (radians > RAD_360)
		return (radians - RAD_360);
	return (radians);
}

void	change_pos(double x, double y)
{
	if (*getter_player_x() / SIZE + x >= -0.9 \
	&& (*getter_map())[(int)(*getter_player_y() / SIZE)] \
			[(int)((*getter_player_x() + x) / SIZE)] != 0)
		*getter_player_x() += x;
	if (*getter_player_y() / SIZE + y >= -0.9 \
	&& (*getter_map())[(int)((*getter_player_y() + y) / SIZE)] != NULL)
		*getter_player_y() += y;
}

double	fisheye_fix(double ray_angle)
{
	double	fisheye;

	fisheye = RAD_1 * *getter_player_ang() - ray_angle;
	fisheye = rad_overflow(fisheye);
	return (cos(fisheye));
}

double	pythagoras(double x0, double y0, double x1, double y1)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}
