#include "libft.h"

# define RED "\033[31m"
# define RESET "\033[0m"
# define WHITE "\033[37m"

# define ERR_LINE 1
# define BLUE  "\033[34m"

static void	ft_error_argv2(char **argv, int error, int error_2)
{
	int i;

	i = 0;
	ft_dprintf(2, "\n%6@", "char", ' ');
	while (argv[++i] && i < error)
		ft_dprintf(2, "%*@ ", ft_strlen(argv[i]), "char", ' ');
	if (i == error)
	{
		if (error_2)
			ft_dprintf(2, "%*@ ", error_2 - 1, "char", ' ');
		ft_dprintf(2, RED);
		ft_dprintf(2, "^%*@\n", (!error_2 ? ft_strlen(argv[i]) - 1 : 0), "char", '~');
		ft_dprintf(2, RESET);
	}
}

void		ft_error_argv(char **argv, int error, int error_2)
{
	int	i;
	int	j;
	
	i = 0;
	j = -1;
	ft_dprintf(2, "%6@", "char", ' ');
	while (argv[++i])
	{
		if (i == error && !error_2)
			ft_dprintf(2, "%s", (i == error) ? RED : "");
		if (i != error || error_2 == 0)
			ft_dprintf(2, "%s%s", argv[i], (argv[i + 1] ? " " : ""));
		else
			while (argv[i][++j])
			{
				ft_dprintf(2, "%s", (j == error_2) ? RED : "");
				ft_dprintf(2, "%c", argv[i][j]);
				ft_dprintf(2, "%s", (j == error_2) ? RESET : "");
			}
		if (i == error && !error_2)
			ft_dprintf(2, "%s", (i == error) ? RESET : "");
	}
	ft_error_argv2(argv, error, error_2);
}

int	ft_error_line(char *str, int error, char *msg, char flag)
{
	int	i;

	i = 0;
	ft_dprintf(2, WHITE"%d:%d: ", ft_strlen(str), error);
	if (flag & ERR_LINE)
		ft_dprintf(2, RED"error: "WHITE"%s\n", msg);
	else
		ft_dprintf(2, BLUE"warning: "WHITE"%s\n", msg);
	ft_dprintf(2, RESET"%6@%s\n", "char", ' ', str);
	ft_dprintf(2, "%*@"RED"↑"RESET"\n", error, "char", ' ');
	return (1);
}

enum	e_flags
{
	F_EXIST = 0b001,
	F_ADD = 0b010,
	F_RM = 0b011,
	F_PRINT = 0b100
};

int	flags_base(char fl, int mod)
{
	static t_ulong	flags = 0;

	if (fl <= 90)
		fl -= 65;
	else
		fl = (fl - 97) + 26;
	if (mod == F_EXIST)
		return ((flags >> fl) & 0x1);
	else if (mod == F_ADD)
		flags |= (unsigned long long)(1UL << fl);
	else if (mod == F_RM)
		flags ^= (1UL << fl);
	else if (mod == F_PRINT)
		ft_printf("%.31b%.31b\n", flags >> 31, flags & INT_MAX);
	return (0);
}

int	exist_flags(char fl)
{
	return(flags_base(ft_toupper(fl) - 'A', F_EXIST));
}


void	remove_flags(char fl)
{
	flags_base(ft_toupper(fl) - 'A', F_RM);
}

void	unknow_flags(char **argv, int i, int j)
{
	ft_dprintf(2, RED"error: "WHITE"unknow flags.\n"RESET);
	ft_error_argv(argv, i, j);
}

# define MFLAG "er;e|diff;d|size;e|coucou;r|rr;t|op41;t|"

void	parse_mflag(char **argv, int i, char *mflag)
{
	int	min;
	int	max;
	int	len;

	min = 0;
	len = ft_strlen(mflag);
	while (min < len)
	{
		max = len - ft_strlen(ft_strchr(mflag + min, '|')) - min;
		if (!ft_strncmp(argv[i] + 2, mflag + min, max - 3) &&
			ft_strlen(argv[i] + 2) == (max - 2))
		{
			flags_base(mflag[max - 1], F_ADD);
			return ;
		}
		min += max + 1;	
	}
	unknow_flags(argv, i, 0);
}

void	init_flags(char **argv, char *flag, char *mflag)
{
	int	i;
	int	j;
	
	i = 0;
	while (argv[++i])
	{
		j = 1;
		while (argv[i][j] && argv[i][0] == '-')
		{
			if (argv[i][1] != '-')
			{
				if (ft_strchr(flag, argv[i][j]))
					flags_base(argv[i][j], F_ADD);
				else
					unknow_flags(argv, i, j);
			}
			else if (argv[i][1] == '-')
			{
				parse_mflag(argv, i, mflag);
				break ;
			}
			j++;
		}

	}
}

# include <stdio.h>

int main(int argc, char **argv)
{
	ft_printf("%d\n", ft_strlen(argv[1]));
	init_flags(argv, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", MFLAG);

	flags_base(' ', F_PRINT);
//	ft_error_line(argv[1], ft_atoi(argv[2]), argv[3]);
//	ft_error_argv(argv, argc - 2);
	return (0);
}
