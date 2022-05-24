/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:05:59 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 17:07:53 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf_bonus.h"
# include <sys/types.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>

# define NORTHEAST 0
# define NORTHWEST 1
# define SOUTHWEST 2
# define SOUTHEAST 3

# define TOP 0
# define RIGHT 1
# define BOTTOM 2
# define LEFT 3

# define A 97
# define B 98
# define C 99
# define D 100
# define E 101
# define F 102
# define G 103
# define H 104
# define I 105
# define J 106
# define K 107
# define L 108
# define M 109
# define N 110
# define O 111
# define P 112
# define Q 113
# define R 114
# define S 115
# define T 116
# define U 117
# define V 118
# define W 119
# define X 120
# define Y 121
# define Z 122

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 65307
# define ENTER 65293

# define GAME 0
# define MENU 1
# define EDITOR_MENU 2
# define EDITOR 3
# define EDITOR_MAPS 4
# define MENU_MAPS 5

# define ZERO 48
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 53
# define SIX 54
# define SEVEN 55
# define EIGHT 56
# define NINE 57

# define MINUS 45
# define PLUS 61

# define RETURN 65288

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	char	ch[2];
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

typedef struct s_neighbor
{
	int	top;
	int	right;
	int	bottom;
	int	left;
}	t_neighbor;

typedef struct s_guard
{
	t_neighbor		neighbor;
	int				choice;
	int				direction;
	t_vector2D		pos;
}	t_guard;

typedef struct s_guards_list
{
	t_guard					guard;
	int						index;
	struct s_guards_list	*next;
}	t_lst_guard;

typedef struct s_miniclock
{
	int		sec;
	double	ms;
	double	full;
}	t_miniclock;

typedef struct s_clock
{
	struct timeval	time;
	double			fl_time;
	struct timeval	start;
	double			fl_start;
	t_miniclock		clock;

}	t_clock;

typedef struct s_menu
{
	t_data			*buttons;
	int				selected;
	void			*mlx;
	void			*win;
	int				size_map;
	char			**map;
}	t_menu;

typedef struct s_editor
{
	t_vector2D		pos;
	void			*mlx;
	void			*win;
	int				size;
	char			name[29];
	int				index;
}	t_editor;

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
	t_lst_guard		*li_guards;
	t_data			*sprites;
	t_data			*jump;
	t_data			**slime;
	t_clock			cl_slime;
	t_clock			cl_jump;
	t_clock			cl_guards;
	t_clock			cl_frozen;
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
	t_vector2D		p_pos;
	int				is_guards;
	t_menu			menu;
	int				mode;
	int				new_win;
	t_editor		editor;
	t_vector2D		ed_pos;
	t_data			*special;
	t_data			*special_h;
	t_data			*wall_special;
	t_data			*wall_special_h;
	t_data			*mini;
	int				new_menu;
	int				new_game;
	int				lock;
	void			*mini_win;
	int				new_mini_win;
	char			**user_maps;
	int				nb_maps;
	int				map_select;
	int				new_editor_win;
	int				select_m;
	t_alloc			*alloc;
	t_alloc			*img_alloc;
	char			*new_map_str;
	char			**real_new_map;
	int				stopping;
	int				frozen;
	int				new_frozen;
	int				frozed;
	int				pos_changed;
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
int			check_size(t_vector2D it, t_vector2D size, char **map, int *err);

// GUARDS
void		guards_add(t_lst_guard **alst, t_lst_guard *new);
void		guards_clear(t_lst_guard **lst);
t_lst_guard	*guards_new(t_guard content, int index, t_alloc *alloc);
int			guards_size(t_lst_guard *lst);
t_lst_guard	*guards_find(t_lst_guard	*li, t_vector2D	pos);

void		move_guards(t_vars *vars);

// UTILS
void		print_map(char	**map);
t_vector2D	search_char(char **map, char c);
char		*ft_str_add(char *str, int n, char c, t_alloc *alloc);
int			random_seed(int max, int fd);
int			random_nb(t_vars *vars);
void		handle_clock(t_vars *vars);
char		**double_str_dup(char **map, t_vector2D size, t_alloc **alloc);
void		complete_menu_maps(t_vars *vars, t_vector2D size);

// GENERATE

	// TEXTURE
