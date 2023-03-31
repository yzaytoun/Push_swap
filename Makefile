# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:16:59 by yzaytoun          #+#    #+#              #
#    Updated: 2022/11/02 21:07:52by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
PUSHBONUS := checker.a  

vpath %.c src
vpath %.h include
vpath %_bonus.c bonus
vpath %.o obj


# ************************ Colors ***********************************
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

# --------------------- Definitions ------------------------------------
CC = gcc 
AR = ar
ARFLAGS = -rcs
INC = include
CFLAGS = -Wall -Wextra -Werror -I $(INC) -g3
RM = rm -fr
SANITIAZE = -fsanitize=address -g3
# ------------------ Libft and printf ------------------------------
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
# ------------------------ Push Swap ------------------------------
SRC = pushswap_actions.c  pushswap_aux.c\
	  pushswap_operations.c pushswap_sort.c pushswap_utils.c pushswap_utils2.c\
	  pushswap_merge.c pushswap_sort_aux.c
BONUS = checker_aux_bonus.c
OBJDIR = obj

PUSH_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
PUSH_OBJB := $(BONUS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(PUSH_OBJ)
	@echo "$(YELLOW)Compiling" $@
	@$(AR) $(ARFLAGS) $@ $(PUSH_OBJ)
	@echo "$(GREEN)Done!!"
	@$(CC) $(NAME) $(LIBFT) $(PRINTF) main.c -o push_swap
	@chmod +x push_swap
	@echo "$(YELLOW)************Push Swap is ready****************\n"

$(PRINTF) $(LIBFT) &:
	@echo "$(YELLOW)Making Libft"
	@cd libft; make bonus;
	@echo "$(YELLOW)Making ft_printf"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)Finished!!!"

bonus: $(PUSHBONUS)

$(PUSHBONUS): $(LIBFT) $(PRINTF) $(PUSH_OBJ) $(PUSH_OBJB)
	@echo "$(YELLOW)Doing Bonus part....."
	@$(AR) $(ARFLAGS) $@ $(PUSH_OBJ) $(PUSH_OBJB)
	@$(CC) $@ $(LIBFT) $(PRINTF) main_bonus.c -o checker $(SANITIAZE)
	@chmod +x checker
	@echo "$(GREEN)\n************Checker DONE****************\n"


fclean: clean
	@$(RM) $(NAME) push_swap $(PUSHBONUS) checker

clean:
	@echo "$(RED)Cleaning libft and ft_printf"
	@(cd libft; make fclean)
	@(cd ft_printf; make fclean)
	@echo "Cleaning Object files"
	@$(RM) $(PUSH_OBJ) $(PUSH_OBJB) $(OBJDIR)
	@echo "Cleaning push_swap and push_swap.a"
	@echo "$(DONE)\n*****************DONE Cleaning**********************\n\n"

re: fclean all bonus

.PHONY: bonus all re fclean clean