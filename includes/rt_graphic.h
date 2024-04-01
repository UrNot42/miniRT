/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_graphic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:18:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 19:38:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GRAPHIC_H
# define RT_GRAPHIC_H

# define WINDOW_NAME  "MiniRT"

# define HEX_RED_OFFS 16
# define HEX_GREEN_OFFS 8
# define HEX_BLUE_OFFS 0
# define HEX_ALPHA_OFFS 24

# define COL_SCALE 255

typedef struct s_canvas	t_canvas;
typedef struct s_wraper	t_wraper;
typedef struct s_image	t_image;
typedef unsigned int	t_unt;
typedef t_unt			t_dim	__attribute__((ext_vector_type(2)));

struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_unt	height;
	t_unt	width;
};

struct	s_canvas
{
	void		*ptr;
	void		*win;
	char		*name;
	t_image		*picture;
	t_scene		*scene;
	t_unt		height;
	t_unt		width;
	bool		defined;
};

struct	s_wraper
{
	t_canvas	*screen;
	t_scene		scene;
};

// Functions
t_canvas	canvas(t_unt width, t_unt height);
void		print_canvas(t_canvas screen);

// Creation
bool		init_canvas(t_canvas *screen);
bool		open_canvas(t_canvas *screen);
void		close_canvas(t_canvas screen);
bool		open_window(t_canvas *screen);
bool		close_window(t_canvas screen);
bool		create_image(t_image **picture, t_dim size, void *data_ptr);
void		set_image(t_canvas screen);
int			free_loop(t_wraper *data);
void		start_loop(t_wraper *data);

// Reading
t_color		pixel_at(t_canvas screen, t_unt x, t_unt y);
void		pixel_put(t_image *pic, int x, int y, t_hxcol color);
void		write_pixel(t_image *pic, int x, int y, t_color color);
bool		safe_pixel(t_image *pic, int x, int y, t_color color);

// World
t_scene		default_world(void);
bool		add_light(t_scene	*world, t_obj light);
bool		add_obj(t_scene	*world, t_obj obj);
t_mater		material(void);

// Camera
t_ray		ray_for_pixel(t_cam view, t_unt	x, t_unt y);
t_canvas	*render(t_cam camera, t_scene world);

int	key_handler(int key, t_wraper *data);
int	render_scene(t_wraper *data);

#endif