t_data		*generate_sprites(t_vars *vars);
t_data		*generate_player(t_vars *vars);
t_data		*generate_guard(t_vars *vars);
t_data		*generate_jump(t_vars *vars);
t_data		**generate_slime(t_vars *vars);
t_data		*generate_special(t_vars *vars);
t_data		*generate_special_h(t_vars *vars);
t_data		*generate_wall(t_vars *vars);
t_data		*generate_wall_h(t_vars *vars);
char		*n3c(char *s1, char *s2, int n, t_alloc **alloc);

	// MAP
char		**resize_map(char **map, t_vector2D *size, t_alloc *alloc);
void		free_map(char **map);
char		**free_before_map(int i, char **map);

	// INIT_GLOBAL
int			initialise_global(t_vars	*vars, char **argv);
int			initialise_global_5(t_vars *vars);

t_lst_guard	*generate_guard_list(char **map, t_alloc *alloc);
t_data		generate_image(t_vars vars, char *path, t_alloc **alloc);

	// FREE
void		free_game(t_vars *vars);

// IMAGE
int			create_trgb(int t, int r, int g, int b);
void		construct_image(char *buffer,
				t_vector2D start, t_data image2, t_data image);
// PARSING 2
char		**several_start_selecting(char **map, int p);

// DISPLAYING

	// MAP
void		create_map(t_vars *vars);
void		create_map_win(t_vars vars);
void		create_map_block(t_vars vars,
				t_vector2D start, char *buffer, t_data *map);
void		special_block_map(t_construct c, t_vars vars, t_data *map);

	// SCORE
void		display_score(t_vars *vars);

// HANDLING

	// UPDATE
int			updating(t_vars *vars);

	// KEY
int			key_handling(int keycode, t_vars *vars);
int			close_win(t_vars *vars);
void		game_key(int keycode, t_vars *vars);

	// CLOCK
t_clock		clock_start(void);
void		get_clock(t_clock *clock);
void		reset_clock(t_clock	*clock);

// GUARDS

	// CHECK
int			is_obstacle(char **map, t_vector2D pos, int dir, t_vector2D size);
void		player_dead(t_vars *vars, t_vector2D pos);

void		create_map_editor(t_vars *vars);

t_data		*generate_mini(t_vars *vars);

void		mini_editor_menu(t_vars *vars);

// MENU
	// UPDATING
int			menu(t_vars *vars);
void		menu_updating(t_vars *vars);
	// KEY
int			menu_key(int keycode, t_vars *vars);

// EDITOR
	//UPDATING
void		editor_updating(t_vars *vars);
	// KEY
int			editor_key(int k, t_vars *vars);
char		*concat_ber(t_vars *vars);
void		editor_block_key(int k, t_vars *vars);
	// MAP
void		create_map_block_editor(t_vars vars,
				t_vector2D start, char *buffer, t_data *map);

// EDITOR MENU 
	//UPDATING
void		editor_menu_updating(t_vars *vars);
	//KEY
void		editor_menu_key(int k, t_vars *vars);
	// PARSING
char		**create_editor_map_base(int size_map, t_alloc *alloc);

// EDITOR MAPS
	// KEY
int			editor_maps_key(int k, t_vars *vars);
	// UPDATING
void		editor_maps_updating(t_vars *vars);

// GLOBAL_HANDLING
	// LAUNCH_WINS
void		launch_new_menu_win(t_vars *vars);
void		launch_new_game_win(t_vars *vars);
void		launch_new_mini_win(t_vars *vars);
void		launch_new_editor_win(t_vars *vars);
	// GLOBAL_UPDATE
void		game_updating(t_vars *vars);

void		menu_maps_updating(t_vars *vars);

char		*del_ber(char *str, t_alloc *alloc);

char		**exec_ls(t_alloc **alloc);
char		**parse_maps_name(char **maps, t_alloc *alloc);
int			count_maps(char **maps);
int			menu_maps_key(int k, t_vars *vars);

int			is_valid_char_map_open(char **map);
int			is_valid_size_map_open(char **map, t_vector2D *size);

int			is_valid_wall_map(char **map, t_vector2D size,
				t_vars *vars, int *err);
void		check_char(char block, int *p, int *c, int *e);
int			is_valid_char_map(char **map, int *c, int *fd);
int			is_valid_size_map(char **map, t_vector2D *size, int *err);

void		reinitialise_game_data(t_vars *vars);

void		check_end(t_vars *vars);

#endif