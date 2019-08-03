# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/07/15 02:18:19 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls
TYPE = "de l'executable"

LIBFT_M : 
	@make -C libft/ all
LIBFT_C : 
	@make -C libft/ clean
LIBFT_FC : 
	@make -C libft/ fclean
LIBFT_N : 
	@make -C libft/ norme
LIBFT_R : 
	@make -C libft/ re

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes -Ilibft/includes

HEADER = ft_ls.h

COMPILE = CC

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
ALL_D = $(DSRC)

DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER)) libft/includes/libft.h

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC = main.c main_ls.c main_ls2.c \
	  sort_ls.c sort_utils_ls.c padding_ls.c print_file.c \
	 stat_ls.c utils_ls.c utils_ls2.c

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

print_name : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [    FT_LS     ]             "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"

print_norme : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                 [    FT_LS NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"


all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ)
	@echo $(SPACE)"\033[JCompilation des Objects \033[38;5;326mterminer\033[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@$(COMPILE) $(COBJ) $(CFLAGS) $(INCLUDE) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@$(COMPILE) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"compilation de la fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: LIBFT_C print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

clean_f: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

fclean: LIBFT_FC clean_f
	@rm -f $(NAME)
	@echo $(SPACE)"Suppresion "$(TYPE) "\033[38;5;265m"$(NAME) "\033[0m"

re_clean:
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"
	@rm -f $(NAME)
	@echo $(SPACE)"Suppresion "$(TYPE) "\033[38;5;265m"$(NAME) "\033[0m"

re: LIBFT_R re_clean print_name $(NAME)

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

normeall : LIBFT_N norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name
