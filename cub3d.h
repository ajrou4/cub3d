/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:24:47 by majrou            #+#    #+#             */
/*   Updated: 2023/11/01 07:01:18 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SQ_ 30
# define PLAYER_SPEED 3
# define WIDTH 1200
# define HEIGHT 1200
# define FALSE 0
# define TRUE 1

typedef struct s_new_map
{
	int				i;
	int				j;
	char			*str;
	char			**new_map;
}					t_new_map;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
}					t_data;

typedef struct s_rgb
{
	int				sky[3];
	int				floor[3];
}					t_rgb;

typedef struct s_map
{
	int				width;
	int				height;
	char			**map;
}					t_map;

typedef struct s_dda
{
	int				dx;
	int				dy;
	int				steps;
	float			xinc;
	float			yinc;
	float			x;
	float			y;
	float			inc;
	float			y_text;
	float			x_text;
	int				i;
}					t_dda;

typedef struct s_3d
{
	float			distance;
	float			perpdistance;
	float			projectedwallheight;
	int				wallstripheight;
	int				walltoppixel;
	int				wallbottompixel;
	int				j;
}					t_3d;

typedef struct s_hr
{
	float			xtocheck;
	float			ytocheck;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
}					t_hr;

typedef struct s_vect
{
	int				x;
	int				y;
}					t_vect;

typedef struct s_vr
{
	float			xtocheck;
	float			ytocheck;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
}					t_vr;

typedef struct s_texteur
{
	mlx_texture_t	*no;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	mlx_texture_t	*so;
}					t_texteur;

typedef struct s_map_data
{
	t_new_map		jk;
	t_texteur		*texteur;
	t_rgb			*color;
	t_dda			dda;
	t_3d			p;
	t_hr			hr;
	t_vr			vr;
	mlx_texture_t	*tex;
	int				*dummy_texture;
	void			*img;
	int				line_length;
	void			*mlx;
	void			*win;
	int				row_count;
	int				col_count;
	int				c_col_count;
	char			cur_char;
	char			**map;
	float			p_x;
	float			p_y;
	float			p_xtmp;
	float			p_ytmp;
	float			p_xtmp_check;
	float			p_ytmp_check;
	float			new_x;
	float			new_y;
	double			r_angle;
	double			ray_angle;
	double			fov;
	int				israyfacingdown;
	int				israyfacingup;
	int				israyfacingright;
	int				israyfacingleft;
	float			nextverttouchx;
	float			nexthorztouchx;
	float			nextverttouchy;
	float			nexthorztouchy;
	float			hwallhitx;
	float			vertwallhitx;
	float			horzwallhity;
	float			vwallhity;
	int				foundvertwallhit;
	int				foundhorzwallhit;
	float			hordis;
	float			verdis;
	int				walltoppixel;
	int				wallbottompixel;
	int				x_text;
	int				y_text;
	int				wallstripheight;
	float			heightwall;
	int				xx;
	int				yy;
	int				x1;
	int				y1;
	int				fr;
	int				fg;
	int				fb;
	int				cr;
	int				cg;
	int				cb;
}					t_map_data;

char				**read_map(char *file);
void				get_color(t_map_data *data);
t_texteur			*get_tex(t_map_data *data);
int					count_lines(int fd);
int					check_elements(t_map_data *data);
void				check_map(t_map_data *data);
void				check_duplcit(t_map_data *data);
void				free_map(char **map);
void				parse_ceiling_line(t_map_data *data, char *line);
void				parse_floor_line(t_map_data *data, char *line);
void				remove_newlines(t_map_data *data);
void				error_map(char **map);
void				error_cheack_map(char **map, int i);
void				dda(t_map_data *map, t_vect v1, t_vect v2);
int					get_offsetx(t_map_data *data, mlx_texture_t *img);
int					get_color_from_textur(mlx_texture_t *texteur, int x, int y);
void				render_map(t_map_data *map);
void				player_x_y(t_map_data *mape);
int					strlen_nn(char *s);
void				get_map_data(t_map_data *mape, char *path);
void				rotate_player(t_map_data *mape, double angle);
double				normalize(double angle);
void				cast_all_rays(t_map_data *mape);
int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void				cast_vertical_ray(t_map_data *mape);
bool				maphaswallat(t_map_data *mape, float x, float y);
void				cast_horizontal_ray(t_map_data *mape);
double				rad(float degree);
void				generate3dprojection(t_map_data *mape, int i);
float				short_distance(t_map_data *mape);
void				loop(void *p);
void				processrotationandesc(t_map_data *a);
void				moveIndirection(t_map_data *a, double angle);
void				processdirectionkeys(t_map_data *a);
int					ismoveallowed(t_map_data *a);
float				calc_hor_dis(t_map_data *mape);
float				calc_vert_dis(t_map_data *mape);
void				my_putpix1(t_map_data *map);
void				my_putpix2(t_map_data *map);
void				my_putpix3(t_map_data *map);
void				my_putpix4(t_map_data *map);
void				dda_increment(t_map_data *map);
void				dda_core_2(t_map_data *map);
void				dda_core_1(t_map_data *map);
void				init_dda(t_map_data *map, t_vect v1, t_vect v2);
int					check_valide_map(t_map_data *data);
int					map_size(char **data);
void				new_map(t_map_data *data, char ***map);
int					is_near_zero_valid(char **map, int i, int c);
int					is_acceptable_char(char c);
void				destroy_program(t_map_data *data);
void				initialize_player_data(t_map_data *mape, int y, int x);
int					check_if_map_enclosed(t_map_data *data);
#endif
