/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:16:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:18:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# define FSPACE 1
# define MAX_FLAGS 127
# define MAX_ARG 30
# define MAX_ERROR 30

enum	e_flags
{
	FLAG_ARGV = 0,
	F_EXIST = 0b001,
	F_ADD = 0b010,
	F_RM = 0b011,
	F_PRINT = 0b100,
	F_STOP,
};

enum	e_type
{
	STRING,
	CHAR,
	INT,
};

enum	e_error_flag
{
	ERROR_SET = 0b01,
	ERROR_GET = 0b10,
	ERROR_PRINT = 0b100,
};

typedef struct s_flagav
{
	char	*string[MAX_ARG];
	char	schar[MAX_ARG];
	int		number[MAX_ARG];
	char	fl;
	int		exist_string;
	int		exist_int;
	int		exist_char;
	int		nb_arg;
}				t_flagav;

typedef struct s_foption
{
	int		nb_arg;
	int		nb;
	char	fl;
}				t_foption;

typedef struct	s_finfo
{
	int			min;
	int			max;
	char		str[127];
	unsigned	isset : 3;
	t_bool		error;
}				t_finfo;

typedef struct	s_flag
{
	char			*mflag;
	char			*flag;
	char			**argv;
	int				argc;
	int				i;
	int				j;
	int				add;
	enum e_flags 	mod;
}				t_flag;


/*
**-----------------------------------------------------------
**          ft_flags.c
**-----------------------------------------------------------
*/
t_bool		flags_base(int fl, enum e_flags mod, void *value, enum e_type type);
//int		flags_base(char fl, enum e_flags mod);
int		print_flags(void);
t_bool		add_flags(int fl);
t_bool	add_flags_av(int fl, void *value, enum e_type type);
int		exist_flags(int fl);
void	remove_flags(int fl);
int		unknow_flags(char **argv, int i, int j);

/*
**-----------------------------------------------------------
**          ft_parse_argv.c
**-----------------------------------------------------------
*/
int		init_flags(char **argv, char *flag, char *mflag, enum e_flags mod);

/*
**-----------------------------------------------------------
**          ft_error_argv.c
**-----------------------------------------------------------
*/
void	ft_error_argv(char **argv, int error, int error_2);


/*
**-----------------------------------------------------------
**          ft_error_flags.c
**-----------------------------------------------------------
*/
int			cout_error_argv(enum e_error_flag mod);
int			wrong_type(t_flag *st, char *type);
int			wrong_flags(t_flag *st, char *msg, char *type);
int			missing_flags(t_flag *st);
int			missing_argv(t_flag *st);
int			many_argv(t_flag *st);
int			not_match(t_flag *st, char *str, char *match);
void		error_optionString(t_flag *st, t_finfo *it, char *str);
void		error_optionInt(t_flag *st, t_finfo *it, int nb);

/*
**-----------------------------------------------------------
**          ft_type_option.c
**-----------------------------------------------------------
*/
int			parse_typeoption(t_finfo *it, char *flag);
void		name_option_match(t_flag *st, t_finfo *it, char *str);
int			ft_spanoption(char *flag);


/*
**-----------------------------------------------------------
**          ft_type_flags.c
**-----------------------------------------------------------
*/
int			is_type(t_flag *st, t_foption *op, char *flag);
int			test_type_arg(t_flag *st, char *flag, t_foption *op, int(*funct)(t_flag*, char, char*, char*));
int			type_char(t_flag *st, char fl, char *flag, char *str);
int			type_string(t_flag *st, char fl, char *flag, char *str);
int			type_int(t_flag *st, char fl, char *flag, char *str);

/*
**-----------------------------------------------------------
**          ft_option_flag.c
**-----------------------------------------------------------
*/
int 		parse_option(t_flag *st, char fl, char *flag);
int			span_alloption(char *flag);

/*
**-----------------------------------------------------------
**          ft_usage_flag.c
**-----------------------------------------------------------
*/
void       print_usage(t_flag *st);
char		*text_usage(char *str);
#endif
