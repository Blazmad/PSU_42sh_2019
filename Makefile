##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

NAME		=	42sh
TEST		=	unit_tests

CC			=	@gcc -Iinclude

SRC			=	$(wildcard $(addprefix lib/my/, *).c)
SRC			+=	$(wildcard $(addprefix src/, *).c)
OBJ			=	$(SRC:.c=.o)

SRC-CRIT	=	$(wildcard $(addprefix lib/my/, *).c)
SRC-CRIT	+=	$(filter-out src/main.c,$(wildcard $(addprefix src/, *).c))
SRC-CRIT	+=	$(wildcard $(addprefix tests/, *).c)
OBJ-CRIT	=	$(SRC-CRIT:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -fno-builtin -g
NCURSFLAGS	+=	-lncurses
CRITFLAGS	=	--coverage -lcriterion

COVERAGE	=	gcovr --exclude tests/

END		=	\033[0m
BOLD	=	\033[1m
RED		=	\033[31m
GREEN	=	\033[32m

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "$(GREEN)$(BOLD)[ COMPLETED ]$(END)"

test_run:	$(SRC-CRIT)
	@$(CC) -o $(TEST) $(SRC-CRIT) $(CRITFLAGS)
	@echo -e "$(GREEN)$(BOLD)[ UNIT_TESTS ]$(END)"
	@./$(TEST)
	@$(COVERAGE)
	@rm *.gc*

clean:
	@find . -type f \( -iname "*~" \) -delete
	@$(RM) $(OBJ)
	@$(RM) $(OBJ-CRIT)
	@echo -e "$(RED)$(BOLD)[ CLEANED ]$(END)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TEST)

re:	fclean all

.PHONY: all test_run clean fclean re