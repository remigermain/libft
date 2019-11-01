# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 15:39:03 by rgermain          #+#    #+#              #
#    Updated: 2019/10/03 19:26:40 by rgermain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
TYPE := "library"

CFLAGS =  -Wall -Wextra -g3 -Werror

INCLUDE = -Iincludes

HEADER =	libft.h limit.h color.h  divers.h  flags.h  ft_errno.h  ft_printf.h  get_next_line.h  \
			is_methode.h math.h  memory.h  print.h  lib_lst.h strings.h bytes_tools.h regex.h


OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
ALL_D = $(D_DIVERS) $(D_IS_METHODE) $(D_MATH) $(D_MEMORY) $(D_FLAGS) $(D_LST)\
		$(D_PUT) $(D_STDIO) $(D_STRING) $(addprefix $(D_STDIO),$(D_FT_PRINTF)) \
		$(D_BYTES) $(D_REGEX)

DHEADER = includes/

SRC =  $(CSRC_DIVERS) $(CSRC_ISMETHODE) $(CSRC_MATH) $(CSRC_LST) \
	  $(CSRC_MEMORY) $(CSRC_PUT) $(CSRC_STRING) $(CSRC_STDIO) $(CSRC_FLAGS)\
	  $(CSRC_BYTES) $(CSRC_REGEX)

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER))

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

CSRC_BYTES = $(addprefix $(D_BYTES), $(SRC_BYTES))
D_BYTES = bytes_tools/
SRC_BYTES = ft_print_memory.c ft_reverse_bytes.c ft_option.c ft_create_bytes_tab.c \

CSRC_DIVERS = $(addprefix $(D_DIVERS),$(SRC_divers))
D_DIVERS = divers/
SRC_divers = 		ft_countwchar.c  ft_createtab.c  ft_inttab_del.c    ft_sort_integer_table.c  \
					ft_swap.c  ft_tablen.c  len_wchar.c  len_wchar_single.c  nlen_wchar.c  timestamp.c \
					ft_getchar.c get_next_line.c  


CSRC_FLAGS = $(addprefix $(D_FLAGS),$(SRC_flags))
D_FLAGS = flags/
SRC_flags = 	flag_base_func.c  flag_base_obj.c  flag_error.c  flag_parse.c  \
				flag_func_obj.c  flag_func_type.c  flag_init.c  flag_usage.c  \
				ft_erro_argv.c  ft_error_line.c flag_utils.c

CSRC_ISMETHODE = $(addprefix $(D_IS_METHODE),$(SRC_ISMETHODE))  
D_IS_METHODE = is_methode/
SRC_ISMETHODE =		ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isblank.c  ft_iscntrl.c  ft_isdigit.c  ft_isgraph.c  \
					ft_islowercase.c  ft_isprint.c  ft_isspace.c  ft_isuppercase.c  ft_isxdigit.c  ft_tolower.c  ft_toupper.c ft_isword.c

CSRC_LST = $(addprefix $(D_LST),$(SRC_LST))
D_LST = libft_list/
SRC_LST	=			ft_lstadd.c    ft_lstdel.c    ft_lstdelone.c ft_lstiter.c   ft_lstmap.c    ft_lstnew.c


CSRC_MATH = $(addprefix $(D_MATH),$(SRC_MATH))
D_MATH = math/
SRC_MATH = 			ft_find_next_prime.c  ft_intlen_base.c  ft_intlen.c  ft_is_prime.c  ft_iterative_factorial.c  \
					ft_iterative_power.c  ft_recursive_factorial.c  ft_recursive_power.c  ft_sqrt.c ft_pow.c


CSRC_MEMORY = $(addprefix $(D_MEMORY),$(SRC_MEMORY))
D_MEMORY = memory/
SRC_MEMORY = 		ft_bzero.c  ft_memalloc.c  ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memdel.c  \
					ft_memmove.c  ft_memnew.c  ft_memset.c  ft_realloc.c


CSRC_PUT = $(addprefix $(D_PUT),$(SRC_PUT))
D_PUT = print/
SRC_PUT = 			ft_printtab.c     ft_putchar.c     ft_putendl.c     ft_putnbr_base.c     ft_putnbr.c    \
					ft_putnstr.c     ft_putnstrw.c     ft_putpchar_fd.c  ft_putpstr_fd.c  ft_putstr_fd.c  ft_putstrw_fd.c  \
					ft_putwchar_fd.c ft_printtab_fd.c  ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_base_fd.c  \
					ft_putnbr_fd.c  ft_putnstr_fd.c  ft_putnstrw_fd.c  ft_putpnstr_fd.c  ft_putstr.c      ft_putstrw.c    ft_putwchar.c \

