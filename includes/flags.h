/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:16:41 by rgermain          #+#    #+#             */
/*   Updated: 2019/10/03 19:21:41 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FLAGS_H
# define FLAGS_H
# define FSPACE 1
# define MAX_FLAGS 127
# define MAX_ARG 30
# define MAX_ERROR 30

/*
**-----------------------------------------------------------
**      Macro for convert return argument
**-----------------------------------------------------------
*/
# define F_INT(ptr) ((int)*((int*)ptr))
# define F_CHAR(ptr) ((int)*((int*)ptr))
# define F_CHARS(ptr) ((char*)ptr)

enum	e_flags
{
	FLAG_ARGV = 0,
	F_EXIST = 0b001,
	F_ADD = 0b010,
	F_RM = 0b011,
	F_PRINT = 0b100,
	F_STOP,
	F_USAGE,
};

enum	e_option
{
	OP_MIN = 0b1,
	OP_MAX = 0b10,
	OP_PATTERN = 0b100,
};

enum	e_type
{
	STRING,
	CHAR,
	INT,
	UINT,
	CHECK,
	MIN,
	MAX,
	ADD,
	MATCH,
	PATTERN,
};

enum	e_error_flag
{
	ERROR_SET = 0b01,
	ERROR_GET = 0b10,
	ERROR_PRINT = 0b100,
};

/*
**-----------------------------------------------------------
**      struct base for flag
**-----------------------------------------------------------
*/

typedef struct	s_flagav
{
	char	*string[MAX_ARG];
	char	schar[MAX_ARG];
	int		number[MAX_ARG];
	int		exist_string;
	int		exist_char;
	int		exist_int;
	int		nb_arg;
	char	fl;
}				t_flagav;

/*
**-----------------------------------------------------------
**      struct for type's option
**-----------------------------------------------------------
*/

typedef struct	s_finfo
{
	int		min;
	int		max;
	char	str[127];
	int		isset;
	t_bool	error;
	char	fl;
	char	*flag;
	char	*av;
}				t_finfo;

/*
**-----------------------------------------------------------
**      struct whith all need
**-----------------------------------------------------------
*/

typedef struct	s_flag
{
	t_finfo			it;
	char			*mflag;
	char			*flag;
	char			**argv;
	int				argc;
	int				i;
	int				j;
	int				add;
	enum e_flags	mod;
}				t_flag;

/*
**-----------------------------------------------------------
**          ft_flags_base.c
**-----------------------------------------------------------
*/
t_flagav		*flags_av_struct(void);
int				flag_getindice(t_flagav *av, int fl);
t_bool			flag_add(t_flagav *av, int fl, void *value, enum e_type type);
void			print_flags(void);

/*
**-----------------------------------------------------------
**          ft_flags_base_func.c
**-----------------------------------------------------------
*/
void			*get_flags_av(int fl, int nb);
void			remove_flags(int fl);
t_bool			exist_flags(int fl);
t_bool			add_flags(int fl);
t_bool			add_flags_av(int fl, void *value, enum e_type type);

/*
**-----------------------------------------------------------
**          ft_parse_argv.c
**-----------------------------------------------------------
*/
int				init_flags(char **argv, char *flag, char *m, enum e_flags mod);

/*
**-----------------------------------------------------------
**          ft_error_argv.c
**-----------------------------------------------------------
*/
void			ft_error_argv(char **argv, int error, int error_2);

/*
**-----------------------------------------------------------
**          ft_error_line.c
**-----------------------------------------------------------
*/
void			error_line(const char *str);
void			error_line_pos(const char *error, int line, int pos);
void			error_line_e(const char *str, int pos);


/*
**-----------------------------------------------------------
**          ft_error_flags.c
**-----------------------------------------------------------
*/
int				cout_error_argv(enum e_error_flag mod);
int				not_match(t_flag *st, char *str, char *match);
int				wrong_type(t_flag *st, char *type);
int				error_argv(t_flag *st, char *str, int i, int j);

/*
**-----------------------------------------------------------
**          ft_func_type.c
**-----------------------------------------------------------
*/
t_bool			check_int(t_flag *st, t_finfo *it, char *str, enum e_type mod);
t_bool			check_uint(t_flag *st, t_finfo *it, char *str, enum e_type mod);
t_bool			check_string(t_flag *st, t_finfo *i, char *s, enum e_type mod);
t_bool			check_char(t_flag *st, t_finfo *it, char *str, enum e_type mod);

/*
**-----------------------------------------------------------
**          ft_func_type_obj.c
**-----------------------------------------------------------
*/
void			func_obj_match(t_flag *st, t_finfo *it, char *str);
void			func_obj_minmax(t_flag *s, t_finfo *i, char *ty, enum e_type m);

/*
**-----------------------------------------------------------
**          ft_parse_type.c
**-----------------------------------------------------------
*/
int				parse_typeoption(t_finfo *it, char *flag);
void			option_match(t_flag *st, t_finfo *it, char *str);
int				span_option(char *flag);

/*
**-----------------------------------------------------------
**          ft_call_types.c
**-----------------------------------------------------------
*/
int				type_all(t_flag *st, t_finfo *it, t_bool(*type_av)
							(t_flag *st, t_finfo*, char*, enum e_type));
int				find_type(t_flag *st, char *flag, char fl, int i);
int				is_type(t_flag *st, char *flag, int nb, char fl);

/*
**-----------------------------------------------------------
**          ft_option_flag.c
**-----------------------------------------------------------
*/
int				parse_option(t_flag *st, char fl, char *flag);
int				span_alloption(char *flag);

/*
**-----------------------------------------------------------
**          ft_usage_flag.c
**-----------------------------------------------------------
*/
char			*init_usage(char *str);
void			print_usage(t_flag *st);

#endif
