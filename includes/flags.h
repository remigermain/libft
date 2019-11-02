/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:16:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 19:16:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FLAGS_H
# include "regex.h"
# define FLAGS_H
# define FSPACE 1
# define MAX_FLAGS 127
# define MAX_ARG 30
# define MAX_ERROR 30
# define NO_FLAG NULL
# define MAX_TYPE_AV 5
# define AV_ADD_NUM(nb, it_num, isset, mod) (*it_num = nb, *isset |= mod)
# define AV_ADD_PATTERN(str, pat, isset, mod) (pat = str, *isset |= mod)
# define AV_ERROR(mod) (count_error_argv(mod))

/*
**-----------------------------------------------------------
**
**-----------------------------------------------------------
*/
# define REGEX_ARGV_PARSE "^(\\s*(?<mflags>[\\w\\-]*)\\s*,\\s*\
(?<sflag>[\\w\\-]?)\\s*(\\(\\s*((?<type>[a-zA-Z*_]+)\\s*\
((\\{\\s*((?<opt_min>[\\d]*)\\s*,\\s*(?<opt_max>[\\d]*)\\s*\
(\\s*,\\s*\"(?<opt_pattern>[^\"]+)\"\\s*)?|\\s*(?<opt_eq>[\\d]*)\\s*)\\s*\\})?\
\\s*,\\s*)?)*\\s*\\))?\\s*(;\\s*((?<set>[\\w\\-]*)\\s*,\\s*)*\\s*;\\s*\
((?<unset>[\\w\\-]*)\\s*,\\s*)*\\s*;)?\\s*(?<separator>\\|))*$"

# define REGEX_ARGV_USAGE "^\\s*\"(?<usage_type>[^\"]+)\"\\s*(?<separator>\\|)\
(\\s*\"(?<text>[^\"]+)\\\"\\s*(?<separator>\\|))*$"

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
	F_EXIST = 0b001,
	F_ADD = 0b010,
	F_RM = 0b011,
	F_PRINT = 0b100,
	F_STOP,
	F_NOF,
	F_USAGE,
};

enum	e_option
{
	OP_MIN = 0b1,
	OP_MAX = 0b10,
	OP_EQ = 0b100,
	OP_PATTERN = 0b1000,
};

enum	e_type
{
	STRING,
	CHAR,
	INT,
	UINT,
	CHECK,
	MIN,
	EQ,
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
	char	*mfl;
	char	*sfl;
	char	*string[MAX_ARG];
	char	schar[MAX_ARG];
	int		number[MAX_ARG];
	int		exist_string;
	int		exist_char;
	int		exist_int;
	int		nb_arg;
}				t_flagav;

typedef struct	s_flags_info
{
	t_flagav	av[MAX_ARG];
	int			nb_flags;
}				t_flags_inf;
/*
**-----------------------------------------------------------
**      struct for type's option
**-----------------------------------------------------------
*/

typedef struct	s_finfo
{
	char	*mfl;
	char	*sfl;
	char	*type;
	char	*pattern;
	char	*av;
	int		error;
	int		min;
	int		eq;
	int		max;
	int		isset;
	int		nb_params;
}				t_finfo;

/*
**-----------------------------------------------------------
**      struct whith all need
**-----------------------------------------------------------
*/

typedef struct	s_flag
{
	t_regex			reg;
	t_finfo			it;
	char			**argv;
	char			*mflag;
	char			*flag;
	const char		*usage;
	int				argc;
	int				i;
	int				j;
	int				add;
	enum e_flags	mod;
}				t_flag;

/*
**-----------------------------------------------------------
**          flag_base_obj.c
**-----------------------------------------------------------
*/
t_flags_inf		*flags_av_struct(void);
t_bool			flag_add(char *mfl, char *sfl, void *value,
												enum e_type type);
int				flag_getindice(t_flags_inf *st, char *mfl, char *sfl);
void			print_flags(void);

/*
**-----------------------------------------------------------
**          flag_base_func.c
**-----------------------------------------------------------
*/
t_bool			exist_flags(char *fl);
t_bool			add_flags(char *mfl, char *sfl);
t_bool			add_flags_av(char *mfl, char *sfl, void *value,
													enum e_type type);
void			remove_flags(char *fl);
void			*get_flags_av(char *fl, int nb);

/*
**-----------------------------------------------------------
**			flag_utils.c
**-----------------------------------------------------------
*/
void			flag_free(void);

/*
**-----------------------------------------------------------
**          	flag_init.c
**-----------------------------------------------------------
*/
int				flag_init(char **argv, char *flag, char *usage,
											enum e_flags mod);

/*
**-----------------------------------------------------------
**				flag_parse.c
**-----------------------------------------------------------
*/
t_bool			parse_flags(t_flag *st, t_reg_list *lst, t_reg_list *head);

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
**          flag_error.c
**-----------------------------------------------------------
*/
void			ft_error_argv(char **argv, int error, int error_2);
int				count_error_argv(enum e_error_flag mod);
int				wrong_type(t_flag *st, char *type);
int				error_argv(t_flag *st, char *str, int i, int j);

/*
**-----------------------------------------------------------
**          flag_func_type.c
**-----------------------------------------------------------
*/
t_bool			check_int(t_flag *st, t_finfo *it, enum e_type mod);
t_bool			check_uint(t_flag *st, t_finfo *it, enum e_type mod);
t_bool			check_string(t_flag *st, t_finfo *i, enum e_type mod);
t_bool			check_char(t_flag *st, t_finfo *it, enum e_type mod);
t_bool			check_file(t_flag *st, t_finfo *it, enum e_type mod);

/*
**-----------------------------------------------------------
**			flag_func_obj.c
**-----------------------------------------------------------
*/
void			func_lenght(t_flag *st, t_finfo *it, char *str, int nb);
void			func_pattern(t_flag *st, t_finfo *it);

/*
**-----------------------------------------------------------
**			flag_usage.c
**-----------------------------------------------------------
*/
void			print_usage(t_flag *st);

#endif