CSRC_STDIO = $(addprefix $(D_STDIO),$(SRC_STDIO))
D_STDIO = stdio/
SRC_STDIO = $(CSRC_PRINTF)

CSRC_REGEX = $(addprefix $(D_REGEX), $(SRC_REGEX))
D_REGEX = regex/
SRC_REGEX =	regex_utils.c regex_exec.c regex_meta.c regex_meta_type.c \
			regex_class.c regex_quantifier.c regex_quantifier_get.c regex_enclosed.c \
			regex_span.c regex_replace.c regex_capt.c \

CSRC_PRINTF = $(addprefix $(D_FT_PRINTF),$(SRC_PRINTF))
D_FT_PRINTF = ft_printf/
SRC_PRINTF =		ft_printf.c ft_printf_base.c get_options.c put_string.c utils.c\
					conv_string.c conv_tabstring.c conv_other.c conv_char.c conv_int.c \
					st_putdouble.c conv_double.c

CSRC_STRING = $(addprefix $(D_STRING),$(SRC_STRINGS))
D_STRING = string/
SRC_STRINGS =		ft_atof.c       ft_atol.c  ft_str_is_type.c ft_strclr.c     ft_strdel.c   \
					ft_str_is_alpha.c      ft_str_is_uppercase.c  ft_strlcat.c     ft_strmap.c   ft_strncpy.c     ft_strnlen.c  \
					ft_strsplit.c  ft_strtrim.c ft_atoi_base.c  ft_itoabase_buffer.c  ft_itoa.c        ft_strcapitalize.c  ft_strcmp.c     ft_strdup.c    \
					ft_str_is_lowercase.c  ft_striter.c           ft_strlcpy.c     ft_strmapi.c  ft_strncpychr.c  ft_strnstr.c \
					 ft_strstr.c    ft_strupcase.c ft_atoi.c       ft_itoa_base.c        ft_spantype.c        ft_strcat.c         \
					 ft_strcpy.c     ft_strequ.c    ft_str_is_numeric.c    ft_striteri.c          ft_strlen.c      ft_strncat.c  \
					 ft_strnequ.c     ft_strpbrk.c  ft_strsub.c    ft_strxfrm.c  ft_atol_base.c  ft_itoa_buffer.c      ft_span.c    \
					 ft_strchr.c         ft_strcpychr.c  ft_strerror.c  ft_str_is_printable.c  ft_strjoin.c    ft_strlowcase.c  \
					 ft_strncmp.c  ft_strnew.c      ft_strrev.c   ft_strtok.c    ft_tabdel.c ft_base_string.c ft_atof_base.c 


NUMBER_FUNCTION := "$(shell  ls -R1 $(DSRC) | grep . | grep "\.c" | wc -l)"
NUMBER := "0"
PROGRESS := "1"
DIFF := "1"
MAX_PROGRESS = "50"
COLOR_PROGRESS = "0"
COUNT := "TRUE"
NULL := 
ESC := $(shell printf '\033')
SPACE := "                       "
.DEFAULT_GOAL := all

