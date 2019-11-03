/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   regex_exec.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 18:11:21 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 19:08:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
**-------------------------------------------------------
**		le alpha[REGEX_ALPHA] represente un chaine de 1 et de 0
**		le 1 represente le character set
**		ex :	bonjour
**		u = 117 en valeur ascii
**		alpha[117] vaudra 1 tendis que alpha[110] vaudre 0
**
**		il fonctionnera aussi avec les metachar \d \w \D \W ...
**		ex :	bonjour\d
**		\d = tout les digits donc de 0 a 9
**		apha[48] a alpha[57] vaudra 1
**		car 0 = 48 et 9 = 57 , on va set tout les char de 0 a 9
**
**		le character doit etre egale a s1 ou que le character
**		de reg soit un delimiteur . car le . match
**		avec n'importe quoi
**-------------------------------------------------------
*/

static t_bool	regex_parse_2(t_regex *st, const char *s1, const char *reg)
{
	char	alpha[REGEX_ALPHA];
	int		len;

	if (is_delimiter(st, reg, "$") && *(reg + 1) == '\0')
	{
		if (*s1 == '\0' && (++st->match))
			return (TRUE);
		return (FALSE);
	}
	if (*s1)
	{
		ft_bzero(alpha, sizeof(char) * 128);
		len = regex_is_metatype(st, alpha, reg);
		if ((is_delimiter(st, reg, ".") || alpha[(int)(*s1)] == 1))
			return (regex_parse(st, ++s1, reg + len));
	}
	return (FALSE);
}

static t_bool	regex_ascii_char(t_regex *st, const char *s1, const char *reg)
{
	int span;

	span = ft_spantype(reg + 1, ft_isxdigit) + 1;
	if (*(reg + span) == ';' && is_delimiter(st, reg + span + 1, QUANTIFIER))
		return (regex_quantifier(st, s1, reg));
	return (regex_parse_2(st, s1, reg));
}

/*
**-------------------------------------------------------
**		function principal qui apelle toutes les functions
**		en rapport avec le delimiter
**-------------------------------------------------------
*/

t_bool			regex_parse(t_regex *st, const char *s1, const char *reg)
{
	if (s1 > st->last_error)
		st->last_error = s1;
	st->last_s1 = s1;
	if (is_delimiter(st, reg, "\\"))
		reg++;
	if (*reg == '\0' && (++st->match))
		return (TRUE);
	if (is_delimiter(st, reg, "|"))
		return (TRUE);
	if (is_delimiter(st, reg, ")"))
		return (TRUE);
	if (is_delimiter(st, reg, "["))
		return (regex_class(st, s1, ++reg));
	if (is_delimiter(st, reg, "("))
		return (regex_enclosed(st, s1, ++reg));
	if (!is_delimiter(st, reg, REG_ASCII_TYPE))
		return (regex_ascii_char(st, s1, reg));
	if (is_delimiter(st, reg + 1, QUANTIFIER))
		return (regex_quantifier(st, s1, reg));
	return (regex_parse_2(st, s1, reg));
}

/*
**-------------------------------------------------------
**
**		ft_regex by rgermain
**
**	-------------
**		QUANTIFIER
**	-------------
**
**		{n,m} ? * +
**
**		{5,9}	match upper than 5, and lower than 9
**		{0,}	match upper than 0 same as *
**		{1,}	match upper than 1 same as +
**		{,1}	match lower than 1 same as ?
**
**		?		lazy quantifier
**		{5,9}?	match upper than 5, and lower than 9
**
**	-------------
**		CLASS
**	-------------
**
**	[^a-zA-Z\d[:isdigit].\\]fg]
**		*^				for not matching
**		*a-z			whole char in a to z
**		*\d				whole char is digit same as 0-9
**		[:isdigit:]		whole char is digit same as 0-9
**		*.				for point char
**		*fg				match with f or g
**
**	-------------
**		META
**	-------------
**
**	\d \D \s \S \w \W \n \e \t \xE7; \o152;
**	{}()[]?*+^$.					metachar need to be esapced
**
**	-------------
**		ENCLOSE
**	-------------
**
**
**	(?!<name>regex)
**
**		*?		for capture en memory
**		*!		for Not matching
**		<name>	for named where you capture (do nothing if ? is not set)
**
**
**	-------------
**		EXEMPLE
**	-------------
**
**	"^(?<alone>[\\p])*\\|(\\s*(?<flags>[\\p])+\\s*(\\((\\s*(?<type>[a-zA-Z*])+
**	\\s*(\\{\\s*(?<min>[\\d])*\\s*,\\s*(?<max>[\\d])*\\s*(,(?<pattern>[^}])*)?
**	\\}\\s*,\\s*)?)*\\))?\\s*;\\s*(?<set>[\\p])*\\s*;\\s*(?<unset>[\\p])*
**	\\s*\\|)*$"
**
**-------------------------------------------------------
*/

int				ft_regex_exec(t_regex *st, const char *s1, const char *reg)
{
	int i;

	ft_bzero(st, sizeof(*st));
	st->s1 = s1;
	st->len_s1 = ft_strlen(s1);
	while (*reg)
	{
		st->reg = reg;
		if (is_delimiter(st, reg, "^"))
			regex_parse(st, s1, reg + 1);
		else
		{
			i = 0;
			while (*(s1 + i))
				regex_parse(st, s1 + i++, reg);
		}
		reg += regex_span_or(st, reg);
	}
	if (st->last_error)
		st->error_pos = st->len_s1 - ft_strlen(st->last_error);
	return (st->error | st->match);
}
