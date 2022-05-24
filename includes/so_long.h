/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:05:59 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 17:41:33 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf_bonus.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define NORTHEAST 0
# define NORTHWEST 1
# define SOUTHWEST 2
# define SOUTHEAST 3

# define TOP 0
# define RIGHT 1
# define BOTTOM 2
# define LEFT 3

# define Z 122
# define W 119
# define ARROW_UP 65362
# define S 115
# define ARROW_DOWN 65364
# define Q 113
# define A 97
# define ARROW_LEFT 65361
# define D 100
# define ARROW_RIGHT 65363
# define ESC 65307

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;

typedef struct s_vector2D
{
	int	x;
	int	y;
}	t_vector2D;

typedef struct s_char
{
	t_data		*sprite;
	int			direction;
}	t_char;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	char			**save;
	t_vector2D		size;
	t_vector2D		screen;
	int				finish;
	t_char			player;
	t_data			*sprites;
	t_data			*jump;
	int				update;
	int				moves;
	int				items;
	int				total_items;
	int				ending;
	int				update_ending;
	t_vector2D		last_pos;
	int				stopped;
	int				slime_sp;
	int				jump_sp;
	int				random;
	unsigned short	seed;
	unsigned int	bit;
	t_alloc			*alloc;
	t_alloc			*img_alloc;
	t_vector2D		p_pos;
}	t_vars;

typedef struct s_image_construct
{
	char		c;
	char		*buffer;
	t_vector2D	start;
	t_vector2D	pos;
}	t_construct;

// DRAW SPRITE
char		*read_file(int fd, t_alloc **alloc);

// PARSING
char		**read_map(int *fd, t_vector2D *size, int *items, t_vars *vars);
int			check_size(t_vector2D size, t_vector2D it, char **map, int *err);

// UTILS
void		print_map(char	**map);
t_vector2D	search_char(char **map, char c);
char		*ft_str_add(char *str, int n, char c, t_alloc **alloc);
int			random_seed(int max, int fd);
int			random_nb(t_vars *vars);

// GENERATE

	// TEXTURE
t_data		*generate_sprites(t_vars *vars);
t_data		*generate_player(t_vars *vars);
t_data		*generate_guard(t_vars *vars);
t_data		*generate_jump(t_vars *vars);

	// MAP
char		**resize_map(char **map, t_vector2D *size, t_alloc **alloc);
void		free_map(char **map);
char		**free_before_map(int i, char **map);

	// OTHER
int			initialise_global(t_vars	*vars, char **argv);
t_data		generate_image(t_vars vars, char *path, t_alloc **alloc);

	// FREE
void		free_game(t_vars *vars);

// IMAGE
int			create_trgb(int t, int r, int g, int b);
void		construct_image(char *buffer,
				t_vector2D start, t_data image2, t_data image);
// PARSING 2
char		**several_start_selecting(char **map, int p, t_vars *vars);

// DISPLAYING

	// MAP
void		create_map(t_vars *vars);
void		create_map_win(t_vars vars);
void		create_map_block(t_vars vars,
				t_vector2D start, char *buffer, t_data *map);

	// SCORE
void		display_score(t_vars *vars);

// HANDLING

	// UPDATE
int			updating(t_vars *vars);

	// KEY
int			key_handling(int keycode, t_vars *vars);
int			close_win(t_vars *vars);

#endif