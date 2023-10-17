#ifndef MLX_TEST_H
# define MLX_TEST_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# define SIZE 8
# define ROT_ANG 5
# define RAD_1 0.0174532925199
# define RAD_90 1.57079632679
# define RAD_270 4.71238898037
# define RAD_360 6.28318530716
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define PINK 0xFF00FFFF

enum e_attributes
{
	NO = 0,
	SO,
	WE,
	EA
};

enum e_colors
{
	R = 0,
	G,
	B,
	A
};

enum e_positions
{
	X = 0,
	Y
};

# define WIDTH 800
# define HEIGHT 600
# define WIDTH_2 400
# define HEIGHT_2 300

# define DIR_SIZE 8

typedef struct s_mlx
{
	char			**attributes;
	mlx_texture_t	*tex[4];
	mlx_image_t		*img;
	mlx_t			*win;
	bool			m_cntl;
}	t_mlx;

extern const char	*g_map[];

// render.c =========================================================
void	draw_background(t_mlx *mlx);
void	draw_direction(t_mlx *mlx, double x0, double y0);
void	draw_player(t_mlx *mlx);
void	draw_map(t_mlx *mlx, int map_x, int map_y);
void	draw_aim(t_mlx *mlx);
void	render(void *var);

// cast_rays.c ======================================================
double	cost_y_ray_distance(double *x, double *y, double tangent, \
							double ray_angle);
double	cost_x_ray_distance(double *x, double *y, double tangent, \
							double ray_angle);
void	update_distance(double *x, double *y, double *ray, double *off);
void	draw_wall(t_mlx *mlx, double height, int init, int ray_x, mlx_texture_t *tex);
void	cast_rays(t_mlx *mlx, int fov);

// utils.c ===========================================================
double	rad_overflow(double radians);
double	fisheye_fix(double ray_angle);
double	pythagoras(double x0, double y0, double x1, double y1);
void	change_pos(double x, double y);

// mouse.c ===========================================================
void	toggle_mouse(t_mlx *mlx);
void	mouse(double x_pos, double y_pos, void *var);

// keyboard.c ========================================================
void	movement_keys(t_mlx *mlx);
void	keyboard(mlx_key_data_t data, void *var);


// fake_globals.c ====================================================
double	*getter_player_x(void);
double	*getter_player_y(void);
int		*getter_player_ang(void);
double	*getter_dir_x(void);
double	*getter_dir_y(void);

#endif