#### COLOR
RED := $(ESC)[1;31m
BLUE := $(ESC)[1;34m
LIGHT_BLUE := $(ESC)[34m
GREEN := $(ESC)[1;32m
WHITE := $(ESC)[0m
WHITE := $(ESC)[0m
####

#Inside actions we can use:  
#    $@ to represent the full target name of the current target  
#    $? returns the dependencies that are newer than the current target  
#    $* returns the text that corresponds to % in the target     
#    $< returns the name of the first dependency 
#    $^ returns the names of all the dependencies with space as the delimiter

print_name : 
	@printf "$(BLUE)\n  		██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓ \n"
	@printf "$(BLUE)		▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒ \n"
	@printf "$(BLUE)		▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░\n"
	@printf "$(WHITE)		▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░ \n"
	@printf "$(WHITE)		░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░ \n"
	@printf "$(WHITE)		░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░   \n"
	@printf "$(WHITE)		░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░    \n"
	@printf "$(RED)		  ░ ░    ▒ ░ ░    ░  ░ ░      ░      \n"
	@printf "$(RED)		    ░  ░ ░   ░                       \n"
	@printf "$(RED)		                  ░                  \n\n\n"
	@printf "$(WHITE)		https://framagit.org/rgermain/libft\n"
	@printf "				by\n"
	@printf "			      rgermain\n\n"
	@printf "$(BLUE)		░ ░ ▒  ░ ▒ ░▒░▒  ░ ░ ▒  ░ ▒ ░▒░▒    \n\n$(WHITE)"

print_norme : print_name
	@printf "			    Norminette    \n\n"
	@printf "$(BLUE)		░ ░ ▒  ░ ▒ ░▒░▒  ░ ░ ▒  ░ ▒ ░▒░▒    \n\n$(WHITE)"


all: print_name $(NAME)
	@if [ $(COUNT) = "TRUE" ]; then \
		printf $(SPACE)"$(BLUE) Nothing are changed !$(WHITE)\n"; \
	fi

$(NAME): $(COBJ)
	@printf $(SPACE)"Compilation of objects $(GREEN)finish$(WHITE)"$(SPACE)$(SPACE)"\n"
	@printf $(SPACE)"Compilation $(TYPE) $(BLUE) $(NAME) $(WHITE)"$(SPACE)$(SPACE)"\n"
	@ar ru $(NAME) $? > /dev/null 2>&1
	@printf $(SPACE)"Opimisation library with $(BLUE)ranlib$(WHITE)"$(SPACE)$(SPACE)"\n\n"
	@ranlib $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
	@$(eval COUNT = "FALSE")
	@printf "$(eval NUMBER=$(shell echo $(NUMBER) + 1 | bc ))"
	@printf "$(eval PROGRESS=$(shell echo $(NUMBER) \* $(MAX_PROGRESS) / $(NUMBER_FUNCTION) | bc ))"
	@printf "$(eval DIFF=$(shell echo $(MAX_PROGRESS) - $(PROGRESS) | bc ))"
	@printf "$(eval COLOR_PROGRESS=$(shell echo $(PROGRESS) % 7 + 31 | bc))"
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(ESC)[$(COLOR_PROGRESS)m       ["
	@printf "%0.s=" {0..$(PROGRESS)}
	@printf ">"
	@printf "%0.s " {0..$(DIFF)}
	@printf "]$(WHITE)\n"
	@printf $(SPACE)"Compilation $(GREEN)$(NUMBER)$(WHITE) of $(BLUE)$(NUMBER_FUNCTION)$(WHITE)"$(SPACE)"\n"
	@printf $(SPACE)"Compilation of function $(GREEN)$<$(WHITE)"$(SPACE)$(SPACE)"\n$(ESC)[3A"

clean: print_name
	@rm -rf $(DOBJ)
	@printf $(SPACE)"Remove $(RED) objects $(WHITE)\n\n"

fclean: print_name
	@rm -rf $(DOBJ)
	@rm -f $(NAME)
	@printf $(SPACE)"Remove $(RED) objects $(WHITE)\n"
	@printf $(SPACE)"Remove $(TYPE) $(RED)$(NAME)$(WHITE)\n\n"

re: fclean all

prototype:
	@printf "$(shell cat $(PATH) | grep '^[a-zA-Z_]*\s*[a-zA-Z]\+[[:space:]]\+[*]*[a-zA-Z][a-zA-Z0-9_]\+(.*)[[:space:]]*' | grep -v '^static')"

info: print_name
	@printf $(SPACE)"Total functions : $(BLUE)"
	@printf "$(NUMBER_FUNCTION)$(WHITE)\n";
	@printf $(SPACE)"Total lines : $(BLUE)"
	@printf "$(shell cat $(CSRC) $(CHEADER) | sed '/^\*\*.*/d' | sed '/^\/\*.*/d' | sed '/^\*\/.*/d' | sed '/^[[:blank:]]*\/\/.*/d' | grep . | wc -l)"
	@printf "$(WHITE)\n";
	@printf $(SPACE)"Total commit : $(BLUE)"
	@git rev-list --all --count
	@printf "$(WHITE)\n";
	@printf $(SPACE)"Last modifications : $(BLUE)"
	@git log| head -n5 | grep Date | cut -c 9-
	@printf "$(WHITE)\n";

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&$(WHITE)," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&$(WHITE),"

.PHONY: default all clean fclean re norme print_libft print_norme info prototype diff
